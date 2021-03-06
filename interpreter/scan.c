/*----------------------------------------------------------------------

  scan.c

  Player command line scanne unit for Alan interpreter ARUN

  ----------------------------------------------------------------------*/

#include "scan.h"


/* IMPORTS */
#include "lists.h"
#include "dictionary.h"
#include "output.h"
#include "memory.h"
#include "params.h"
#include "term.h"
#include "options.h"
#include "exe.h"
#include "word.h"
#include "literal.h"
#include "debug.h"
#include "msg.h"
#include "inter.h"

#ifdef USE_READLINE
#include "readline.h"
#endif



/* PRIVATE CONSTANTS */


/* PUBLIC DATA */
bool continued = FALSE;


/* PRIVATE DATA */
static char buf[1000]; /* The input buffer */
static char isobuf[1000]; /* The input buffer in ISO */
static bool eol = TRUE; /* Looking at End of line? Yes, initially */
static char *token = NULL;


/*======================================================================*/
void forceNewPlayerInput() {
    setEndOfArray(&playerWords[currentWordIndex]);
}


/*----------------------------------------------------------------------*/
static void unknown(char token[]) {
    char *str = strdup(token);
    Parameter *messageParameters = newParameterArray();

#if ISO == 0
    fromIso(str, str);
#endif
    addParameterForString(messageParameters, str);
    printMessageWithParameters(M_UNKNOWN_WORD, messageParameters);
    deallocate(messageParameters);
    free(str);
    abortPlayerCommand();
}


/*----------------------------------------------------------------------*/
static int number(char token[]) {
    int i;

    sscanf(token, "%d", &i);
    return i;
}


/*----------------------------------------------------------------------*/
static int lookup(char wrd[]) {
    int i;

    // TODO: Why do we start at 0, is there a word code == 0?
    for (i = 0; !isEndOfArray(&dictionary[i]); i++) {
        if (compareStrings(wrd, (char *) pointerTo(dictionary[i].string)) == 0) {
            return i;
        }
    }
    return EOF;
}


/*----------------------------------------------------------------------*/
static bool isWordCharacter(int ch) {
    return isISOLetter(ch) || isdigit(ch) || ch == '\'' || ch == '-' || ch == '_';
}

/*----------------------------------------------------------------------*/
static void readWord(char **markerp) {
    while (**markerp && isWordCharacter(**markerp))
        (*markerp)++;
}

/*----------------------------------------------------------------------*/
static void readNumber(char **markerp) {
    while (isdigit((int)**markerp))
        (*markerp)++;
}

/*----------------------------------------------------------------------*/
static void readString(char **markerp) {
    (*markerp)++;
    while (**markerp != '\"')
        (*markerp)++;
    (*markerp)++;
}


/*----------------------------------------------------------------------*/
static char *gettoken(char *buf) {
    static char *marker;
    static char oldch;

    if (buf == NULL)
        *marker = oldch;
    else
        marker = buf;
    while (*marker != '\0' && isSpace(*marker) && *marker != '\n')
        marker++;
    buf = marker;
    if (isISOLetter(*marker))
        readWord(&marker);
    else if (isdigit((int)*marker))
        readNumber(&marker);
    else if (*marker == '\"') {
        readString(&marker);
    } else if (*marker == '\0' || *marker == '\n' || *marker == ';')
        // End of input, either actually or by a comment start
        return NULL;
    else
        marker++;
    oldch = *marker;
    *marker = '\0';
    return buf;
}


/*----------------------------------------------------------------------*/
// TODO replace dependency to exe.c with injection of quitGame() and undo()
static void getLine(void) {
    para();
    do {
        statusline();
        if (header->prompt) {
            anyOutput = FALSE;
            interpret(header->prompt);
            if (anyOutput)
                printAndLog(" ");
            needSpace = FALSE;
        } else
            printAndLog("> ");

#ifdef USE_READLINE
        if (!readline(buf))
#else
        fflush(stdout);
        if (fgets(buf, LISTLEN, stdin) == NULL)
#endif
        {
            newline();
            quitGame();
        }

        getPageSize();
        anyOutput = FALSE;
        if (transcriptOption || logOption) {
            // TODO Refactor out the logging to log.c?
#ifdef HAVE_GLK
            glk_put_string_stream(logFile, buf);
            glk_put_char_stream(logFile, '\n');
#else
            fprintf(logFile, "%s\n", buf);
#endif
        }
        /* If the player input an empty command he forfeited his command */
        if (strlen(buf) == 0) {
            clearWordList(playerWords);
            longjmp(forfeitLabel, 0);
        }

#if ISO == 0
        toIso(isobuf, buf, NATIVECHARSET);
#else
        strcpy(isobuf, buf);
#endif
        token = gettoken(isobuf);
        if (token != NULL) {
            if (strcmp("debug", token) == 0 && header->debug) {
                debugOption = TRUE;
                debug(FALSE, 0, 0);
                token = NULL;
            } else if (strcmp("undo", token) == 0) {
                token = gettoken(NULL);
                if (token != NULL) /* More tokens? */
                    error(M_WHAT);
                undo();
            }
        }
    } while (token == NULL);
    eol = FALSE;
}


/*----------------------------------------------------------------------*/
static int try_elision(char *apostrophe, int *_i) {
    int i = *_i, w;
    // Handle elisions (contractions) with apostrophe,
    // e.g. Italian "l'acqua", and split that into two
    // words

    // First cut after the apostrophe
    int previous_char = apostrophe[1];
    apostrophe[1] = '\0';

    // Now try that word
    w = lookup(token);
    apostrophe[1] = previous_char;
    if (w == EOF) {
        // No cigar, so give up
        unknown(token);
    }

    // We found a word, save it
    if (!isNoise(w))
        playerWords[i++].code = w;
    // Then restore and point to next part
    token = &apostrophe[1];
    w = lookup(token);
    if (w == EOF) {
        // No cigar, so give up
        unknown(token);
    }

    // Prepare to store this word
    ensureSpaceForPlayerWords(i+1);
    playerWords[i].start = token;
    playerWords[i].end = strchr(token, '\0');

    *_i = i;
    return w;
}


/*----------------------------------------------------------------------*/
static int handle_literal(int i) {
    if (isdigit((int)token[0])) {
        createIntegerLiteral(number(token));
    } else {
        char *unquotedString = strdup(token);
        unquotedString[strlen(token) - 1] = '\0';
        createStringLiteral(&unquotedString[1]);
        free(unquotedString);
    }
    playerWords[i++].code = dictionarySize + litCount; /* Word outside dictionary = literal */
    return i;
}


/*----------------------------------------------------------------------*/
static int handle_word(int i) {
    int w = lookup(token);
    if (w == EOF) {
        char *apostrophe = strchr(token, '\'');
        if (apostrophe == NULL) {
            unknown(token);
        } else {
            w = try_elision(apostrophe, &i);
        }
    }
    if (!isNoise(w))
        playerWords[i++].code = w;
    return(i);
}


/*======================================================================*/
void scan(void) {
    int i;

    if (continued) {
        /* Player used '.' to separate commands. Read next */
        para();
        token = gettoken(NULL);
        if (token == NULL) /* Or did he just finish the command with a full stop? */
            getLine();
        continued = FALSE;
    } else
        getLine();

    freeLiterals();
    playerWords[0].code = 0; // TODO This means what?
    i = 0;
    do {
        ensureSpaceForPlayerWords(i+1);
        playerWords[i].start = token;
        playerWords[i].end = strchr(token, '\0');

        if (isISOLetter(token[0])) {
            i = handle_word(i);
        } else if (isdigit((int)token[0]) || token[0] == '\"') {
            i = handle_literal(i);
        } else if (token[0] == ',') {
            playerWords[i++].code = conjWord;
        } else if (token[0] == '.') {
            continued = TRUE;
            setEndOfArray(&playerWords[i]);
            eol = TRUE;
            break;
        } else
            unknown(token);
        setEndOfArray(&playerWords[i]);
        eol = (token = gettoken(NULL)) == NULL;
    } while (!eol);
}
