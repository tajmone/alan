#ifndef _GLKIO_H_
#define _GLKIO_H_

/*----------------------------------------------------------------------*\

  glkio.c

  Header file for Glk output for Alan interpreter

\*----------------------------------------------------------------------*/

#include "glk.h"

winid_t glkMainWin;
winid_t glkStatusWin;

/* NB: this header must be included in any file which calls printf() */

#define printf glkio_printf
void glkio_printf(char *, ...);

#define fgetc(stream) glk_get_char_stream(stream)
#define fwrite(buf, elementSize, count, stream) glk_put_buffer_stream(stream, buf, elementSize*count);
#define fread(buf, elementSize, count, stream) glk_get_buffer_stream(stream, buf, elementSize*count);
#define fclose(stream) glk_stream_close(stream, NULL)

#endif
