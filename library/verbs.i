-- ALAN Standard Library v0.95
-- Verbs (file name: 'verbs.i')


----- This library file defines common verbs needed in gameplay. The verbs
----- are listed alphabetically. This file also includes common commands which are not
----- actually verbs, such as "inventory", "verbose" and "again". You are free to edit this
----- file for your own purposes in any way you like by adding, deleting or modifying verbs. 
----- Verbs originally defined in this file are the following:


----- VERB        SYNONYMS                                        SYNTAX                              ARITY             OBJ
		
----- about       (+ help, info)                                  about                               0
----- again       (+ g)                                           again                               0
----- answer      (+ reply)                                       answer (topic)                      1
----- ask         (+ enquire, inquire, interrogate)               ask (act) about (topic)             2
----- ask for                                                     ask (act) for (obj)                 2                 x
----- attack      (+ beat, fight, hit, punch)                     attack (target)                     1
----- attack_with                                                 attack (target) with (weapon)       2
----- bite        (+ chew)                                        bite (obj)                          1                 x
----- break       (+ destroy)                                     break (obj)                         1			x 
----- break_with                                                  break (obj) with (instr)            2                 x 
----- brief                                                       brief                               0
----- burn                                                        burn (obj)                          1                 x
----- burn_with                                                   burn (obj) with (instr)             2                 x 
----- buy         (+ purchase)                                    buy (item)                          1			
----- catch                                                       catch (obj)                         1                 x	
----- clean       (+ polish, wipe)                                clean (obj)                         1                 x 
----- climb                                                       climb (obj)                         1                 x 
----- climb_on                                                    climb on (surface)                  1						
----- climb_through                                               climb through (obj)                 1                 x
----- close       (+ shut)                                        close (obj)                         1                 x
----- close_with                                                  close (obj) with (instr)            2                 x
----- consult                                                     consult (source) about (topic)      2			
----- credits     (+ acknowledgments, author, copyright)          credits                             2 					
----- cut                                                         cut (obj)                           1                 x
----- cut_with                                                    cut (obj) with (instr)              2                 x 
----- dance                                                       dance                               0
----- dig                                                         dig (obj)                           1                 x
----- dive                                                        dive                                0
----- dive_in                                                     dive in (liq)                       1
----- drink                                                       drink (liq)                         1
----- drive                                                       drive (vehicle)                     1
----- drop        (+ discard, dump, reject)                       drop (obj)                          1                 x
----- eat                                                         eat (food)                          1		
----- empty                                                       empty (obj)                         1                 x
----- empty_in                                                    empty (obj) in (cont)               2                 x
----- empty_on                                                    empty (obj) in (cont)               2                 x
----- enter                                                       enter (cont)                        1
----- examine     (+ check, inspect, observe, x)                  examine (obj)                       1                 x
----- exit                                                        exit (cont)                         1
----- extinguish  (+ put out, quench)                             extinguish (obj)                    1                 x 
----- fill                                                        fill (cont)                         1			
----- fill_with                                                   fill (cont) with (substance)        1			
----- find        (+ locate)                                      find (obj)                          1                 x
----- fire                                                        fire (weapon)                       1			
----- flip                                                        flip (obj)                          1                 x 
----- follow                                                      follow (act)                        1			
----- free        (+ release)                                     free (obj)                          1                 x
----- get_up                                                      get up                              0					
----- get_off                                                     get off (obj)                       1                 x
----- give                                                        give (obj) to (recip)               1                 x
----- go_to                                                       go to (dest)                        1			
----- hint        (+ hints)                                       hint                                0
----- inventory   (+ i, inv)                                      inventory                           0
----- jump                                                        jump                                0
----- jump_in                                                     jump in (cont)                      1			
----- jump_on                                                     jump on (surface)                   1 			
----- kick                                                        kick (target)                       1
----- kill        (+ murder)                                      kill (victim)                       1			
----- kill_with                                                   kill (victim) with (weapon)         2			
----- kiss        (+ hug, embrace)                                kiss (obj)                          1                 x
----- lie_down                                                    lie down                            0
----- lie_in                                                      lie in (cont)                       1     
----- lie_on                                                      lie on (surface)                    1
----- lift                                                        lift (obj)                          1                 x
----- light       (+ lit)                                         light (obj)                         1                 x
----- listen0                                                     listen                              0
----- listen                                                      listen to (obj)                     1                 x
----- lock                                                        lock (obj)                          1                 x
----- lock_with                                                   lock (obj) with (instr)             2                 x	
----- look        (+ gaze, peek)                                  look                                0						
----- look_at                                                     look at (obj)                       1                 x
----- look_behind                                                 look behind (bulk)                  1			
----- look_in                                                     look in (cont)                      1			
----- look_out_of                                                 look out of (obj)                   1                 x				
----- look_through                                                look through (bulk)                 1  		
----- look_under                                                  look under (bulk)                   1 			
----- look_up                                                     look up                             0
----- no                                                          no                                  0						
----- notify (on, off)                                            notify. notify on. notify off       0
----- open                                                        open (obj)                          1                 x
----- open_with                                                   open (obj) with (instr)             2                 x	
----- play                                                        play (obj)                          1                 x
----- play_with                                                   play with (obj)                     1                 x
----- pour        (= defined at the verb 'empty)                  pour (obj)                          1                 x
----- pour_in     (= defined at the verb 'emtpy_in')              pour (obj) in (cont)                1                 x  
----- pour_on     (= defined at the verb 'empty_on')              pour (obj) on (surface)             1                 x
----- pray                                                        pray                                0
----- pry                                                         pry (obj)                           1                 x
----- pry_with                                                    pry (obj) with (instr)              2                 x
----- pull                                                        pull (obj)                          1                 x
----- push                                                        push (obj)                          1                 x
----- push_with                                                   push (obj) with (instr)             1                 x	
----- put         (+ lay, place)                                  put (obj)                           1                 x
----- put_behind                                                  put (obj) behind (bulk)             1                 x			
----- put_down                                                    put down (obj)                      1                 x
----- put_in      (+ insert)                                      put (obj) in (cont)                 2                 x
----- put_near                                                    put (obj) near (bulk)               2                 x
----- put_on                                                      put (obj) on (surface)              2                 x
----- put_under                                                   put (obj) under (bulk)              2                 x 
----- read                                                        read (obj)                          1                 x
----- restart                                                     restart                             0					
----- restore                                                     restore                             0		
----- rub                                                         rub (obj)                           1                 x
----- save                                                        save                                0
----- say                                                         say (topic)                         1  
----- say_to                                                      say (topic) to (act)                1
----- score                                                       score                               0 
----- scratch                                                     scratch (obj)                       1                 x
----- script                                                      script. script on. script off.      0
----- search                                                      search (obj)                        1                 x
----- sell                                                        sell (item)                         1 
----- shake                                                       shake (obj)                         1                 x
----- shoot (at)                                                  shoot (at) (target)                 1
----- shoot_with                                                  shoot (target) with (weapon)        2			
----- shout       (+ scream, yell)                                shout                               0 
----- show        (+ reveal)                                      show (obj) to (act)                 1                 x
----- sing                                                        sing                                0						
----- sip                                                         sip (liq)                           1
----- sit (down)                                                  sit.  sit down.                     0
----- sit_on                                                      sit on (surface)                    1
----- sleep       (+ rest)                                        sleep                               0
----- smell0                                                      smell                               0
----- smell                                                       smell (odour)                       1
----- squeeze                                                     squeeze (obj)                       1                 x
----- stand (up)                                                  stand.  stand up.                   0
----- stand_on                                                    stand on (surface)                  1
----- swim                                                        swim                                0
----- swim_in                                                     swim in (liq)                       1
----- switch_on                                                   switch on (app)                     1
----- switch_off                                                  switch off (app)                    1
----- take        (+ carry, get, grab, hold, obtain)              take (obj)                          1                 x
----- take_from   (+ remove from)                                 take (obj) from (holder)            2                 x
----- talk                                                        talk                                0						
----- talk_to     (+ speak)                                       talk to (act)                       1
----- taste       (+ lick)                                        taste (obj)                         1                 x
----- tear        (+ rip)                                         tear (obj)                          1                 x
----- tell        (+ enlighten, inform)                           tell (act) about (topic)            2	
----- think                                                       think                               0
----- think_about                                                 think about (topic)                 1
----- throw                                                       throw (projectile)                  1
----- throw_at                                                    throw (projectile) at (target)      2	
----- throw_in                                                    throw (projectile) in (cont)        2
----- throw_to                                                    throw (projectile) to (recipient)   2 
----- tie                                                         tie (obj)                           1                 x
----- tie_to                                                      tie (obj) to (target)               2                 x
----- touch       (+ feel)                                        touch (obj)                         1                 x			
----- turn        (+ rotate)                                      turn (obj)                          1                 x 
----- turn_on                                                     turn on (app)                       1                 
----- turn_off                                                    turn off (app)                      1
----- unlock                                                      unlock (obj)                        1                 x
----- unlock_with                                                 unlock (obj) with (key)             2                 x	
----- use                                                         use (obj)                           1                 x 
----- use_with                                                    use (obj) with (instr)              2                 x
----- verbose                                                     verbose                             0
----- wait        (+ z)                                           wait                                0
----- what_am_i                                                   what am i                           0
----- what_is                                                     what is (obj)                       1                 x	
----- where_am_i                                                  where am i                          0
----- where_is                                                    where is (obj)                      1                 x
----- who_am_i                                                    who am i                            0
----- who_is                                                      who is (obj)                        1                 x 
----- write                                                       write (txt) on (obj)                2                 x 
----- yes                                                         yes                                 0



----- Verbs having to do with wearing clothes are defined in the file 'classes.i', 
----- subclass 'clothing'. These verbs are:
-----
----- remove      (+ doff, take off)                              remove (clothing)                   1
----- undress                                                     undress                             0
----- wear        (+ don, put on)                                 wear (clothing)                     1


----- Directions (north, south, up, etc.) are declared in the file 'locations.i'.



----- We first declare some default attributes for things (= objects and actors) below.
----- These attributes are frequently checked in verb definitions to prohibit
----- the use of verbs with objects and actors in an irrational way. For example, the hero
----- won't be able to eat anything that is not edible, and so forth.


----- Specific class attributes that override or complete the following 
----- attributes are declared in the files 'classes.i' and 'locations.i'.



ADD TO EVERY THING

	IS examinable. 
	   inanimate.
	   movable.  
	   reachable. 	
	   takeable.

	HAS text "".	

	NOT broken.
	NOT closeable.
	NOT closed.
	NOT drinkable. 
	NOT edible.
	NOT lit.
	NOT lockable.
	NOT locked.
	NOT readable.   
	NOT wearable.
	NOT writeable.

	CAN NOT talk.		-- Since Alan3 alpha8, CAN is accepted as an attribute header word.
					-- 'Talk' here doesn't refer to the verb 'talk'; it just means that an actor is 
					-- (or is not) able to talk. This is to make the code more readable.
					-- (Cf. 'HAS can_talk', which was the formulation earlier.)
END ADD TO.




-- We still define that plural nouns are preceded by "some" (and not "a" or "an"):


ADD TO EVERY THING
	INDEFINITE ARTICLE
		IF THIS IS plural
			THEN "some"
			ELSE "a"
		END IF.
END ADD TO.	

-- If you need "an", you should declare it separately at the instance, e.g.:

-- THE owl ISA ACTOR
--  	AT woods
--  	INDEFINITE ARTICLE "an"
-- END THE.



-- (We add the 'plural' attribute to the 'entity' class, because the plural 
-- applies not only to things but also to e.g. parameters in syntax statements; ignore.)


ADD TO EVERY ENTITY
	IS NOT plural.
END ADD TO.



-- (Other article and pronoun definitions are in the file 'classes.i'.)



----- Next, we declare synonyms for some words so that it will be possible
----- for the player to type commands such as both "put ball in box" and 
----- "put ball into box", etc:



SYNONYMS 

into, inside = 'in'.
onto = on.
thru = through.
using = 'with'.



----- The verbs and commands:



-- =============================================================


----- ABOUT 
 

-- =============================================================


SYNTAX 'about' = 'about'.
	 

VERB 'about'
	DOES 
		STYLE emphasized.
		"This is a text adventure, also called interactive fiction, which means that what
		goes on in the story depends on what you type at the prompt. Commands you can type 
		are for example GO NORTH (or NORTH or just N), WEST, SOUTHEAST, UP, IN etc for 
		moving around, but you can try many
	      other things too, like TAKE LAMP, DROP EVERYTHING, EAT APPLE, EXAMINE BIRD or
		FOLLOW OLD MAN, to name just a few. LOOK (L) describes your surroundings, and 
		INVENTORY (I) lists what you are carrying. You can SAVE your game and RESTORE it 
		later on. 
		$pType CREDITS to see information about the author and the copyright issues.
		$pTo stop playing and end the program, type QUIT.$p"
		STYLE normal.
END VERB.


SYNONYMS help, info = 'about'.



-- =============================================================


----- AGAIN (= g)


-- =============================================================


SYNTAX again = again.


VERB again
	DOES
		"[The AGAIN command is not supported in this game. As a workaround, try using
		 the 'up' and 'down' arrow keys to scroll through your previous commands.]" 
END VERB.


SYNONYMS g = again.



-- =============================================================


----- ANSWER   	(+ reply)


-- =============================================================


SYNTAX answer = answer (topic)
	WHERE topic ISA STRING
		ELSE "That's not something you can answer."


ADD TO EVERY STRING
   VERB answer
	DOES 
		IF COUNT ISA ACTOR, AT hero < 1
			THEN "There is no-one here to hear you talk."
			ELSE "There is no reaction."
		END IF.
   END VERB.
END ADD TO.



-- =============================================================


----- ASK (= enquire, inquire, interrogate)


-- =============================================================


SYNTAX ask = ask (act) about (topic)!
    		WHERE act ISA ACTOR
      		ELSE 
				IF act IS NOT plural
					THEN "That's not"
					ELSE "Those are not"
				END IF.
				 "something you can talk to."
    		AND topic ISA THING
      		ELSE "That doesn't seem to be something you can talk about with" SAY THE act. "."

	 
	 ask = enquire (act) about (topic)!.

	 ask = inquire (act) about (topic)!.

	 ask = interrogate (act) about (topic)!.

	-- Above, we define the alternative verbs in the syntax rather than as synonyms,
      -- as the verb 'ask_for' below doesn't sound correct with these alternatives allowed.	


ADD TO EVERY ACTOR
  VERB ask
    WHEN act
      CHECK act CAN talk
        	ELSE 
			IF act IS NOT plural
					THEN "That's not"
					ELSE "Those are not"
				END IF.
				"something you can talk to."
	AND act <> hero
		ELSE "It doesn't make much sense to ask yourself about something."
	AND act IS reachable			-- you might want to remove this check in some situations, e.g.
							-- when an NPC (= a non-player character) is speaking 
							-- on the phone with the hero
		ELSE SAY THE act.
			IF act IS NOT plural
				THEN "is"
				ELSE "are"
			END IF. 
			"too far away for you to talk to."
      DOES
		IF topic IN act
			THEN SAY THE act. 
				IF act IS NOT plural
					THEN "doesn't"
					ELSE "don't"
				END IF.
				"seem to want to talk about" SAY THE topic. "."
	      ELSIF topic = act
			THEN SAY THE act. 
				IF act IS NOT plural
					THEN "chooses"
					ELSE "choose" 
				END IF.
				"to be silent."
		ELSIF topic = hero
			THEN """I think you know more about yourself than what I do!""," SAY THE act. 
				IF act IS NOT plural
					THEN "remarks."
					ELSE "remark."
				END IF.
		ELSE """I don't know anything about" SAY THE topic. "$$!""," SAY THE act. 
				IF act IS NOT plural
					THEN "remarks."
					ELSE "remark."
				END IF.
		END IF.
  END VERB.
END ADD TO.




----- note that 'consult' is defined separately



-- =============================================================


----- ASK FOR


-- =============================================================


SYNTAX ask_for = ask (act) 'for' (obj)
	WHERE act ISA ACTOR
		ELSE 
			IF act IS NOT plural
				THEN "That's not"
				ELSE "Those are not"
			END IF.
			"something you can ask for things."
	AND obj ISA OBJECT
		ELSE 
			IF obj IS NOT plural
					THEN "That's not"
					ELSE "Those are not"
				END IF.
			"something you can ask for."


ADD TO EVERY ACTOR
VERB ask_for
   WHEN act
      CHECK act CAN talk
        	ELSE 
			IF act IS NOT plural
				THEN "That's not"
				ELSE "Those are not"
			END IF. 
			"something you can talk to."
	AND act <> hero
		ELSE "It doesn't make much sense to ask yourself for something."
	AND act IS reachable			-- you might want to remove this check in some situations, e.g.
							-- when an NPC (= a non-player character) is speaking 
							-- on the phone with the hero
		ELSE SAY THE act. 
			IF act IS NOT plural
				THEN "is"
				ELSE "are"
			END IF.
			"too far away for you to talk to."
	AND obj IS takeable
		ELSE SAY THE obj.
			IF obj IS NOT plural
				THEN "is"
				ELSE "are"
			END IF.
			"not something that" SAY THE act. "could give to you."
	AND obj IS reachable
		ELSE SAY THE act. "can't reach" SAY THE obj. "."
	AND obj NOT IN hero
		ELSE "Why ask for something you already have?"
	DOES 
		SAY THE act. 
			IF act IS NOT plural
				THEN "gives you" 
				ELSE "give you"
			END IF.
		SAY THE obj. "."
		LOCATE obj IN hero.
END VERB.
END ADD TO.


--- another 'ask_for' formulation added to guide players to use the right phrasing:


SYNTAX ask_for_error = ask 'for' (obj)
	WHERE obj ISA OBJECT
		ELSE "Please use the formulation ASK PERSON FOR THING to ask somebody for
           something."


ADD TO EVERY OBJECT
VERB ask_for_error
	DOES "Please use the formulation ASK PERSON FOR THING to ask somebody for
           something."
END VERB.
END ADD TO.
 


-- =============================================================


----- ATTACK (+ beat, fight, hit, punch)


-- =============================================================


SYNTAX attack = attack (target)
    		WHERE target ISA THING
      		ELSE "That�s not something you can $v."


ADD TO EVERY THING
  VERB attack
	CHECK target IS examinable
		ELSE 
			IF target IS NOT plural
				THEN "That's not"
				ELSE "Those are not"
			END IF.
			"something you can $v."
	AND target <> hero 
		ELSE "It doesn't make sense to $v yourself."
	AND target NOT IN hero
		ELSE "It doesn't make much sense to $v something you're holding."
	AND target NOT IN worn
		ELSE "It doesn't make sense to $v something you're wearing."
	AND CURRENT LOCATION IS lit
		ELSE "It is too dark to see."
	AND target IS reachable
		ELSE SAY THE target. 
			IF target IS NOT plural
				THEN "is"
				ELSE "are"
			END IF. 
			"too far away."
	AND hero IS NOT sitting
		ELSE "It is difficult to attack anything while sitting down."
	AND hero IS NOT lying_down
		ELSE "It is difficult to attack anything while lying down."
    	DOES "Resorting to brute force is not the solution here."
  END VERB.
END ADD TO.


SYNONYMS beat, fight, hit, punch = attack.
 
-- Note that 'kick' is defined separately, to avoid absurd commands such as
-- 'kick man with sword' (see 'attack_with' below)



-- ==============================================================


----- ATTACK WITH


-- ==============================================================


SYNTAX attack_with = attack (target) 'with' (weapon)
    		WHERE target ISA THING
      		ELSE "That's not something you can $v."
    		AND weapon ISA WEAPON
     			ELSE 
				IF weapon ISA ACTOR
		 			THEN 
						IF weapon = hero
							THEN "It doesn't make sense to attack something with yourself."
							ELSE "You cannot use" SAY THE weapon. "to attack anything."
						END IF.
					ELSE "There's no point attacking anything with" SAY THE weapon. "."
				END IF.


ADD TO EVERY THING
  VERB attack_with
    WHEN target
	CHECK target IS examinable
	  	ELSE 
			IF target IS NOT plural
				THEN "That's not"
				ELSE "Those are not"
			END IF.
			"something you can $v."
	AND weapon IS takeable
		ELSE "You don't have" SAY THE weapon. "."
	AND target <> hero 
		ELSE "It doesn't make sense to $v yourself."
	AND target NOT IN hero
		ELSE "It doesn't make much sense to $v something you're holding."
	AND target NOT IN worn
		ELSE "It doesn't make sense to $v something you're wearing."
	AND CURRENT LOCATION IS lit
		ELSE "It is too dark to see."
	AND target IS reachable
		ELSE SAY THE target. 
			IF target IS NOT plural
				THEN "is" 
				ELSE "are"
			END IF.
			"out of your reach."
	AND hero IS NOT sitting
		ELSE "It is difficult to attack anything while sitting down."
	AND hero IS NOT lying_down
		ELSE "It is difficult to attack anything while lying down."
      DOES "Resorting to brute force is not the solution here."
  END VERB.
END ADD TO.



-- ===============================================================


----- BITE 	(+ chew, taste)
 

-- ===============================================================


SYNTAX bite = bite (obj)
		WHERE obj ISA OBJECT
			ELSE 
				IF obj IS NOT plural
					THEN "That's not" 
					ELSE "Those are not"
				END IF. 
				"something you can bite."


ADD TO EVERY OBJECT
  VERB bite
	CHECK obj IS edible
		ELSE 
			IF obj IS NOT plural
				THEN "That's not" 
				ELSE "Those are not"
			END IF.
			"something you should $v."
	AND obj IS takeable
		ELSE "You don't have" SAY THE obj. "."
	AND CURRENT LOCATION IS lit
		ELSE "It is too dark to see."
	AND obj IS reachable
		ELSE SAY THE obj. 
			IF obj IS NOT plural
				THEN "is" 
				ELSE "are"
			END IF.
			"out of your reach."
	DOES 
		-- This if-statement takes care of implicit taking; i.e. if the hero
		-- doesn't have the object, (s)he will take it automatically first.
		-- This same if-statement is found in numerous other verbs throughout 
		-- the library, as well.

		IF obj NOT DIRECTLY IN hero	
			THEN  "(taking" SAY THE obj. "first)$n"
				LOCATE obj IN hero.
		END IF.

		
		"You take a bite of" SAY THE obj. "$$." 
			IF obj IS NOT plural
				THEN "It tastes rather good."
				ELSE "They taste rather good."
			END IF.
	
  END VERB.
END ADD TO.


SYNONYMS chew = bite.



-- ===============================================================


----- BREAK


-- ===============================================================


SYNTAX break = break (obj)
		WHERE obj ISA OBJECT
			ELSE 
				IF obj ISA ACTOR
					THEN "Resorting to brute force is not the solution here."
					ELSE "That's not something you can $v."
				END IF.


ADD TO EVERY OBJECT
  VERB break
	CHECK obj IS examinable
		ELSE 
			IF obj IS NOT plural
				THEN "That's not" 
				ELSE "Those are not"
			END IF.
			"something you can break."
	AND CURRENT LOCATION IS lit
		ELSE "It is too dark to see."
	AND obj IS reachable 
		ELSE SAY THE obj. 
			IF obj IS NOT plural
				THEN "is" 
				ELSE "are"
			END IF.
			"out of your reach."
	
	DOES
		"Resorting to brute force is not the solution here."
  END VERB.
END ADD TO.


SYNONYMS destroy = break.




-- ===============================================================


----- BREAK WITH


-- ===============================================================


SYNTAX break_with = break (obj) 'with' (instr)
		WHERE obj ISA OBJECT
			ELSE 
				IF obj IS NOT plural
					THEN "That's not" 
					ELSE "Those are not"
				END IF. 
				"something you can $v."
		AND instr ISA OBJECT
			ELSE 
				IF instr IS NOT plural
					THEN "That's not" 
					ELSE "Those are not"
				END IF.
				"something you can $v things with."


ADD TO EVERY OBJECT
   VERB break_with
	WHEN obj
	CHECK obj IS examinable
		ELSE 
			IF obj IS NOT plural
				THEN "That's not" 
				ELSE "Those are not"
			END IF.
			"something you can break."
	AND CURRENT LOCATION IS lit
		ELSE "It is too dark to see."
	AND instr IN hero
		ELSE "You don't have" SAY THE instr. "."
	AND obj IS reachable
		ELSE SAY THE obj. 
			IF obj IS NOT plural
				THEN "is" 
				ELSE "are"
			END IF.
		 	"out of your reach."
	DOES		
		"Trying to break" SAY THE obj. "with" SAY THE instr. 
		"wouldn't accomplish anything."
   END VERB.
END ADD TO.



-- ================================================================


----- BRIEF


-- ================================================================


-- Use "Visits 0." or "Visits 1000." in the START section if you want
-- the game to start in verbose or brief mode. (By default,
-- all games start in the verbose mode.)


SYNTAX brief = brief.


VERB brief
	DOES
		Visits 1000.
		"Brief mode is now on. Location descriptions will only be shown
		the first time you visit."
END VERB.



-- =================================================================


----- BURN


-- =================================================================


SYNTAX burn = burn (obj)
		WHERE obj ISA OBJECT
			ELSE 
				IF obj ISA ACTOR
					THEN "That would be needlessly brutal."
					ELSE "That's not something you can burn."
				END IF.


ADD TO EVERY OBJECT
  VERB burn
	CHECK obj IS examinable
		ELSE 
			IF obj IS NOT plural
				THEN "That's not"
				ELSE "Those are not"
			END IF.
			"something you can burn."
	AND CURRENT LOCATION IS lit
		ELSE "It is too dark to see."
	AND obj IS reachable
		ELSE SAY THE obj. 
			IF obj IS NOT plural
				THEN "is" 
				ELSE "are"
			END IF.
			"out of your reach."
	DOES
		"You must state what you want to burn" SAY THE obj. "with."
  END VERB.
END ADD TO.



-- =================================================================


----- BURN WITH


-- =================================================================


SYNTAX burn_with = burn (obj) 'with' (instr)
		WHERE obj ISA OBJECT
			ELSE 
				IF obj ISA ACTOR
					THEN "That would be needlessly brutal."
					ELSE "That's not something you can burn."
				END IF.
		AND instr ISA OBJECT
			ELSE 
				IF instr ISA ACTOR
					THEN "It doesn't make sense to burn something with" SAY THE instr. "."
					ELSE "It's not possible to burn something with that."
				END IF.


ADD TO EVERY OBJECT
  VERB burn_with
	WHEN obj
	CHECK obj IS examinable
		ELSE 
			IF obj IS NOT plural
				THEN "That's not" 
				ELSE "Those are not"
			END IF.
			"something you can burn."
	AND obj <> instr 
		ELSE "It doesn't make sense to burn something with itself."
	AND CURRENT LOCATION IS lit
		ELSE "It is too dark to see."
	AND obj IS reachable
		ELSE SAY THE obj. 
			IF obj IS NOT plural
				THEN "is" 
				ELSE "are"
			END IF.
			"out of your reach."
	AND instr IN hero
		ELSE "You don't have" SAY THE instr. "."
	DOES
		"You can't burn" SAY THE obj. "with" SAY THE instr. "."
  END VERB.
END ADD TO.



-- ==================================================================


----- BUY (+ purchase)


-- ==================================================================


SYNTAX buy = buy (item)
		WHERE item ISA OBJECT
			ELSE  
				IF item IS NOT plural
					THEN "That's not"
					ELSE "Those are not"
				END IF.
				"something you can $v."


ADD TO EVERY OBJECT
  VERB buy
	CHECK item IS examinable
		ELSE 
			IF item IS NOT plural
				THEN "That's not" 
				ELSE "Those are not"
			END IF.
			"something you can buy."
	DOES
		IF item IS NOT plural
			THEN "That's not" 
			ELSE "Those are not"
		END IF. 
		"for sale."
  END VERB.
END ADD TO.


SYNONYMS purchase = buy.



-- ==================================================================


----- CATCH


-- ==================================================================


SYNTAX catch = catch (obj)
		WHERE obj ISA THING
			ELSE "That's not something you can catch."


ADD TO EVERY THING
  VERB catch
	CHECK obj <> hero 
		ELSE "It doesn't make sense to $v yourself."
	AND CURRENT LOCATION IS lit
		ELSE "It is too dark to see."
	AND hero IS NOT sitting
		ELSE "It is difficult to catch anything while sitting down."
	AND hero IS NOT lying_down
		ELSE "It is difficult to catch anything while lying down."
	DOES
		IF obj IS NOT plural
			THEN "That doesn't" 
			ELSE "Those don't"
		END IF.
	      "need to be caught."
  END VERB.
END ADD TO.



-- ==================================================================


----- CLEAN ( + wipe, polish)


-- ==================================================================


SYNTAX clean = clean (obj)
		WHERE obj ISA OBJECT
			ELSE 
				IF obj IS NOT plural
					THEN "That's not" 
					ELSE "Those are not"
				END IF.
				"something you can $v."


ADD TO EVERY OBJECT
  VERB clean
	CHECK obj IS examinable
		ELSE IF obj IS NOT plural
				THEN "That's not" 
				ELSE "Those are not"
			END IF.
			"something you can $v."
	AND CURRENT LOCATION IS lit
		ELSE "It is too dark to see."
	AND obj IS reachable
		ELSE SAY THE obj. 
			IF obj IS NOT plural
				THEN "is" 
				ELSE "are"
			END IF.
			"out of your reach."
	DOES
		"Nothing would be achieved by that."
  END VERB.
END ADD TO.


SYNONYMS wipe, polish = clean.


----- notice that 'rub' is defined separately



-- ==============================================================


----- CLIMB


-- ==============================================================


SYNTAX climb = climb (obj)
		WHERE obj ISA OBJECT
			ELSE 
				IF obj IS NOT plural
					THEN "That's not" 
					ELSE "Those are not"
				END IF.
				"something you can climb."


ADD TO EVERY OBJECT
  VERB climb
	CHECK obj IS examinable
		ELSE IF obj IS NOT plural
				THEN "That's not" 
				ELSE "Those are not"
			END IF.
			"something you can climb."
	AND CURRENT LOCATION IS lit
		ELSE "It is too dark to see."
	AND obj IS reachable
		ELSE SAY THE obj.
			IF obj IS NOT plural
				THEN "is" 
				ELSE "are"
			END IF.
		 	"out of your reach."
	AND hero IS NOT sitting
		ELSE "It is difficult to climb while sitting down."
	AND hero IS NOT lying_down
		ELSE "It is difficult to climb while lying down."
	DOES 
		IF obj IS NOT plural
			THEN "That's not" 
			ELSE "Those are not"
		END IF.
		"something you can climb."
  END VERB.
END ADD TO.



-- ==============================================================


----- CLIMB ON


-- ==============================================================


SYNTAX climb_on = climb 'on' (surface)
		WHERE surface ISA SUPPORTER
			ELSE 
				IF surface IS NOT plural
					THEN "That's not" 
					ELSE "Those are not"
				END IF.
				"something you can climb on."


ADD TO EVERY SUPPORTER
  VERB climb_on
	CHECK surface IS reachable
		ELSE SAY THE surface.
			IF surface IS NOT plural
				THEN "is" 
				ELSE "are"
			END IF. 
			"out of your reach."
	AND CURRENT LOCATION IS lit
		ELSE "It is too dark to see."
	AND hero IS NOT sitting
		ELSE "It is difficult to climb anywhere while sitting down."
	AND hero IS NOT lying_down
		ELSE "It is difficult to climb anywhere while lying down."
	DOES 
		IF surface IS NOT plural
				THEN "That's not" 
				ELSE "Those are not"
			END IF.
		"something you can climb on."
  END VERB.
END ADD TO.



-- ==============================================================


----- CLIMB THROUGH


-- ==============================================================


SYNTAX climb_through = climb through (obj)
		WHERE obj ISA OBJECT
			ELSE
			 	IF obj IS NOT plural
					THEN "That's not" 
					ELSE "Those are not"
				END IF.	
				"something you can climb through."


ADD TO EVERY OBJECT
  VERB climb_through
	CHECK obj IS reachable
		ELSE SAY THE obj.
			IF obj IS NOT plural
				THEN "is" 
				ELSE "are"
			END IF.
			"out of your reach."
	AND CURRENT LOCATION IS lit
		ELSE "It is too dark to see."
	AND hero IS NOT sitting
		ELSE "It is difficult to climb anywhere while sitting down."
	AND hero IS NOT lying_down
		ELSE "It is difficult to climb anywhere while lying down."
	DOES 
		IF obj IS NOT plural
				THEN "That's not" 
				ELSE "Those are not"
			END IF.
		"something you can climb through."
  END VERB.
END ADD TO.



-- ==============================================================


----- CLOSE (+ shut)


-- ==============================================================


SYNTAX close = close (obj)
        	WHERE obj ISA OBJECT
	    		ELSE 
				IF obj IS NOT plural
					THEN "That's not" 
					ELSE "Those are not"
				END IF.
				"something you can $v."


ADD TO EVERY OBJECT
  VERB close
	CHECK obj IS closeable
	    ELSE
		 IF obj IS NOT plural
			THEN "That's not" 
			ELSE "Those are not"
		 END IF.
		 "something you can close."
	AND CURRENT LOCATION IS lit
		ELSE "It is too dark to see."
	AND obj IS NOT closed
	    ELSE
		 IF obj IS NOT plural
			THEN "It is" 
			ELSE "They are"
		 END IF.
		"already closed."
	AND obj IS reachable
		ELSE SAY THE obj. 
			IF obj IS NOT plural
				THEN "is" 
				ELSE "are"
			END IF.
			"out of your reach."
	DOES
	    MAKE obj closed.
	    "You close the" SAY THE obj. "."
  END VERB.
END ADD TO.


SYNONYMS shut = close.



-- ==============================================================


----- CLOSE WITH


-- ==============================================================


SYNTAX close_with = close (obj) 'with' (instr)
        	WHERE obj ISA OBJECT
	    		ELSE 
				IF obj IS NOT plural
					THEN "That's not"
					ELSE "Those are not"
				END IF.
				"something you can $v."
	  	AND instr ISA OBJECT
	    		ELSE 
				IF instr IS NOT plural
					THEN "That's not"
					ELSE "Those are not"
				END IF.
				"$v anything with that."


ADD TO EVERY OBJECT
  VERB close_with
    WHEN obj
	CHECK obj IS closeable
		ELSE 
			IF obj IS NOT plural
				THEN "That's not"
				ELSE "Those are not"
			END IF.
			"something you can $v."
	AND instr IN hero
		ELSE "You don't have" SAY THE instr. "."
	AND CURRENT LOCATION IS lit
		ELSE "It is too dark to see."
	AND obj IS NOT closed
	    ELSE 
			IF obj IS NOT plural
				THEN "It is"
				ELSE "They are"
			END IF.
			"already closed."
	AND obj IS reachable
		ELSE SAY THE obj. 
			IF obj IS NOT plural
				THEN "is" 
				ELSE "are"
			END IF.
			"out of your reach."
	DOES
	    "You can't $v" SAY THE obj. "with" SAY THE instr. "."
  END VERB.
END ADD TO.



-- ==============================================================


----- CONSULT


-- ==============================================================


SYNTAX consult = consult (source) about (topic)!
		WHERE source ISA THING
			ELSE "That's not something you can consult."
		AND topic ISA THING
			ELSE "That's not something you can find information about."
	

       consult = 'look' 'up' (topic) 'in' (source).


ADD TO EVERY THING
  VERB consult
    WHEN source
	CHECK source IS examinable
		ELSE 
			IF source IS NOT plural
				THEN "That's not"
				ELSE "Those are not"
			END IF.
			"something you can consult."
	AND source <> hero 
		ELSE "It doesn't make sense to consult yourself about anything."
	AND CURRENT LOCATION IS lit
		ELSE "It is too dark to see."
	AND source IS reachable
		ELSE SAY THE source. 
			IF source IS NOT plural
				THEN "is" 
				ELSE "are"
			END IF.
			"out of your reach."
	DOES 
		IF source ISA OBJECT
			THEN "You find nothing useful about" SAY THE topic. "in" SAY THE source. "."
			ELSE SAY THE source.
				IF source IS NOT plural
					THEN "chooses"
					ELSE "choose"
				END IF.
				"to be silent on that subject."
		END IF.
  END VERB.
END ADD TO.


--- another 'consult' formulation added to guide players to use the right phrasing:


SYNTAX consult_error = consult (source)
	WHERE source ISA THING
		ELSE "To consult something, please use the 
			formulation CONSULT PERSON/THING ABOUT PERSON/THING."	


ADD TO EVERY THING
  VERB consult_error
	DOES "To consult something, please use the formulation CONSULT PERSON/THING 
		ABOUT PERSON/THING."	
  END VERB.
END ADD TO.



-- ==============================================================


----- CREDITS (+ acknowledgments, author, copyright)


-- ==============================================================


SYNTAX credits = credits.


VERB credits
	DOES
		"The author retains the copyright to this game.
		$pThis game was written using the ALAN Adventure Language. ALAN is 
		an interactive fiction authoring system by Thomas Nilsson.
		$nE-mail address: thomas.nilsson@progindus.se $pFurther information 
		about the ALAN system can be obtained from
		the World Wide Web Internet site
		$ihttp://www.alanif.se$p"
END VERB.


SYNONYMS acknowledgments, author, copyright = credits.



-- ==============================================================


----- CUT


-- ==============================================================


SYNTAX cut = cut (obj)
		WHERE obj ISA OBJECT
			ELSE 
				IF obj IS NOT plural
					THEN "That's not"
					ELSE "Those are not"
				END IF.
				"something you can cut."


ADD TO EVERY OBJECT
  VERB cut
	DOES "You need to specify what you want to cut" SAY THE obj. "with."
  END VERB.
END ADD TO.



-- ==============================================================


----- CUT WITH


-- ==============================================================


SYNTAX cut_with = cut (obj) 'with' (instr)
		WHERE obj ISA OBJECT
			ELSE 
				IF obj IS NOT plural
					THEN "That's not"
					ELSE "Those are not"
				END IF.
				"something you can cut."
		AND instr ISA OBJECT
			ELSE 
				IF instr IS NOT plural
					THEN "That's not"
					ELSE "Those are not"
				END IF.
				"something you can cut with."


ADD TO EVERY OBJECT
  VERB cut_with
    WHEN obj
	CHECK obj <> instr
		ELSE "You can't cut something with itself."
	AND instr IN hero
		ELSE "You don't have" SAY THE instr. "."
	AND CURRENT LOCATION IS lit
		ELSE "It is too dark to see."
	AND obj IS reachable
		ELSE SAY THE obj. 
			IF obj IS NOT plural
				THEN "is" 
				ELSE "are"
			END IF.
			"out of your reach."
	DOES 
		"You can't cut" SAY THE obj. "with" SAY THE instr. "."
  END VERB.
END ADD TO.



-- ==============================================================


----- DANCE


-- ==============================================================


SYNTAX dance = dance.


VERB dance
	CHECK CURRENT LOCATION IS lit
		ELSE "It is too dark to see."
	AND hero IS NOT sitting
		ELSE "It is difficult to dance while sitting down."
	AND hero IS NOT lying_down
		ELSE "It is difficult to dance while lying down."
  DOES
    	"How about a waltz?"
END VERB.



-- ==============================================================


----- DIG


-- ==============================================================


SYNTAX dig = dig (obj)
		WHERE obj ISA OBJECT
			ELSE 
				IF obj IS NOT plural
					THEN "That's not"
					ELSE "Those are not"
				END IF.
				"something you can dig."


ADD TO EVERY OBJECT
  VERB dig
	CHECK CURRENT LOCATION IS lit
		ELSE "It is too dark to see."
	AND hero IS NOT sitting
		ELSE "It is difficult to dig anything while sitting down."
	AND hero IS NOT lying_down
		ELSE "It is difficult to dig anything while lying down."
	DOES 
		"There is nothing suitable to dig here."
  END VERB.
END ADD TO.



-- ==============================================================


----- DIVE


-- ==============================================================


SYNTAX dive = dive.


VERB dive 	
	CHECK CURRENT LOCATION IS lit
		ELSE "It is too dark to see."
	AND hero IS NOT sitting
		ELSE "It is difficult to dive anywhere while sitting down."
	AND hero IS NOT lying_down
		ELSE "It is difficult to dive anywhere while lying down."
	
	DOES 
		"There is no water suitable for swimming here."
END VERB.



-- ==============================================================


----- DIVE IN


-- ==============================================================


SYNTAX dive_in = dive 'in' (liq)
		WHERE liq ISA LIQUID
			ELSE 
				IF liq IS NOT plural
					THEN "That's not"
					ELSE "Those are not"
				END IF.
				"something you can dive into."


ADD TO EVERY OBJECT
  VERB dive_in
	CHECK CURRENT LOCATION IS lit
		ELSE "It is too dark to see."
	AND hero IS NOT sitting
		ELSE "It is difficult to dive anywhere while sitting down."
	AND hero IS NOT lying_down
		ELSE "It is difficult to dive anywhere while lying down."
	
	DOES 
		IF liq IS NOT plural
			THEN "That's not"
			ELSE "Those are not"
		END IF.
		"something you can dive into."
  END VERB.
END ADD TO.



-- ==============================================================


----- DRINK 


-- ==============================================================


SYNTAX drink = drink (liq)
		WHERE liq ISA LIQUID		-- see 'classes.i'
			ELSE 
				IF liq IS NOT plural
					THEN "That's not"
					ELSE "Those are not"
				END IF.
				"something you can drink."


ADD TO EVERY LIQUID
  VERB drink
	CHECK liq IS drinkable
		ELSE 
			IF liq IS NOT plural
				THEN "That's not"
				ELSE "Those are not"
			END IF.
			"something you can drink."
	AND liq IS takeable
		ELSE "You don't have" SAY THE liq. "."
	AND CURRENT LOCATION IS lit
		ELSE "It is too dark to see."
	AND liq IS reachable
		ELSE SAY THE liq. 
			IF liq IS NOT plural
				THEN "is" 
				ELSE "are"
			END IF.
			"out of your reach."
	DOES
		IF vessel OF liq = no_vessel		-- here, if the liquid is in no container, e.g.
								-- the hero takes a sip of water from a river,
								-- the action is allowed to succeed.
			THEN "You drink a bit of" SAY THE liq. "."
		ELSE 
			-- implicit taking:
				IF vessel OF liq NOT DIRECTLY IN hero
					THEN 
						IF vessel OF liq IS NOT takeable
							THEN "You can't carry" SAY THE liq. "around in your bare hands."
							ELSE LOCATE vessel OF liq IN hero.
								"(taking" SAY THE vessel OF liq. "first)$n"
						END IF.
				END IF.
			-- end of implicit taking.
		
			IF liq IN hero 		-- i.e. if the implicit taking was successful
				THEN
					"You drink all of" SAY THE liq. "."
					LOCATE liq AT nowhere.
			END IF.
		END IF.

  END VERB.
END ADD TO.


-- Note that the verb 'sip' is defined separately, with a slightly different behaviour.



-- ==============================================================


----- DRIVE


-- ==============================================================


SYNTAX drive = drive (vehicle)
		WHERE vehicle ISA OBJECT
			ELSE 
				IF vehicle IS NOT plural
					THEN "That's not"
					ELSE "Those are not"
				END IF.
				"something you can drive."


ADD TO EVERY OBJECT
  VERB drive
	DOES 
		IF vehicle IS NOT plural
			THEN "That's not"
			ELSE "Those are not"
		END IF.
		"something you can drive."
  END VERB.
END ADD TO.


-- another 'drive' formulation added to guide players to use the right phrasing:


SYNTAX drive_error = drive.


VERB drive_error
	DOES "To drive something, use the phrasing DRIVE SOMETHING."
END VERB.



-- ==============================================================


----- DROP


-- ==============================================================


SYNTAX drop = drop (obj)*
		WHERE obj ISA OBJECT
			ELSE 
				IF obj IS NOT plural
					THEN "That's not"
					ELSE "Those are not"
				END IF.
				"something you can $v."
  	
	
	drop = put (obj) * down.
  
	
	drop = put down (obj)*.


ADD TO EVERY OBJECT
  VERB drop
   	 CHECK obj IN hero
      	ELSE "You don't have" SAY THE obj. "."
    	DOES
      	LOCATE obj HERE.
      	"Dropped."
  END VERB.
END ADD TO.


SYNONYMS
  discard, dump, reject = drop.



-- ==============================================================


----- EAT 


-- ==============================================================


SYNTAX eat = eat (food)
		WHERE food ISA OBJECT
			ELSE 
				IF food IS NOT plural
					THEN "That's not"
					ELSE "Those are not"
				END IF.
				"something you can eat."


ADD TO EVERY OBJECT
  VERB eat
	CHECK food IS edible
		ELSE 
			IF food IS NOT plural
				THEN "That's not"
				ELSE "Those are not"
			END IF.
			"something you can eat."
	AND food IS takeable
		ELSE "You don't have" SAY THE food. "."
	AND CURRENT LOCATION IS lit
		ELSE "It is too dark to see."
	AND food IS reachable
		ELSE SAY THE food. 
			IF food IS NOT plural
				THEN "is" 
				ELSE "are"
			END IF.
			"out of your reach."
	DOES
		-- implicit taking:
		IF food NOT DIRECTLY IN hero
			THEN  "(taking" SAY THE food. "first)$n"
				LOCATE food IN hero.
		END IF.
		-- end of implicit taking.
		
		"You eat all of" SAY THE food. "."
		LOCATE food AT nowhere.

  END VERB.
END ADD.



-- ==============================================================


----- EMPTY   (+ POUR)


-- ==============================================================


-- The verbs 'empty' and 'pour' have similar syntaxes and behaviour here. They are, however,
-- not declared as synonyms but kept separate, as their usage doesn't overlap 100%; for example 
-- you can pour liquids but not empty them. 
-- That's why in 'classes.i', liquids are defined only to work with the verb 'pour',
-- and the verb 'empty' is disabled for liquids.




SYNTAX 'empty' = 'empty' (obj)
		WHERE obj ISA OBJECT
			ELSE 
				IF obj IS NOT plural
					THEN "That's not"
					ELSE "Those are not"
				END IF.
				"something you can empty."
		AND obj ISA CONTAINER
			ELSE "You can only empty containers."
	
	 pour = pour (obj)
		WHERE obj ISA OBJECT
			ELSE 
				IF obj IS NOT plural
					THEN "That's not"
					ELSE "Those are not"
				END IF.
				"something you can pour."
		AND obj ISA CONTAINER
			ELSE "You can only pour containers."


ADD TO EVERY OBJECT
  VERB 'empty', pour
	CHECK obj IS takeable
		ELSE "You don't have" SAY THE obj. "."
	AND CURRENT LOCATION IS lit
		ELSE "It is too dark to see."
	AND obj IS reachable
		ELSE SAY THE obj. 
			IF obj IS NOT plural
				THEN "is" 
				ELSE "are"
			END IF.
			"out of your reach."
	AND obj IS NOT closed
		ELSE "You can't, since" SAY THE obj. 
				IF obj IS NOT plural
					THEN "is"
					ELSE "are"
				END IF.
			"closed."
	DOES 
		-- implicit taking:
		IF obj NOT DIRECTLY IN hero
			THEN "(taking" SAY THE obj. "first)$n"
				LOCATE obj IN hero.
		END IF.
		-- end of implicit taking.

		IF COUNT ISA OBJECT, IN obj = 0
			THEN "There is nothing in" SAY THE obj.
			ELSE 	"You $v the contents of" SAY THE obj.
					IF floor HERE
						THEN "on the floor."
						ELSE "on the ground."
					END IF.
				EMPTY obj AT hero.
		END IF.
  END VERB.
END ADD TO.



-- ==============================================================


----- EMPTY IN	(+ POUR IN)	


-- ==============================================================



SYNTAX empty_in = 'empty' (obj) 'in' (cont)
	WHERE obj ISA OBJECT
		ELSE 
			IF obj IS NOT plural
				THEN "That's not"
				ELSE "Those are not"
			END IF.
			"something you can empty."
	AND obj ISA CONTAINER
		ELSE 
			IF obj IS NOT plural
				THEN "That's not"
				ELSE "Those are not"
			END IF.
			"something you can empty."
	AND cont ISA OBJECT					
		ELSE 
			IF cont IS NOT plural
				THEN "That's not"
				ELSE "Those are not"
			END IF.
			"something you can empty things into."
	AND cont ISA CONTAINER
		ELSE 
			IF cont IS NOT plural
				THEN "That's not"
				ELSE "Those are not"
			END IF.
			"something you can empty things into."	 


pour_in = pour (obj) 'in' (cont)
	WHERE obj ISA OBJECT
			ELSE 
				IF obj IS NOT plural
					THEN "That's not"
					ELSE "Those are not"
				END IF.
				"something you can pour."
	AND obj ISA CONTAINER
			ELSE 
			IF obj IS NOT plural
				THEN "That's not"
				ELSE "Those are not"
			END IF.
			"something you can pour."
	AND cont ISA OBJECT					
			ELSE 
			IF cont IS NOT plural
				THEN "That's not"
				ELSE "Those are not"
			END IF.
			"something you can pour things into."
	AND cont ISA CONTAINER
			ELSE 
			IF cont IS NOT plural
				THEN "That's not"
				ELSE "Those are not"
			END IF.
			"something you can pour things into."


ADD TO EVERY OBJECT
VERB empty_in, pour_in
   WHEN obj
	CHECK obj <> cont
		ELSE "It doesn't make sense to $v something into itself."
	AND obj IS takeable
		ELSE "You don't have" SAY THE obj. "."
	AND CURRENT LOCATION IS lit
		ELSE "It is too dark to see."
	AND obj NOT DIRECTLY IN cont
		ELSE SAY THE obj. 
			IF obj IS NOT plural
				THEN "is"
				ELSE "are"
			END IF.
			"already in" SAY THE cont. "."
	AND obj IS reachable
		ELSE SAY THE obj. 
			IF obj IS NOT plural
				THEN "is" 
				ELSE "are"
			END IF.
			"out of your reach."
	AND cont IS reachable
		ELSE SAY THE cont. 
			IF cont IS NOT plural
				THEN "is" 
				ELSE "are"
			END IF.
			"out of your reach."
	AND obj IS NOT closed
		ELSE "You can't, since" SAY THE obj. 
				IF obj IS NOT plural
					THEN "is"
					ELSE "are"
				END IF.
			"closed." 
	AND cont IS NOT closed
		ELSE "You can't, since" SAY THE cont.
				IF cont IS NOT plural
					THEN "is"
					ELSE "are"
				END IF.
			"closed."
	DOES
		-- implicit taking:
		IF obj NOT DIRECTLY IN hero
			THEN  "(taking" SAY THE obj. "first)$n"
				LOCATE obj IN hero.
		END IF.
		-- end of implicit taking.
			
		IF COUNT ISA OBJECT, IN obj = 0
			THEN "There is nothing in" SAY THE obj. "."
		ELSE EMPTY obj IN cont.
			"You $v the contents of" SAY THE obj. 
			"into" SAY THE cont. "."	
		END IF.
END VERB.
END ADD TO.



-- ==============================================================


----- EMPTY ON	(+ POUR ON)


-- ==============================================================



SYNTAX empty_on = 'empty' (obj) 'on' (surface)
		WHERE obj ISA OBJECT
			ELSE 
				IF obj IS NOT plural
					THEN "That's not"
					ELSE "Those are not"
				END IF.
				"something you can empty."
		AND obj ISA CONTAINER
			ELSE 
				IF obj IS NOT plural
					THEN "That's not"
					ELSE "Those are not"
				END IF.
				"something you can empty."
		AND surface ISA OBJECT
			ELSE 
				IF surface ISA ACTOR
					THEN 
						IF surface = hero 
							THEN "That wouldn't make sense."
							ELSE	"That wouldn't be polite."
						END IF.
					ELSE "You can't empty anything onto" SAY THE surface. "."
				END IF.
		AND surface ISA CONTAINER
			ELSE SAY THE surface. 
				IF surface IS NOT plural
					THEN "is not"
					ELSE "are not"
				END IF.
				"something you can empty things onto."


	pour_on = pour (obj) 'on' (surface)
		WHERE obj ISA OBJECT
			ELSE 
				IF obj IS NOT plural
					THEN "That's not"
					ELSE "Those are not"
				END IF.
				"something you can pour."
		AND obj ISA CONTAINER
			ELSE 
				IF obj IS NOT plural
					THEN "That's not"
					ELSE "Those are not"
				END IF.
				"something you can pour."
		AND surface ISA OBJECT
			ELSE 
				IF surface ISA ACTOR
					THEN 
						IF surface = hero 
							THEN "That wouldn't make sense."
							ELSE	"That wouldn't be polite."
						END IF.
					ELSE "You can't pour anything onto" SAY THE surface. "."
				END IF.
		AND surface ISA CONTAINER
			ELSE SAY THE surface. 
				IF surface IS NOT plural
					THEN "is not"
					ELSE "are not"
				END IF.
				"something you can pour things onto."


ADD TO EVERY OBJECT
VERB empty_on, pour_on
   WHEN obj
	CHECK obj <> surface
		ELSE "It doesn't make sense to $v something on itself."
	AND obj IS takeable
		ELSE "You don't have" SAY THE obj. "."
	AND CURRENT LOCATION IS lit
		ELSE "It is too dark to see."
	AND obj IS reachable
		ELSE SAY THE obj. 
			IF obj IS NOT plural
				THEN "is" 
				ELSE "are"
			END IF.
			"out of your reach."
	AND surface IS reachable
		ELSE SAY THE surface. 
			IF surface IS NOT plural
				THEN "is" 
				ELSE "are"
			END IF.
			"out of your reach."
	AND obj IS NOT closed
		ELSE "You can't, since" SAY THE obj. 
			IF obj IS NOT plural
				THEN "is"
				ELSE "are"
			END IF.
			"closed."
	DOES
		-- implicit taking:
		IF obj NOT DIRECTLY IN hero
			THEN  "(taking" SAY THE obj. "first)$n"
				LOCATE obj IN hero.
		END IF.
		-- end of implicit taking.
			
		IF COUNT ISA OBJECT, IN obj = 0
			THEN "There is nothing in" SAY THE obj. "."
		ELSE 
				IF surface = floor OR surface = ground 
					THEN EMPTY obj AT hero.
						"You $v the contents of" SAY THE obj. "on" SAY THE surface. "."
				ELSIF surface ISA SUPPORTER
					THEN EMPTY obj IN surface.
						"You $v the contents of" SAY THE obj. "on" SAY THE surface. "."
				ELSE "It wouldn't be sensible to $v anything on" SAY THE surface.
				END IF.
		END IF.
END VERB.
END ADD TO.



-- ==============================================================


----- ENTER 


-- ==============================================================


SYNTAX enter = enter (cont)
		WHERE cont ISA OBJECT
			ELSE 
				IF cont IS NOT plural
					THEN "That's not"
					ELSE "Those are not"
				END IF.
				"something you can enter."
      	AND cont ISA CONTAINER
			ELSE 
				IF cont IS NOT plural
					THEN "That's not"
					ELSE "Those are not"
				END IF.
				"something you can enter."


ADD TO EVERY OBJECT
  VERB enter
	 CHECK hero IS NOT sitting
		ELSE "It is difficult to enter anything while sitting down."
	 AND hero IS NOT lying_down
		ELSE "It is difficult to enter anything while lying down."
   	 DOES 
		IF cont IS NOT plural
			THEN "That's not"
			ELSE "Those are not"
		END IF.
		"something you can enter."
  END VERB.
END ADD TO.


--- another 'enter' formulation declared to guide players to use the right formulation:


SYNTAX enter_error = enter.


VERB enter_error
	DOES "You must state what you want to enter."
END VERB. 



-- ==============================================================


----- EXAMINE (+ look at)


-- ==============================================================


SYNTAX examine = examine (obj) 
		WHERE obj ISA THING
			ELSE 
				IF obj IS NOT plural
					THEN "That's not"
					ELSE "Those are not"
				END IF.
				"something you can examine."


SYNTAX examine = 'look' 'at' (obj).
	 examine = 'look' (obj).			-- note that this formulation is allowed, too


ADD TO EVERY THING
  VERB examine
    	CHECK obj IS examinable
      	ELSE 
			IF obj IS NOT plural
				THEN "That's not"
				ELSE "Those are not"
			END IF.
			"something you can examine."
    	AND CURRENT LOCATION IS lit
		ELSE "You can't see anything in the dark."
    	DOES
		IF obj IS readable
			THEN 
				IF text OF obj = ""
					THEN "There is nothing written on" SAY THE obj. "."
					ELSE "You read" SAY THE obj. "."
						IF obj IS NOT plural
							THEN "It says"
							ELSE "They say"
						END IF.  
						"""$$" SAY text OF obj. "$$""."
				END IF.
      		ELSE "There is nothing special about" SAY THE obj. "." 
		END IF.
  END VERB.
END ADD TO.


SYNONYMS
	'check', inspect, observe, x = examine.



-- ==============================================================


----- EXIT 


-- ==============================================================


SYNTAX 'exit' = 'exit' (cont)
		WHERE cont ISA OBJECT
			ELSE 
				IF cont IS NOT plural
					THEN "That's not"
					ELSE "Those are not"
				END IF.
				"something you can exit."
		AND cont ISA CONTAINER
			ELSE 
				IF cont IS NOT plural
					THEN "That's not"
					ELSE "Those are not"
				END IF.
				"something you can exit."

ADD TO EVERY OBJECT
  VERB 'exit'
	CHECK hero IN cont
		ELSE 
			IF cont = current_room
				THEN "You must state a direction where to go."
				ELSE "But you aren't in" SAY THE cont. "!"	
			END IF.
	DOES 
		"You exit" SAY THE cont. "."
		LOCATE hero AT CURRENT LOCATION.
		MAKE hero NOT sitting.
		MAKE hero NOT lying_down.
  END VERB.
END ADD TO.


--- another 'exit' formulation added to guide players to use the right formulation:


SYNTAX exit_error = 'exit'.


VERB exit_error
	DOES 
		"You must state what you want to exit."
END VERB.



-- ==============================================================


----- EXTINGUISH	(+ put out)


-- ==============================================================



SYNTAX extinguish = extinguish (obj)
	WHERE obj ISA OBJECT
		ELSE 
			IF obj IS NOT plural
				THEN "That's not"
				ELSE "Those are not"
			END IF.
			"something you can extinguish."
       
	extinguish = put 'out' (obj).


ADD TO EVERY OBJECT
  VERB extinguish
	DOES 
		IF obj IS NOT plural
			THEN "That's not"
			ELSE "Those are not"
		END IF.
		"on fire."
  END VERB.
END ADD TO.


SYNONYMS quench = extinguish.



-- ==============================================================


----- FILL


-- ==============================================================


SYNTAX fill = fill (cont)
		WHERE cont ISA OBJECT
			ELSE 
				IF cont IS NOT plural
					THEN "That's not"
					ELSE "Those are not"
				END IF.
				"something you can fill."
		AND cont ISA CONTAINER
			ELSE 	IF cont IS NOT plural
					THEN "That's not"
					ELSE "Those are not"
				END IF.
				"something you can fill."


ADD TO EVERY OBJECT
  VERB fill
	DOES 
		"You have to say what you want to fill" SAY THE cont. "with."
  END VERB.
END ADD TO.



-- ==============================================================


----- FILL WITH


-- ==============================================================


SYNTAX fill_with = fill (cont) 'with' (substance)
		WHERE cont ISA OBJECT
			ELSE 
				IF cont IS NOT plural
					THEN "That's not"
					ELSE "Those are not"
				END IF.
				"something you can fill."
		AND cont ISA CONTAINER
			ELSE 
				IF cont IS NOT plural
					THEN "That's not"
					ELSE "Those are not"
				END IF.
				"something you can fill."
		AND substance ISA OBJECT
			ELSE "It's not possible to fill something with"
				IF substance IS NOT plural
					THEN "that."
					ELSE "those."
				END IF.


ADD TO EVERY OBJECT
  VERB fill_with
    WHEN cont
	CHECK cont <> substance
		ELSE "It doesn't make sense to fill something with itself."
	AND CURRENT LOCATION IS lit
		ELSE "It is too dark to see."
	AND substance NOT IN cont
		ELSE SAY THE cont. "is already full of" SAY substance. "."
	AND cont IS reachable
		ELSE SAY THE cont. 
			IF cont IS NOT plural
				THEN "is" 
				ELSE "are"
			END IF.
			"out of your reach."
	DOES 
		-- "That wouldn't accomplish anything."
	
		"You fill" SAY THE cont. "with" SAY substance. "."
		LOCATE substance IN cont.
  END VERB.
END ADD TO.



-- ==============================================================


----- FIND


-- ==============================================================


SYNTAX
	find = find (obj)!
		WHERE obj ISA THING
			ELSE 
				IF obj IS NOT plural
					THEN "That's not"
					ELSE "Those are not"
				END IF.
				"something you need to find."


ADD TO EVERY THING
  VERB find
	CHECK obj <> hero 
		ELSE "You're right here!"
	AND CURRENT LOCATION IS lit
		ELSE "It's too dark to find anything here."
	AND obj NOT HERE
		ELSE "The" SAY obj. "is right here!"
	DOES
		"You'll have to find it yourself."
  END VERB.
END ADD TO.


SYNONYMS 'locate' = find.



-- ==============================================================


----- FIRE


-- ==============================================================


SYNTAX fire = fire (weapon)
		WHERE weapon ISA WEAPON
			ELSE 
				IF weapon IS NOT plural
					THEN "That's not"
					ELSE "Those are not"
				END IF.
				"something you can fire."


ADD TO EVERY WEAPON
  VERB fire
	CHECK weapon IS fireable
		ELSE 
			IF weapon IS NOT plural
				THEN "That's not"
				ELSE "Those are not"
			END IF.
			"something you can fire."
	AND weapon IN hero
		ELSE "You don't have" SAY THE weapon. "."
	AND CURRENT LOCATION IS lit
		ELSE "It is too dark to see."
	DOES 
		"You fire" SAY THE weapon. "into the air."
  END VERB.
END ADD TO.



-- ==============================================================


----- FIRE AT


-- ==============================================================


SYNTAX fire_at = fire (weapon) 'at' (target)
		WHERE weapon ISA WEAPON
			ELSE 
				IF weapon IS NOT plural
					THEN "That's not"
					ELSE "Those are not"
				END IF.
				"something you can fire."
		AND target ISA THING
			ELSE 
				IF target IS NOT plural
					THEN "That's not"
					ELSE "Those are not"
				END IF.
				"something you can shoot at."


ADD TO EVERY WEAPON
  VERB fire_at
    WHEN weapon
	CHECK weapon IS fireable
		ELSE 
			IF weapon IS NOT plural
				THEN "That's not"
				ELSE "Those are not"
			END IF.
			"something you can fire."
	AND weapon IN hero
		ELSE "You don't have" SAY THE weapon. "."
	AND target <> hero 
		ELSE "There's no need to be that desperate."
	AND CURRENT LOCATION IS lit
		ELSE "It is too dark to see."
	DOES 
		"Resorting to violence is not the solution here."
  END VERB.
END ADD TO.


-- another formulation added:


SYNTAX fire_at_error = fire 'at' (target)
	WHERE target ISA THING
		ELSE 
			IF target IS NOT plural
				THEN "That's not"
				ELSE "Those are not"
			END IF.
			"something you can fire at."


ADD TO EVERY THING
VERB fire_at_error
	CHECK COUNT ISA WEAPON, IS fireable, IN hero > 0
		ELSE "You are not holding any firearm."
	AND target <> hero
		ELSE "There's no need to be that desperate."
	AND CURRENT LOCATION IS lit
		ELSE "It is too dark to see."
	DOES 
		"Resorting to violence is not the solution here."
END VERB.
END ADD TO.



-- ==============================================================


----- FIX (mend, repair)


-- ==============================================================


SYNTAX
	fix = fix (obj)
		WHERE obj ISA OBJECT
			ELSE 
				IF obj IS NOT plural
					THEN "That's not"
					ELSE "Those are not"
				END IF.
				"something you can $v."


ADD TO EVERY OBJECT
  VERB fix
	CHECK CURRENT LOCATION IS lit
		ELSE "It is too dark to see."
	AND obj IS broken
		ELSE "The" SAY obj. "doesn't need fixing."
	AND obj IS reachable
		ELSE SAY THE obj. 
			IF obj IS NOT plural
				THEN "is" 
				ELSE "are"
			END IF.
			"out of your reach."
	DOES
		"Please be more specific. How do you intend to fix it?"
  END VERB.
END ADD TO.


SYNONYMS mend, repair = fix.



-- ==============================================================


----- FLIP


-- ==============================================================


SYNTAX flip = flip (obj)
		WHERE obj ISA OBJECT
			ELSE 
				IF obj IS NOT plural
					THEN "That's not"
					ELSE "Those are not"
				END IF.
				"something you can flip."


ADD TO EVERY OBJECT
  VERB flip 
	CHECK CURRENT LOCATION IS lit
		ELSE "It is too dark to see."
	AND obj IS reachable
		ELSE SAY THE obj. 
			IF obj IS NOT plural
				THEN "is" 
				ELSE "are"
			END IF.
			"out of your reach."
	DOES ONLY 
		"That's not something you need to flip."
  END VERB.
END ADD TO.



-- ==============================================================


----- FOLLOW


-- ==============================================================


SYNTAX follow = follow (act)!
		WHERE act ISA ACTOR
			ELSE 
				IF act IS NOT plural
					THEN "That's not"
					ELSE "Those are not"
				END IF.


ADD TO EVERY THING
  VERB follow
	CHECK act <> hero
		ELSE "It doesn't make sense to follow yourself." 
	AND CURRENT LOCATION IS lit
		ELSE "It is too dark to see."
	AND act NOT AT hero
		ELSE SAY THE act. "is right here."
	AND hero IS NOT sitting
		ELSE "It is difficult to follow anybody while sitting down."
	AND hero IS NOT lying_down
		ELSE "It is difficult to follow anybody while lying down."
	AND act NOT NEAR hero			-- this check presumes that if the actor to be followed
							-- is in an adjacent location, the hero will be able to follow him/her.				
		ELSE "You follow" SAY THE act. "."
			LOCATE hero AT act.
	DOES 
		"You don't quite know where" SAY THE act. "went. You must state a direction 
		where you want to go."
  END VERB.
END ADD TO.



-- ==============================================================


----- FREE (+ release)


-- ==============================================================


SYNTAX free = free (obj)
		WHERE obj ISA THING
			ELSE "That's not something you can $v."


ADD TO EVERY THING
  VERB free
	CHECK obj IS examinable
		ELSE "That's not something you can $v."
	AND obj <> hero 
		ELSE "You don't need to be freed at present."
	AND CURRENT LOCATION IS lit
		ELSE "It is too dark to see."
	AND obj IS reachable
		ELSE SAY THE obj. 
			IF obj IS NOT plural
				THEN "is" 
				ELSE "are"
			END IF.
			"out of your reach."
	DOES 
		"That doesn't need to be $vd."
  END VERB.
END ADD TO.


SYNONYMS release = free.



-- ==============================================================


------ GET OFF


-- ==============================================================


SYNTAX get_off = get off (surface)
	WHERE surface ISA SUPPORTER
		ELSE 
			IF surface IS NOT plural
				THEN "That's not"
				ELSE "Those are not"
			END IF.
			"something you can get off."


ADD TO EVERY SUPPORTER
  VERB get_off
	DOES
		IF hero IS sitting OR hero IS lying_down
			THEN "You get off" SAY THE surface. "."
				MAKE hero NOT lying_down.
				MAKE hero NOT sitting.
			ELSE "You're standing up already."
		END IF.
  END VERB.
END ADD TO.


-- ==============================================================


------ GET UP


-- ==============================================================


SYNTAX get_up = get up.		
		

VERB get_up
	DOES
		IF hero IS sitting 
			THEN "You stand up."
				MAKE hero NOT sitting.
		ELSIF hero IS lying_down
			THEN "You get up."
				MAKE hero NOT lying_down.
		ELSE "You're standing up already."
		END IF.
END VERB.



-- ==============================================================


----- GIVE (+ hand, offer)


-- ==============================================================


SYNTAX give = 'give' (obj) 'to' (recip)
    		WHERE obj ISA OBJECT
      		ELSE "You can only give away objects."
    		AND recip ISA ACTOR
      		ELSE 
				IF recip IS NOT plural
					THEN "That's not"
					ELSE "Those are not"
				END IF.
				"something you can give things to."
  	 

	 give = give (recip) (obj).


ADD TO EVERY OBJECT
  VERB give
    WHEN obj
	CHECK obj IS takeable
		ELSE "You don't have" SAY THE obj. "."
	AND obj <> recip
		ELSE "It doesn't make sense to give something to itself."
	AND recip <> hero
		ELSE "It doesn't make sense to give something to yourself."
	AND CURRENT LOCATION IS lit
		ELSE "It is too dark to see."
	AND obj IS reachable
		ELSE SAY THE obj. 
			IF obj IS NOT plural
				THEN "is" 
				ELSE "are"
			END IF.
			"out of your reach."
	AND recip IS reachable
		ELSE SAY THE recip. "is too far away."
	AND obj NOT IN recip
		ELSE SAY THE recip. "already has" SAY THE obj. "."
      DOES
		-- implicit taking:
		IF obj NOT DIRECTLY IN hero
			THEN  "(taking" SAY THE obj. "first)$n"
			LOCATE obj IN hero.
		END IF.
		-- end of implicit taking.
		
		"You give" SAY THE obj. "to" SAY THE recip. "."
	  	LOCATE obj IN recip.

  END VERB.
END ADD TO.


SYNONYMS hand, offer = give.



-- ==============================================================


----- GO TO


-- ==============================================================


SYNTAX go_to = 'to' (dest)!					-- because 'go' is predefined in the parser, it can't be used 
		WHERE dest ISA THING				-- in verb definitions
			ELSE "It's not possible to go to there."


ADD TO EVERY THING
  VERB go_to
	CHECK dest <> hero
		ELSE "You're right here!"
	AND hero IS NOT sitting
		ELSE "It is difficult to go anywhere while sitting down."
	AND hero IS NOT lying_down
		ELSE "It is difficult to go anywhere while lying down."
	DOES 
		IF dest AT hero
			THEN 
				IF dest IS NOT reachable
					THEN "You can't reach" SAY THE dest. "from here."
					ELSE 
						IF CURRENT LOCATION IS lit
							THEN "That's right here!"
							ELSE "It is too dark to see."
						END IF.
				END IF.
			ELSE "You can't see" SAY THE dest. "anywhere nearby. You must state a
					 direction where you want to go."
		END IF.
  END VERB.
END ADD TO.


SYNONYMS walk = go.		-- here we define a synonym for the predefined parser word 'go'
					-- which is not visible in the syntax itself.
					-- Thus, you will be able to say e.g. both 'go to shop' and 'walk to shop'
					-- (as well as e.g. both 'go east' and 'walk east').



-- ==============================================================


----- HELP -> see ABOUT


-- ==============================================================





-- ==============================================================


----- HINT (+ hints)


-- ==============================================================


SYNTAX hint = hint.


VERB hint
	DOES
		"Unfortunately hints are not available in this game."
END VERB.


SYNONYMS
	hints = hint.



-- ==============================================================


----- INVENTORY (+ i, inv)


-- ==============================================================



ADD TO EVERY THING
   IS weight 0.
END ADD TO THING.


ADD TO EVERY ACTOR 
   IS weight 50. 
END ADD TO ACTOR. 


ADD TO EVERY OBJECT
   IS weight 5.
END ADD TO OBJECT. 


SYNTAX i = i.


VERB i
	DOES 
		LIST hero.

		-- if the hero in your game carries any containers you want the contents of 
		-- to be listed after 'inventory', you should manually add the listing right here
            -- according to the following example:
		-- 
		-- IF bag IN hero
		--     THEN LIST bag.
		-- END IF.
		--
		-- This way, 'inventory' will yield e.g. "You are carrying a bag. The bag contains a book."
		-- If you leave the above addition out, the outcome will be just "You are carrying a bag.", with
		-- no comment on what is inside the bag.
		
		IF COUNT IN worn > 0		-- See the file 'classes.i', subclass 'clothing'.
			THEN LIST worn. 		-- This code will list what the hero is wearing.
		END IF.
	
END VERB.


SYNONYMS inv, inventory  = i.



-- ==============================================================


----- JUMP


-- ==============================================================


SYNTAX jump = jump.


VERB jump
	CHECK hero IS NOT sitting
		ELSE "It is difficult to jump while sitting down."
	AND hero IS NOT lying_down
		ELSE "It is difficult to jump while lying down."
	DOES
		"You jump on the spot, to no avail."
END VERB.



-- ==============================================================


----- JUMP IN


-- ==============================================================


SYNTAX jump_in = jump 'in' (cont)
		WHERE cont ISA OBJECT
			ELSE 
				IF cont IS NOT plural
					THEN "That's not"
					ELSE "Those are not"
				END IF.
				"something you can jump into."
		AND cont ISA CONTAINER
			ELSE 
				IF cont IS NOT plural
					THEN "That's not"
					ELSE "Those are not"
				END IF.
				"something you can jump into."


ADD TO EVERY OBJECT
  VERB jump_in
	CHECK CURRENT LOCATION IS lit
		ELSE "It's too dark to see."
	AND cont IS reachable
		ELSE SAY THE cont. 
			IF cont IS NOT plural
				THEN "is" 
				ELSE "are"
			END IF.
			"out of your reach."
	AND hero IS NOT sitting
		ELSE "It is difficult to jump while sitting down."
	AND hero IS NOT lying_down
		ELSE "It is difficult to jump while lying down."
	DOES
		"That's not something you can jump into."
	
  END VERB.
END ADD TO.



-- ==============================================================


----- JUMP ON


-- ==============================================================


SYNTAX jump_on = jump 'on' (surface)
		WHERE surface ISA OBJECT
		      ELSE 
				IF surface IS NOT plural
					THEN "That's not"
					ELSE "Those are not"
				END IF.
				"something you can jump on."
		AND surface ISA SUPPORTER
			ELSE 
				IF surface IS NOT plural
					THEN "That's not"
					ELSE "Those are not"
				END IF.
				"something you can jump on."


ADD TO EVERY OBJECT
  VERB jump_on
	CHECK CURRENT LOCATION IS lit
		ELSE "It is too dark to see."
	AND surface IS reachable
		ELSE SAY THE surface. 
			IF surface IS NOT plural
				THEN "is" 
				ELSE "are"
			END IF.
			"out of your reach."
	AND hero IS NOT sitting
		ELSE "It is difficult to jump while sitting down."
	AND hero IS NOT lying_down
		ELSE "It is difficult to jump while lying down."
	DOES
		IF surface ISA SUPPORTER
			THEN "That wouldn't accomplish anything."
			ELSE 
				IF surface IS NOT plural
					THEN "That's not"
					ELSE "Those are not"
				END IF.
				"something you can jump onto."
		END IF.
  END VERB.
END ADD TO.



-- =============================================================


----- KICK 


-- =============================================================


SYNTAX kick = kick (target)
    		WHERE target ISA THING
      		ELSE "That's not something you can kick."


ADD TO EVERY THING
  VERB kick
	CHECK target IS examinable
		ELSE 
			IF target IS NOT plural
				THEN "That's not"
				ELSE "Those are not"
			END IF.
			"something you can kick."
	AND target <> hero 
		ELSE "It doesn't make sense to kick yourself."
	AND target NOT IN hero
		ELSE "It doesn't make much sense to kick something you're holding."
	AND target NOT IN worn
		ELSE "It doesn't make sense to kick something you're wearing."
	AND CURRENT LOCATION IS lit
		ELSE "It is too dark to see."
	AND target IS reachable
		ELSE SAY THE target. 
			IF target IS NOT plural
				THEN "is" 
				ELSE "are"
			END IF.
			"out of your reach."
    	DOES "Resorting to brute force is not the solution here."
  END VERB.
END ADD TO.



-- ==============================================================


-- KILL (+ murder)


-- ==============================================================


SYNTAX kill = kill (victim)
		WHERE victim ISA ACTOR
			ELSE 
				IF victim IS NOT plural
					THEN "That's not"
					ELSE "Those are not"
				END IF.
				"something you can $v."


ADD TO EVERY ACTOR
  VERB kill
	CHECK victim <> hero 
		ELSE "There's no need to be that desperate."
	AND CURRENT LOCATION IS lit
		ELSE "It is too dark to see."
	DOES 
		"That would be needlessly brutal."
  END VERB.
END ADD TO.



-- ==============================================================


-- KILL WITH 


-- ==============================================================


SYNTAX kill_with = kill (victim) 'with' (weapon)
		WHERE victim ISA ACTOR
			ELSE 
				IF victim IS NOT plural
					THEN "That's not"
					ELSE "Those are not"
				END IF.
				"something you can $v."
		AND weapon ISA WEAPON
			ELSE "You cannot kill anybody with" SAY THE weapon. "."


ADD TO EVERY ACTOR
  VERB kill_with
	WHEN victim
	CHECK victim <> hero 
		ELSE "There's no need to be that desperate."
	AND weapon IN hero
		ELSE "You don't have" SAY THE weapon. "."
	AND CURRENT LOCATION IS lit
		ELSE "It is too dark to see."
	DOES 
		"That would be needlessly brutal."
  END VERB.
END ADD TO.



-- ==============================================================


----- KISS (+ hug, embrace)


-- ==============================================================


SYNTAX kiss = kiss (obj)
		WHERE obj ISA THING
			ELSE 
				IF obj IS NOT plural
					THEN "That's not"
					ELSE "Those are not"
				END IF.
				"something you can kiss."


ADD TO EVERY THING
  VERB kiss
	CHECK obj IS examinable
		ELSE 
			IF obj IS NOT plural
				THEN "That's not"
				ELSE "Those are not"
			END IF.
			"something you can kiss."
	AND obj <> hero
		ELSE "There is no time for that now."
	AND CURRENT LOCATION IS lit
		ELSE "It is too dark to see."
	AND obj IS reachable
		ELSE SAY THE obj. 
			IF obj IS NOT plural
				THEN "is" 
				ELSE "are"
			END IF.
			"out of your reach."	
	DOES
		IF obj ISA ACTOR
			THEN SAY THE obj. "avoids your advances."
			ELSE "Nothing would be achieved by that."
		END IF.
  END VERB.
END ADD TO.


SYNONYMS hug, embrace = kiss.



-- ==============================================================


----- KNOCK 


-- ==============================================================


SYNTAX knock = knock 'on' (obj)
		WHERE obj ISA OBJECT
			ELSE 
				IF obj IS NOT plural
					THEN "That's not"
					ELSE "Those are not"
				END IF.
				"something you can knock on."
	

       knock = knock (obj).


ADD TO EVERY OBJECT
  VERB knock
	CHECK obj IS examinable
		ELSE 
			IF obj IS NOT plural
				THEN "That's not"
				ELSE "Those are not"
			END IF.
			"something you can knock on."
	AND CURRENT LOCATION IS lit
		ELSE "It is too dark to see."
	AND obj IS reachable
		ELSE SAY THE obj. 
			IF obj IS NOT plural
				THEN "is" 
				ELSE "are"
			END IF.
			"out of your reach."
	DOES
		"You knock on" SAY THE obj. "$$. Nothing happens."
  END VERB.
END ADD TO.


--- another 'knock' formulation added to guide players to use the right phrasing:


SYNTAX knock_error = knock.


VERB knock_error
	DOES 
		"Please use the formulation KNOCK ON SOMETHING to knock on something."
END VERB.



-- ==============================================================


----- LIE DOWN


-- ==============================================================


SYNTAX lie_down = lie 'down'.
	 
	 lie_down = lie.


VERB lie_down
	CHECK hero IS NOT lying_down
		ELSE "You're lying down already."
	DOES 
		"There's no need to lie down right now."
		-- If you need this to work, insert the following lines instead of the above:
				-- DOES "You lie down."
				-- MAKE hero lying_down.
				-- MAKE hero NOT sitting_down.
END VERB.


-- When the hero is sitting or lying down, it will be impossible for her/him to
-- perform certain actions, as numerous verbs in the library have checks for this. 
-- For example, if the hero is lying down and the player types 'attack [something]',
-- the response will be "It will be difficult to attack anything while
-- lying down." 
-- Also, it is often essential to make certain objects NOT reachable when you are sitting
-- or lying down.



-- ==============================================================


----- LIE IN


-- ==============================================================


SYNTAX lie_in = lie 'in' (cont)
		WHERE cont ISA OBJECT
			ELSE 
				IF cont IS NOT plural
					THEN "That's not"
					ELSE "Those are not"
				END IF.
				"something you can lie in."
		AND cont ISA CONTAINER
			ELSE 
				IF cont IS NOT plural
					THEN "That's not"
					ELSE "Those are not"
				END IF.
				"something you can lie in."
	

       lie_in = lie 'down' 'in' (cont).
	

ADD TO EVERY OBJECT
  VERB lie_in
	CHECK hero IS NOT lying_down
		ELSE "You're lying down already."
	DOES 
		"There's no need to lie down in" SAY THE cont. "."
			-- If you need this to work, insert the following two lines instead of the above:
				-- DOES "You lie down in" SAY THE cont. "."
				-- LOCATE hero IN cont.
				-- MAKE hero lying_down.
  END VERB.
END ADD TO.


-- When the hero is sitting or lying down, it will be impossible for her/him to
-- perform certain actions, as numerous verbs in the library have checks for this. 
-- For example, if the hero is lying down and the player types 'attack [something]',
-- the response will be "It will be difficult to attack anything while
-- lying down." 
-- Also, it is often essential to make certain objects NOT reachable when you are sitting
-- or lying down.



-- ==============================================================


----- LIE ON


-- ==============================================================


SYNTAX lie_on = lie 'on' (surface)
		WHERE surface ISA SUPPORTER
			ELSE 
				IF surface IS NOT plural
					THEN "That's not"
					ELSE "Those are not"
				END IF.
				"something you can lie on."
       

	 lie_on = lie 'down' 'on' (surface).


ADD TO EVERY OBJECT
  VERB lie_on
	CHECK hero IS NOT lying_down
		ELSE "You're lying down already."
	DOES 
		"There's no need to lie down on" SAY THE surface. "."
		-- If you need this to work, insert the following two lines instead of the above:
			-- DOES "You lie down on" SAY THE surface. "."
			-- LOCATE hero IN surface.    
			-- MAKE hero lying_down.
  END VERB.
END ADD TO.



-- When the hero is sitting or lying down, it will be impossible for her/him to
-- perform certain actions, as numerous verbs in the library have checks for this. 
-- For example, if the hero is lying down and the player types 'attack [something]',
-- the response will be "It will be difficult to attack anything while
-- lying down." 
-- Also, it is often essential to make certain objects NOT reachable when you are sitting
-- or lying down.



-- ==============================================================


----- LIFT


-- ==============================================================


SYNTAX lift = lift (obj)
		WHERE obj ISA THING
			ELSE 
				IF obj IS NOT plural
					THEN "That's not"
					ELSE "Those are not"
				END IF.
				"something you can lift."


ADD TO EVERY THING
  VERB lift  
	CHECK obj IS examinable
		ELSE 
			IF obj IS NOT plural
				THEN "That's not"
				ELSE "Those are not"
			END IF.
			"something you can lift."
	AND CURRENT LOCATION IS lit
		ELSE "It is too dark to see."
	AND obj IS reachable
		ELSE SAY THE obj. 
			IF obj IS NOT plural
				THEN "is" 
				ELSE "are"
			END IF.
			"out of your reach."
	AND obj IS movable
		ELSE 
			IF obj IS NOT plural
				THEN "That's not"
				ELSE "Those are not"
			END IF.
			"something you can lift."
	AND obj IS inanimate
		ELSE SAY THE obj. "wouldn't probably appreciate that."
	AND obj <> hero
		ELSE "It doesn't make sense to lift yourself."
	AND obj NOT IN hero
		ELSE "You're already holding" SAY THE obj. "."
	DOES 
		"That wouldn't accomplish anything."	
  END VERB.
END ADD TO.



-- ==============================================================


----- LIGHT (+ lit)


-- ==============================================================


SYNTAX light = light (obj)
		WHERE obj ISA LIGHTSOURCE
			ELSE 
				IF obj IS NOT plural
					THEN "That's not"
					ELSE "Those are not"
				END IF.
				"something you can $v."


ADD TO EVERY OBJECT
  VERB light
	CHECK obj IS reachable
		ELSE SAY THE obj.
			IF obj IS NOT plural
				THEN "is"
				ELSE "are"
			END IF.
			"out of your reach."					
	DOES
		IF obj IS NOT plural
			THEN "That's not"
			ELSE "Those are not"
		END IF.
		"something you can $v."
  END VERB.
END ADD TO.


SYNONYMS lit = light.



-- ==============================================================


----- LISTEN


-- ==============================================================


SYNTAX listen0 = listen.


VERB listen0
	DOES
		"You hear nothing unusual."
END VERB.



-- ==============================================================


----- LISTEN TO


-- ==============================================================


SYNTAX listen = listen 'to' (obj)!
		WHERE obj ISA THING
			ELSE 
				IF obj IS NOT plural
					THEN "That's not"
					ELSE "Those are not"
				END IF.
				"something you can listen to."


ADD TO EVERY THING
  VERB listen
	CHECK obj <> hero 
		ELSE "It doesn't make sense to listen to yourself."
	DOES
		IF obj AT hero
			THEN "You hear nothing unusual."
		ELSIF obj NEAR hero
			THEN "You can't hear" SAY THE obj. "very well from here."
		ELSE "You can't hear anything."
		END IF.
  END VERB.
END ADD TO.



-- ==============================================================


----- LOCK


-- ==============================================================


SYNTAX lock = lock (obj)
    		WHERE obj ISA OBJECT
      		ELSE 
				IF obj IS NOT plural
					THEN "That's not"
					ELSE "Those are not"
				END IF.
				"something you can lock."


ADD TO EVERY OBJECT
  VERB lock
	CHECK obj IS lockable
	    ELSE 
			IF obj IS NOT plural
				THEN "That's not"
				ELSE "Those are not"
			END IF.
			"something you can lock."
	AND CURRENT LOCATION IS lit
		ELSE "It is too dark to see."
	AND obj IS reachable
		ELSE SAY THE obj. 
			IF obj IS NOT plural
				THEN "is" 
				ELSE "are"
			END IF.
			"out of your reach."
	AND obj IS NOT locked
	    ELSE SAY THE obj.
			IF obj IS NOT plural
				THEN "is"
				ELSE "are"
			END IF.
			"already locked."
	DOES
	    "You have to state what you want to lock" SAY THE obj. "with."
	    --  If you need this to work, use the following lines instead:
	    -- MAKE obj locked. "You" 
	    -- IF obj IS NOT closed
		-- THEN "close and"
		-- MAKE obj closed.
	    -- END IF.
	    -- "lock" SAY THE obj. "."
  END VERB.
END ADD TO. 



-- ==============================================================


----- LOCK WITH


-- ==============================================================


SYNTAX lock_with = lock (obj) 'with' (instr)
		WHERE obj ISA OBJECT
	    		ELSE 
				IF obj IS NOT plural
					THEN "That's not"
					ELSE "Those are not"
				END IF.
				"something you can lock."
		AND instr ISA OBJECT
	    		ELSE "You can't lock anything with" SAY THE instr. "."


ADD TO EVERY OBJECT
  VERB lock_with
    WHEN obj
	    CHECK obj IS lockable
		ELSE 
			IF obj IS NOT plural
				THEN "That's not"
				ELSE "Those are not"
			END IF.
			"something you can lock."
	    AND CURRENT LOCATION IS lit
		ELSE "It is too dark to see."
	    AND obj IS NOT locked
		ELSE 
			IF obj IS NOT plural
				THEN "It is"
				ELSE "They are"
			END IF.
			"already locked."
	    AND obj IS reachable
		ELSE SAY THE obj. 
			IF obj IS NOT plural
				THEN "is" 
				ELSE "are"
			END IF.
			"out of your reach."
	    AND instr IN hero
		ELSE
		    "You don't have" SAY THE instr. "."
	    DOES
		"You can't lock" SAY THE obj. "with" SAY THE instr. "."
		 -- If you need this to work, use the following lines instead:
	       -- MAKE obj locked. "You"
		 -- IF obj IS NOT closed
			-- THEN "close and"
			-- MAKE obj closed.
		 -- END IF.
		 -- "lock" SAY THE obj. "with" SAY THE instr. "."
  END VERB.
END ADD TO.



-- ==============================================================


----- LOOK


-- ==============================================================


SYNTAX 'look' = 'look'.


VERB 'look'
	DOES
		LOOK.
		INCREASE described OF CURRENT LOCATION. 		
		-- see 'locations.i', attribute 'described'.
END VERB.


SYNONYMS l = 'look'.



-- ==============================================================


----- LOOK AT -> see EXAMINE


-- ==============================================================





-- ==============================================================


----- LOOK BEHIND


-- ==============================================================


SYNTAX look_behind = 'look' behind (bulk)
		WHERE bulk ISA THING
			ELSE "You can't look behind" SAY THE bulk. "."


ADD TO EVERY THING
  VERB look_behind 
	CHECK bulk IS examinable
		ELSE 
			"You can't look behind" SAY THE bulk. "."
	AND CURRENT LOCATION IS lit
		ELSE "It is too dark to see."
	AND bulk <> hero 
		ELSE "Turning your head, you notice nothing unusual behind yourself."
	DOES 
		"You notice nothing unusual behind" SAY THE bulk. "."
  END VERB.
END ADD TO.



-- ==============================================================


----- LOOK IN


-- ==============================================================


SYNTAX
	look_in = 'look' 'in' (cont) 
		WHERE cont ISA OBJECT
			ELSE "You can't look inside" SAY THE cont. "."
		AND cont ISA CONTAINER
			ELSE "You can't look inside" SAY THE cont. "."


ADD TO EVERY OBJECT
  VERB look_in
	CHECK cont IS examinable
		ELSE 
			"You can't look inside" SAY THE cont. "."
	AND CURRENT LOCATION IS lit
		ELSE "It is too dark to see."
	AND cont IS NOT closed
		ELSE "You can't, since" SAY THE cont. 
			IF cont IS NOT plural
				THEN "is"
				ELSE "are"
			END IF.
			"closed."
	
	DOES  
		LIST cont.
  END VERB.
END ADD TO.



-- ==============================================================


----- LOOK OUT OF


-- ==============================================================


SYNTAX look_out_of = 'look' 'out' 'of' (obj)
		WHERE obj ISA OBJECT
			ELSE 
				IF obj IS NOT plural
					THEN "That's not"
					ELSE "Those are not"
				END IF.
				"something you can look out of."


ADD TO EVERY OBJECT
  VERB look_out_of 
	CHECK obj IS examinable
		ELSE 
			"You can't look out of" SAY THE obj. "."
	AND CURRENT LOCATION IS lit
		ELSE "It is too dark to see."
	DOES 
		IF obj IS NOT plural
			THEN "That's not"
			ELSE "Those are not"
		END IF.
		"something you can look out of."
  END VERB.
END ADD TO.



-- ==============================================================


----- LOOK THROUGH


-- ==============================================================


SYNTAX look_through = 'look' through (bulk)
		WHERE bulk ISA OBJECT
			ELSE 
				IF bulk IS NOT plural
					THEN "That's not"
					ELSE "Those are not"
				END IF.
				"something you can look through."


ADD TO EVERY OBJECT
  VERB look_through
	CHECK bulk IS examinable
		ELSE "You can't look through" SAY THE bulk. "."
	AND CURRENT LOCATION IS lit
		ELSE "It is too dark to see."
	DOES 
		"You can't see through" SAY THE bulk. "."
  END VERB.
END ADD TO.



-- ==============================================================


----- LOOK UNDER


-- ==============================================================


SYNTAX look_under = 'look' under (bulk)
		WHERE bulk ISA THING
			ELSE "That's not something you can look under."


ADD TO EVERY THING
  VERB look_under 
	CHECK bulk IS examinable
		ELSE "You can't look under" SAY THE bulk. "."
	AND bulk <> hero
		ELSE "It doesn't make sense to look under yourself."
	AND CURRENT LOCATION IS lit
		ELSE "It is too dark to see."
	DOES 
		"You notice nothing unusual under" SAY THE bulk. "."
  END VERB.
END ADD TO.



-- ==============================================================


----- LOOK UP 	(-> see also CONSULT)


-- ==============================================================


SYNTAX look_up = 'look' up.


VERB look_up
	DOES "Looking up, you see nothing unusual."
END VERB.



-- ==============================================================


----- NO


-- ==============================================================


SYNTAX 'no' = 'no'.


VERB 'no'
	DOES "You sound rather negative."
END VERB.



-- ==============================================================


----- NOTIFY


-- ==============================================================


-- Thanks to Steve Griffiths whose 'Score notification' sample was used
-- in declaring this verb.



SYNTAX notify = notify. 

	 notify_on = notify 'on'.	-- The instructions tell the player that mere 'notify'
						-- is enough, but these two verbs are implemented
	 notify_off = notify 'off'.	-- in case (s)he adds the prepositions to the end anyway.


VERB notify 
	DOES 
		IF hero IS notify_on 
			THEN MAKE hero NOT notify_on. 
				"Score notification is now disabled. (You can turn it back on 
				using the NOTIFY command again.)" 
			ELSE MAKE hero notify_on. "Score notification is now enabled. 
				(You can turn it off using the NOTIFY command again.)" 
		END IF. 
END VERB. 


VERB notify_on
	DOES 
		IF hero IS notify_on 
			THEN "Score notification is already enabled."
			ELSE MAKE hero notify_on. 
				"Score notification is now enabled. 
				(You can turn it off using the NOTIFY command again.)" 
		END IF. 
END VERB. 


VERB notify_off
	DOES 
		IF hero IS notify_on 
			THEN MAKE hero NOT notify_on. 
				"Score notification is now disabled. (You can turn it back on 
				using the NOTIFY command again.)" 
			ELSE "Score notification is already disabled." 
		END IF. 
END VERB. 


-- The 'notify' verb allows the players to disable the score change 
-- messages. (Some players find such messages annoying.) 
-- The verb toggles the hero's 'notify_on' attribute on and off. That 
-- attribute is checked by the 'checkscore' event to determine whether 
-- to display the score msg or not. 
	

-- The following event is run each turn to check if the game score is greater than 
-- the last recorded score (which is stored in the Hero's 'oldscore' 
-- attribute). If the score is greater, then the 'Score has gone up...' 
-- text is displayed (as long as the player hasn't disabled it by using the 
-- 'notify' verb - which sets 'notify_on' to off 
-- - i.e. the hero 'IS NOT notify_on'.) 

-- NOTE: The ALAN scoring system records the game score in a thing called 
-- score. It isn't called score OF anything; its just 'score'. 

-- NOTE: This event assumes score can only increase, if score can go 
-- down then you would need to modify this code a bit. 


EVENT check_score 
	IF oldscore OF hero < score 
		THEN 
			IF hero IS notify_on 
				THEN 			-- ie: the player wants to see score msgs 
					"$p(Your score has just gone up by" SAY (score - oldscore OF hero). 
					IF (score - oldscore OF hero) = 1
						THEN "point.)"
						ELSE "points.)"
					END IF. 
					-- this msg only displayed the first time player is notified 
					-- of a score change 
					IF hero IS NOT seen_notify 
						THEN MAKE hero seen_notify. 
							"$p(You can use the NOTIFY command to disable score change messages.)" 
					END IF. 
			END IF.
 
			SET oldscore OF hero TO score. 
	END IF. 
	-- run the 'check_score' event again next turn: 
	SCHEDULE check_score AT hero AFTER 1.
END EVENT. 




-- ==============================================================


----- OPEN


-- ==============================================================


SYNTAX open = open (obj)
    		WHERE obj ISA OBJECT
      		ELSE 
				IF obj IS NOT plural
					THEN "That's not"
					ELSE "Those are not"
				END IF.
				"something you can open."


ADD TO EVERY OBJECT
  VERB open
    CHECK obj IS closeable
      ELSE 
		IF obj IS NOT plural
			THEN "That's not"
			ELSE "Those are not"
		END IF.
		"something you can open."
    AND CURRENT LOCATION IS lit
	ELSE "It is too dark to see."
    AND obj IS reachable
	ELSE SAY THE obj. 
		IF obj IS NOT plural
			THEN "is" 
			ELSE "are"
		END IF.
		"out of your reach."
    AND obj IS closed
      ELSE SAY THE obj. 
		IF obj IS NOT plural
			THEN "is"
			ELSE "are" 
		END IF.
		"already open."
    AND obj IS NOT locked
	ELSE SAY THE obj. 
		IF obj IS NOT plural
			THEN "appears"
			ELSE "appear"
		END IF.
		"to be locked."
    DOES
      	MAKE obj NOT closed.
		"You open" SAY THE obj. "."
  END VERB.
END ADD TO.



-- ==============================================================


----- OPEN WITH


-- ==============================================================


SYNTAX open_with = open (obj) 'with' (instr)
    		WHERE obj ISA OBJECT
      		ELSE 
				IF obj IS NOT plural
					THEN "That's not"
					ELSE "Those are not"
				END IF.
				"something you can open."
    		AND instr ISA OBJECT
      		ELSE "You can't open anything with" SAY THE instr. "."


ADD TO EVERY OBJECT
  VERB open_with
    WHEN obj
	    CHECK obj IS closeable
		  ELSE 
			IF obj IS NOT plural
				THEN "That's not"
				ELSE "Those are not"
			END IF.
			"something you can open."
	    AND CURRENT LOCATION IS lit
		ELSE "It is too dark to see."
	    AND obj IS reachable
		ELSE SAY THE obj. 
			IF obj IS NOT plural
				THEN "is" 
				ELSE "are"
			END IF.
			"out of your reach."
	    AND instr IN hero
		ELSE "You don't have" SAY THE instr. "."
	    AND obj IS closed
		  ELSE SAY THE obj.  
			IF obj IS NOT plural
				THEN "is"
				ELSE "are"
			END IF. 
			"already open."
	    AND obj IS NOT locked
		ELSE SAY THE obj. "appears to be locked."
	    DOES
		  "You can't open" SAY THE obj. "with" SAY THE instr. "."
  END VERB.
END ADD TO.



-- ==============================================================


----- PLAY


-- ==============================================================


SYNTAX 'play' = 'play' (obj)
		WHERE obj ISA OBJECT
			ELSE 
				IF obj IS NOT plural
					THEN "That's not"
					ELSE "Those are not"
				END IF.
				"something you can play."


ADD TO EVERY OBJECT
  VERB 'play'
	DOES 
		IF obj IS NOT plural
			THEN "That's not"
			ELSE "Those are not"
		END IF.
		"something you can play."
  END VERB.
END ADD TO.



-- ==============================================================


----- PLAY WITH


-- ==============================================================


SYNTAX play_with = 'play' 'with' (obj)
		WHERE obj ISA OBJECT
			ELSE 
				IF obj IS NOT plural
					THEN "That's not"
					ELSE "Those are not"
				END IF.
				"something you can play with."


ADD TO EVERY OBJECT
  VERB play_with
	CHECK CURRENT LOCATION IS lit
		ELSE "It is too dark to see."
	DOES 
		"After second thoughts you don't find it purposeful to start
		 playing with" SAY THE obj. "."
  END VERB.
END ADD TO.



-- ==============================================================


----- POUR, POUR IN, POUR ON


-- ==============================================================



-- => SEE EMPTY, EMPTY IN, EMPTY ON




-- ==============================================================


----- PRAY 


-- ==============================================================


SYNTAX pray = pray.


VERB pray
	DOES "Your prayers don't seem to help right now."
END VERB.



-- ==============================================================


----- PRY


-- ==============================================================


SYNTAX pry = pry (obj)
		WHERE obj ISA OBJECT
			ELSE 
				IF obj IS NOT plural
					THEN "That's not"
					ELSE "Those are not"
				END IF.
				"something you can pry."


ADD TO EVERY OBJECT
VERB pry
	DOES "You must state what you want to pry" SAY THE obj. "with."
END VERB.
END ADD TO.



-- ==============================================================


----- PRY_WITH


-- ==============================================================


SYNTAX pry_with = pry (obj) 'with' (instr)
		WHERE obj ISA OBJECT
			ELSE 
				IF obj IS NOT plural
					THEN "That's not"
					ELSE "Those are not"
				END IF.
				"something you can pry."
		AND instr ISA OBJECT
			ELSE "You can't pry anything with"
				IF instr IS NOT plural
				THEN "that"
				ELSE "Those"
			END IF.
			"."


ADD TO EVERY OBJECT
VERB pry_with
	WHEN obj
	CHECK obj IS examinable
		ELSE 
			IF obj IS NOT plural
				THEN "That's not"
				ELSE "Those are not"
			END IF.
			"something you can pry."
	AND obj <> instr
		ELSE "You can't pry something with itself."
	AND instr IN hero
		ELSE "You don't have" SAY THE instr.
	AND CURRENT LOCATION IS lit
		ELSE "It is too dark to see."
	AND obj IS reachable
		ELSE SAY THE obj. 
			IF obj IS NOT plural
				THEN "is" 
				ELSE "are"
			END IF.
			"out of your reach."
	DOES "That doesn't work."
END VERB.
END ADD TO.



-- ==============================================================


----- PULL


-- ==============================================================


SYNTAX pull = pull (obj)
		WHERE obj ISA OBJECT
			ELSE 
				IF obj ISA ACTOR
					THEN 
						IF obj = hero
							THEN "It doesn't make sense to pull yourself."
							ELSE SAY THE obj. "wouldn't probably appreciate that."
						END IF.
					ELSE 
						IF obj IS NOT plural
							THEN "That's not"
							ELSE "Those are not"
						END IF.
						"something you can pull."
				END IF.


ADD TO EVERY OBJECT
VERB pull
	CHECK obj IS movable
		ELSE "It's not possible to pull" SAY THE obj. "."
	AND CURRENT LOCATION IS lit
		ELSE "It is too dark to see."
	AND obj IS reachable
		ELSE SAY THE obj. 
			IF obj IS NOT plural
				THEN "is" 
				ELSE "are"
			END IF.
			"out of your reach."
	DOES "That wouldn't accomplish anything."
END VERB.
END ADD TO.



-- ==============================================================


----- PUSH


-- ==============================================================


SYNTAX push = push (obj)
		WHERE obj ISA THING
			ELSE 
				IF obj IS NOT plural
					THEN "That's not"
					ELSE "Those are not"
				END IF.
				"something you can push."


ADD TO EVERY THING
    VERB PUSH
	CHECK obj IS movable
	      ELSE 
			IF obj IS NOT plural
				THEN "That's not"
				ELSE "Those are not"
			END IF.
			"something you can push."
	AND obj NOT IN hero
		ELSE "But you're holding" SAY THE obj. "."
	AND obj <> hero
		ELSE "It doesn't make sense to push yourself."
	AND obj IS inanimate
		ELSE SAY THE obj. "wouldn't probably appreciate that."
	AND CURRENT LOCATION IS lit
		ELSE "It is too dark to see."
	AND obj IS reachable
		ELSE SAY THE obj. 
			IF obj IS NOT plural
				THEN "is" 
				ELSE "are"
			END IF.
			"out of your reach."
	DOES
	    "You give" SAY THE obj. "a little push. Nothing happens."
    END VERB.
END ADD TO.


SYNONYMS press = push.



-- ==============================================================


----- PUSH WITH


-- ==============================================================


SYNTAX push_with = push (obj) 'with' (instr)
		WHERE obj ISA THING
	    		ELSE "That's not something you can push."
		AND instr ISA OBJECT
	    		ELSE "You can use only objects to push things with."


ADD TO EVERY THING
    VERB push_with
	WHEN obj
	CHECK obj IS movable
	        ELSE 
			IF obj IS NOT plural
				THEN "That's not"
				ELSE "Those are not"
			END IF.
			"something you can push."
	AND obj <> instr
		ELSE "It doesn't make sense to push something with itself."
	AND obj NOT IN hero
		ELSE "But you're holding" SAY THE obj. "."
	AND instr IN hero
		ELSE "You don't have" SAY THE instr. "."
	AND obj <> hero
		ELSE "It doesn't make sense to push yourself with something."
	AND obj IS inanimate
		ELSE SAY THE obj. "wouldn't probably appreciate that." 
	AND CURRENT LOCATION IS lit
		ELSE "It is too dark to see."
	AND obj IS reachable
		ELSE SAY THE obj. 
			IF obj IS NOT plural
				THEN "is" 
				ELSE "are"
			END IF.
			"out of your reach."
	DOES
		"Using" SAY THE instr. "you push" SAY THE obj. "$$. Nothing happens."
    END VERB. 
END ADD TO.



-- ==============================================================


----- PUT (+ lay, locate, place)


-- ==============================================================


SYNTAX put = put (obj) 
		WHERE obj ISA OBJECT
			ELSE "You can't put"
				IF obj IS NOT plural
					THEN "that"
					ELSE "those"
				END IF.
				"anywhere."


ADD TO EVERY OBJECT
  VERB put
	CHECK obj IN HERO
		ELSE "You don't have" SAY THE obj.
	AND CURRENT LOCATION IS lit
		ELSE "It is too dark to see."
	DOES
		"You must state where you want to put" 
			IF obj IS NOT plural
				THEN "it."
				ELSE "them."
			END IF.
  END VERB.
END ADD TO.


SYNONYMS lay, place = put.



-- ==============================================================


----- PUT DOWN	(works as  'drop')


-- ==============================================================


----- The syntax for 'put down' has been declared in the 'drop' verb.




-- ==============================================================


----- PUT IN	(+ insert)


-- ==============================================================


SYNTAX put_in = put (obj) 'in' (cont)
		WHERE obj ISA OBJECT
			ELSE 
				IF obj ISA ACTOR
				  THEN 
					IF obj = hero
						THEN "It doesn't make sense to put yourself into something."
						ELSE "You can only put objects somewhere."
							-- If you need to allow e.g. 'put child in bed'
							-- then you should remove this check.
					END IF.
				  ELSE "You can't put that anywhere."
				END IF.
		AND cont ISA OBJECT
			ELSE 
				IF cont IS NOT plural
					THEN "That's not"
					ELSE "Those are not"
				END IF.
				"something you can put things in."
		AND cont ISA CONTAINER
			ELSE "You can't put anything there." 
	 
   
        put_in = insert (obj) 'in' (cont).
		

ADD TO EVERY OBJECT
    VERB put_in
	WHEN obj
	    CHECK obj <> cont
	        	ELSE "It doesn't make sense to put something into itself."
	    AND obj IS takeable
		  	ELSE "You don't have" SAY THE obj. "."
	    AND CURRENT LOCATION IS lit
			ELSE "It is too dark to see."
	    AND obj NOT IN cont
		  	ELSE 
				IF cont ISA SUPPORTER
					THEN "You can't put" SAY THE obj. "inside" SAY THE cont. "."
					ELSE SAY THE obj. 
						IF obj IS NOT plural
							THEN "is"
							ELSE "are"
						END IF.
						"in" SAY THE cont. "already."
				END IF.
	    AND cont IS NOT closed
		  	ELSE "You can't, since" SAY THE cont. 
					IF cont IS NOT plural
						THEN "is"
						ELSE "are"
					END IF.
				"closed."
	    AND cont IS reachable
		  	ELSE SAY THE cont. 
				IF cont IS NOT plural
					THEN "is" 
					ELSE "are"
				END IF.
				"out of your reach."
	    DOES
			-- implicit taking:
			IF obj NOT DIRECTLY IN hero
				THEN  "(taking" SAY THE obj. "first)$n"
					LOCATE obj IN hero.
			END IF.
			-- end of implicit taking.
			
			LOCATE obj IN cont.
			"You put" SAY THE obj. "into" SAY THE cont. "."
				
    END VERB.
END ADD TO.



-- ==============================================================


----- PUT BEHIND, NEAR, UNDER


-- ==============================================================


SYNTAX put_near = put (obj) 'near' (bulk)
        	WHERE obj ISA OBJECT
	    		ELSE
				IF obj ISA ACTOR
					THEN SAY THE obj. "wouldn't probably appreciate that."
					ELSE "You can't put that anywhere."
				END IF.
	  	AND bulk ISA THING
	    		ELSE "You can't put anything near that."


    	 put_behind = put (obj) behind (bulk)
       	 WHERE obj ISA OBJECT
	    		ELSE 
				IF obj ISA ACTOR
					THEN SAY THE obj. "wouldn't probably appreciate that."
					ELSE "You can't put that anywhere."
				END IF.
		AND bulk ISA THING
	    		ELSE "You can't put anything behind that."

    
   	 put_under = put (obj) under (bulk)
        	WHERE obj ISA OBJECT
	    		ELSE
				IF obj ISA ACTOR
					THEN SAY THE obj. "wouldn't probably appreciate that."
					ELSE "You can't put that anywhere."
				END IF.
		AND bulk ISA THING
	    		ELSE "You can't put anything under that."


ADD TO EVERY OBJECT
    VERB put_near, put_behind, put_under
	WHEN obj	
	    CHECK bulk NOT IN hero
		  ELSE "That would be futile."
	    AND obj IS takeable
		  ELSE "You don't have" SAY THE obj. "."	
	    AND obj <> bulk
		   ELSE "That doesn't make sense."
	    AND bulk <> hero
		   ELSE "That would be futile."
	    AND CURRENT LOCATION IS lit
		    ELSE "It is too dark to see."
	    AND bulk IS reachable
			ELSE SAY THE bulk. 
				IF bulk IS NOT plural
					THEN "is" 
					ELSE "are"
				END IF.
			"out of your reach."
	    DOES
		   "That wouldn't accomplish anything."
		
             -- To make it work, type e.g.:	
		 -- IF obj NOT IN hero
			-- THEN  "(taking" SAY THE obj. "first)$n"
		 -- END IF.
		 -- "You put" SAY THE obj. "near" --(or behind or under) SAY THE bulk. "."
		 -- (+ you would need to define some attributes to check that 
		 -- the object is behind another object, etc.)
	
    END VERB.
END ADD TO.



-- ==============================================================


----- PUT_ON


-- ==============================================================


-- To use this verb in the meaning 'wear', see the file 'classes.i',
--  class 'clothing', verb 'wear'.

-- You can put things on the floor/ground or on a supporter. In other 
-- cases, the response will be "That wouldn't accomplish anything."



SYNTAX put_on = put (obj) 'on' (surface)
		WHERE obj ISA OBJECT
	    		ELSE
				IF obj ISA ACTOR
					THEN 
						IF obj = hero
							THEN "That would be futile."
							ELSE SAY THE obj. "wouldn't probably 
								appreciate that."
						END IF.
					ELSE "You can't put that anywhere."
				END IF.
		AND surface ISA OBJECT	
	    		ELSE "You can't well put anything on"
				IF surface IS NOT plural
					THEN "that."
					ELSE "those."
				END IF.	
      	AND surface ISA CONTAINER
	    		ELSE "You can't well put anything on"
				IF surface IS NOT plural
					THEN "that."
					ELSE "those."
				END IF.



ADD TO EVERY OBJECT
    VERB put_on
	WHEN obj
	    CHECK surface NOT IN hero
		  ELSE "That would be futile."
	    AND obj IS takeable
		   ELSE "You don't have" SAY THE obj. "."	
	    AND obj <> surface
		   ELSE "That doesn't make sense."
	    AND CURRENT LOCATION IS lit
		    ELSE "It is too dark to see."
	    AND obj NOT IN surface
		   ELSE SAY THE obj. 
			IF obj IS NOT plural
				THEN "is"
				ELSE "are"
			END IF.
			"on" SAY THE surface. "already."
	    AND obj IS reachable
			ELSE SAY THE obj. 
				IF obj IS NOT plural
					THEN "is" 
					ELSE "are"
				END IF.
				"out of your reach."
	    AND surface IS reachable
			ELSE SAY THE surface. 
				IF surface IS NOT plural
					THEN "is" 
					ELSE "are"
				END IF.
				"out of your reach."
	    DOES	  
			-- implicit taking:
		 	IF obj NOT DIRECTLY IN hero
				THEN  "(taking" SAY THE obj. "first)$n"
					LOCATE obj IN hero.
			END IF.
			-- end of implicit taking.
		
			IF surface = floor OR surface = ground
				THEN LOCATE obj AT hero.
				"You put" SAY THE obj. "on" SAY THE surface. "."
			ELSIF surface ISA SUPPORTER
				THEN LOCATE obj IN surface.
				"You put" SAY THE obj. "on" SAY THE surface. "."
			ELSE "That wouldn't accomplish anything."
			END IF.	
    END VERB.
END ADD TO.



-- ==============================================================


----- PUT OUT  (works as -> EXTINGUISH)


-- ==============================================================


----- The syntax for 'put out' has been declared in the 'extinguish' verb.



-- ==============================================================


----- QUIT


-- ==============================================================


SYNTAX
	'quit' = 'quit'.


VERB 'quit'
	DOES
		QUIT.
END VERB.


SYNONYMS q = 'quit'.



-- ==============================================================


----- READ


-- ==============================================================


SYNTAX read = read (obj)
		WHERE obj ISA OBJECT
	    		ELSE 
				IF obj IS NOT plural
					THEN "That's not"
					ELSE "Those are not"
				END IF.
				"something you can read."


ADD TO EVERY OBJECT
    VERB read
	CHECK obj IS readable
	    ELSE
		IF obj IS NOT plural
			THEN "That's not"
			ELSE "Those are not"
		END IF.
		"something you can read."
	AND CURRENT LOCATION IS lit
		ELSE "It is too dark to see."
	AND obj IS reachable
		ELSE SAY THE obj. 
			IF obj IS NOT plural
				THEN "is" 
				ELSE "are"
			END IF.
			"too far away."
	DOES
		IF text OF obj = ""
			THEN "There's nothing written on" SAY THE obj. "."
			ELSE "You read" SAY THE obj. "." 
				IF obj IS NOT plural
					THEN "It says"
					ELSE "They say"
				END IF.
				"""$$" SAY text OF obj. "$$""." 
		END IF.
    END VERB.
END ADD TO.



-- ==============================================================


-- REMOVE


-- ==============================================================


-- see the file 'classes.i', class 'clothing' for the definition of
-- this verb





-- ==============================================================


----- REMOVE FROM      ( => TAKE FROM)


-- ==============================================================


----- this verb works as 'take from'



-- ==============================================================


----- RESTART


-- ==============================================================


SYNTAX 'restart' = 'restart'.


VERB 'restart'
	DOES
		RESTART.
END VERB.



-- ==============================================================


----- RESTORE


-- ==============================================================


SYNTAX 'restore' = 'restore'.


VERB 'restore'
	DOES
		RESTORE.
END VERB.



-- ==============================================================


----- RUB (+ massage)


-- ==============================================================


SYNTAX rub = rub (obj)
		WHERE obj ISA THING
			ELSE "That's not something you can rub."


ADD TO EVERY THING
  VERB rub
	CHECK obj IS examinable
		ELSE 
			IF obj IS NOT plural
				THEN "That's not"
				ELSE "Those are not"
			END IF.
			"something you can rub."
	AND obj <> hero
		ELSE "There's no time for that now."
	AND obj IS inanimate
		ELSE "You aren't sure whether" SAY THE obj. 
			"would appreciate that."
	AND CURRENT LOCATION IS lit
		ELSE "It is too dark to see."
	AND obj IS reachable
		ELSE SAY THE obj. 
			IF obj IS NOT plural
				THEN "is" 
				ELSE "are"
			END IF.
			"out of your reach."
	DOES
		"Nothing would be achieved by that."
  END VERB.
END ADD TO.


SYNONYMS massage = rub.



-- ==============================================================


----- SAVE


-- ==============================================================


SYNTAX 'save' = 'save'.


VERB 'save'
	DOES
		SAVE.
END VERB.



-- ==============================================================


----- SAY


-- ==============================================================


SYNTAX 'say' = 'say' (topic)
    		WHERE topic ISA STRING
      		ELSE "That's not something you can say."


ADD TO EVERY THING
  VERB 'say'
    DOES
      "You utter """ SAY topic. "$$"". Nothing happens."
  END VERB.
END ADD TO.



-- ==============================================================


----- SAY TO


-- ==============================================================


SYNTAX say_to = 'say' (topic) 'to' (act)
    		WHERE topic ISA STRING
      		ELSE "Nothing happens."
    		AND act ISA ACTOR
      		ELSE 
				IF act IS NOT plural
					THEN "That's not"
					ELSE "Those are not"
				END IF.
				"something you can talk to."


ADD TO EVERY ACTOR
  VERB say_to
    WHEN act
      CHECK act CAN talk
		ELSE 
			IF act IS NOT plural
				THEN "That's not"
				ELSE "Those are not"
			END IF.
			"something you can talk to."
	AND act IS reachable
		ELSE SAY THE act. 
			IF act IS NOT plural
				THEN "is" 
				ELSE "are"
			END IF.
			"too far away."
      DOES
		SAY THE act. 
			IF act IS NOT plural
				THEN "doesn't look"
				ELSE "don't look"
			END IF.
			"seem interested."
  END VERB.
END ADD TO.



-- ==============================================================


----- SCORE


-- ==============================================================


SYNTAX 'score' = 'score'.


VERB 'score'
	DOES
		SCORE.
		-- (or, if you wish to disable the score, use the following kind of 
			-- line instead of the above:)
		-- "There is no score in this game."
END VERB 'score'.



-- ==============================================================


----- SCRATCH


-- ==============================================================


SYNTAX scratch = scratch (obj)
		WHERE obj ISA THING
			ELSE "That's not something you can scratch."


ADD TO EVERY THING
  VERB scratch
	CHECK obj IS examinable
		ELSE 
			IF obj IS NOT plural
				THEN "That's not"
				ELSE "Those are not"
			END IF.
			"something you can scratch."
	AND obj IS inanimate
		ELSE SAY THE obj. "wouldn't probably appreciate that."
	AND obj <> hero
		ELSE "That wouldn't help matters."
	AND CURRENT LOCATION IS lit
		ELSE "It is too dark to see."
	AND obj IS reachable
		ELSE SAY THE obj. 
			IF obj IS NOT plural
				THEN "is" 
				ELSE "are"
			END IF.
			"out of your reach."
	DOES
		"Nothing would be achieved by that."
  END VERB.
END ADD TO.




-- ==============================================================


------ SCRIPT


-- ==============================================================


SYNTAX 'script' = 'script'.
	 'script' = 'script' 'on'.
	 'script' = 'script' 'off'.

VERB 'script' 
	DOES 
		"Starting a transcript of the current game varies depending on the interpreter you are running. 
		In a GUI-version you probably find this in the drop-down menu. In the command line version 
		you need to start your game with the -s switch. 
		$n(In the near future, a 'script on/off' command will be implemented.)"

END VERB.
    


SYNONYMS transcript = 'script'.



-- ==============================================================


------ SEARCH


-- ==============================================================


SYNTAX search = search (obj) 
		WHERE obj ISA THING
			ELSE "That's not something you can search."


ADD TO EVERY THING
  VERB search
	CHECK obj <> hero
		ELSE LIST hero.
	AND obj IS inanimate
		ELSE SAY THE obj. "would probably object to that."
	AND CURRENT LOCATION IS lit			
		ELSE "It is too dark to see."
	AND obj IS reachable
		ELSE SAY THE obj. 
			IF obj IS NOT plural
				THEN "is" 
				ELSE "are"
			END IF.
			"out of your reach."
	DOES 
		"You find nothing of interest."
  END VERB.
END ADD TO.



-- ==============================================================


----- SELL


-- ==============================================================


SYNTAX sell = sell (item)
		WHERE item ISA OBJECT
			ELSE 
				IF item IS NOT plural
					THEN "That's not"
					ELSE "Those are not"
				END IF.
				"something you can sell."


ADD TO EVERY OBJECT
  VERB sell
	CHECK item IS examinable
		ELSE 
			IF item IS NOT plural
				THEN "That's not"
				ELSE "Those are not"
			END IF.
			"something you can sell."
	DOES
		"There's nobody here who would be interested in buying" SAY THE item. "."
  END VERB.
END ADD TO.



-- ==============================================================


----- SHAKE


-- ==============================================================


SYNTAX shake = shake (obj)
		WHERE obj ISA OBJECT
			ELSE 
				IF obj ISA ACTOR
					THEN 
						IF obj = hero
							THEN "It doesn't make sense 
								to shake yourself."
							ELSE SAY THE obj. "wouldn't probably 
								appreciate that."
						END IF.
					ELSE "That's not something you can shake."
				END IF.


ADD TO EVERY OBJECT
VERB shake
	CHECK obj IS examinable
		ELSE 
			IF obj IS NOT plural
				THEN "That's not"
				ELSE "Those are not"
			END IF.
			"something you can shake."
	AND obj IS movable
		ELSE "Shaking" SAY THE obj. "is not possible."
	AND CURRENT LOCATION IS lit
		ELSE "It is too dark to see."
	AND obj IS reachable
		ELSE SAY THE obj. 
			IF obj IS NOT plural
				THEN "is" 
				ELSE "are"
			END IF.
			"out of your reach."
	DOES 
		IF obj IN hero
			THEN "You shake" SAY THE obj. "cautiously in your hands. Nothing happens."
			ELSE "There is no reason to start shaking" SAY THE obj. "."
		END IF.
END VERB.
END ADD TO.



-- ==============================================================


----- SHOOT 


-- ==============================================================



SYNTAX shoot = shoot (target)
    		WHERE target ISA THING
      		ELSE "That's not something you can shoot."
       shoot = shoot 'at' (target).


ADD TO EVERY THING
  VERB shoot
	CHECK target <> hero 
		ELSE "There's no need to be that desperate."
	AND COUNT ISA WEAPON, IS fireable, IN hero > 0
		ELSE "You don't have anything to shoot with."
	AND CURRENT LOCATION IS lit
		ELSE "It is too dark to see."
	DOES 
		"Resorting to violence is not the solution here."
  END VERB.
END ADD TO.


-- another  'shoot' formulation added, to guide players to use the right phrasing:


SYNTAX shoot_error = shoot.


VERB shoot_error
	DOES "You must state what you want to shoot, e.g. SHOOT BEAR WITH RIFLE."
END VERB.


	
-- ==============================================================


----- SHOOT WITH


-- ==============================================================


SYNTAX shoot_with = shoot (target) 'with' (weapon)
    		WHERE target ISA THING
      		ELSE "That's not something you can shoot."
    		AND weapon ISA WEAPON
      		ELSE 
				IF weapon IS NOT plural
					THEN "That's not"
					ELSE "Those are not"
				END IF.
				"something you can shoot with."

	 shoot_with = shoot (weapon) 'at' (target).
			-- to allow player input such as 'shoot rifle at bear'


ADD TO EVERY THING
  VERB shoot_with
    WHEN target
      CHECK weapon IN hero
        ELSE "You don't have" SAY THE weapon. "."
	AND target IS examinable
		ELSE 
			IF target IS NOT plural
				THEN "That's not"
				ELSE "Those are not"
			END IF.
			"something you can shoot."
	AND target <> hero 
		ELSE "There's no need to be that desperate."
	AND target <> weapon
		ELSE "It doesn't make sense to shoot something with itself."
	AND CURRENT LOCATION IS lit
		ELSE "It is too dark to see."
      DOES
           "Resorting to violence is not the solution here."
  END VERB.
END ADD TO.



-- ==============================================================


----- SHOUT


-- ==============================================================


SYNTAX shout = shout.


VERB shout
  	DOES
    		"Nothing results from your $ving."
END VERB.


SYNONYMS scream, yell = shout.



-- ==============================================================


----- SHOW


-- ==============================================================


SYNTAX 'show' = 'show' (obj) 'to' (act)
		WHERE obj ISA THING
			ELSE "That's not something you can show."
		AND act ISA ACTOR
			ELSE 
				IF act IS NOT plural
					THEN "That's not"
					ELSE "Those are not"
				END IF.
				"something you can show things to."


ADD TO EVERY THING
  VERB 'show'
	WHEN obj
	CHECK obj IN hero
		ELSE "You don't have" SAY THE obj. "."
	AND act <> hero 
		ELSE "It doesn't make sense to show something to yourself."
	AND obj <> act
		ELSE "It doesn't make sense to show something to itself."
	AND CURRENT LOCATION IS lit
		ELSE "It is too dark to see."
	DOES 
		SAY THE act. 
			IF act IS NOT plural
				THEN "is"
				ELSE "are"
			END IF.
			"not especially interested."
  END VERB.
END ADD TO.


SYNONYMS reveal = 'show'.



-- ==============================================================


----- SING (+ hum, whistle)


-- ==============================================================


SYNTAX sing = sing.


VERB sing
  DOES
    	"You $v a little tune."
END VERB.


SYNONYMS hum, whistle = sing.



-- ==============================================================


----- SIP 
	

-- ==============================================================


SYNTAX sip = sip (liq)
		WHERE liq ISA LIQUID
			ELSE 
				IF liq IS NOT plural
					THEN "That's not"
					ELSE "Those are not"
				END IF.
				"something you can drink."


ADD TO EVERY LIQUID
  VERB sip
	CHECK liq IS drinkable
		ELSE 
			IF liq IS NOT plural
				THEN "That's not"
				ELSE "Those are not"
			END IF.
			"something you can drink."
	AND CURRENT LOCATION IS lit
		ELSE "It is too dark to see."
	AND liq IS reachable
		ELSE SAY THE liq. 
			IF liq IS NOT plural
				THEN "is" 
				ELSE "are"
			END IF.
			"out of your reach."
	DOES	
		IF vessel OF liq = no_vessel		-- here, if the liquid is in no container, e.g.
								-- the hero takes a sip of water from a river,
								-- the action is allowed to succeed.
			THEN "You take a sip of" SAY THE liq. "."
			ELSE 
				-- implicit taking:
				IF vessel OF liq NOT DIRECTLY IN hero
					THEN 
						IF vessel OF liq IS NOT takeable
							THEN "It's not worth the bother trying to take a sip of" SAY THE liq. "."
							ELSE LOCATE vessel OF liq IN hero.
								"(taking" SAY THE vessel OF liq. "first)$n"
						END IF.
				END IF.
				-- end of implicit taking.
		END IF.		

		IF liq IN hero		-- i.e. if the implicit taking was successful
		 	THEN "You take a sip of" SAY THE liq. "."
		END IF.
			
  END VERB.
END ADD TO.


-- See also the verb 'drink'.


-- ==============================================================


----- SIT


-- ==============================================================


SYNTAX sit = sit.
	 
 
       sit = sit 'down'.


VERB sit 
	CHECK hero IS NOT sitting
		ELSE "You're sitting down already."
	DOES 
		"You feel no urge to sit down at present."
		-- (or, if you wish to make it work, use the following instead of the above:
		-- IF hero IS lying_down
		--	THEN "You sit up."
		--		MAKE hero NOT lying_down.
		-- 	ELSE "You sit down."
		-- END IF.
		-- MAKE hero sitting.
END VERB.

-- When the hero is sitting or lying down, it will be impossible for her/him to
-- perform certain actions, as numerous verbs in the library have checks for this. 
-- For example, if the hero is sitting and the player types 'attack [something]',
-- the response will be "It will be difficult to attack anything while
-- sitting down." 
-- Also, it is often essential to make certain objects NOT reachable when
-- sitting or lying down.



-- ==============================================================


----- SIT_ON


-- ==============================================================


SYNTAX sit_on = sit 'on' (surface)
		WHERE surface ISA SUPPORTER
			ELSE 
				IF surface IS NOT plural
					THEN "That's not"
					ELSE "Those are not"
				END IF.
				"something you can sit on."


ADD TO EVERY SUPPORTER
  VERB sit_on
	CHECK hero IS NOT sitting
		ELSE "You're sitting down already."
	AND CURRENT LOCATION IS lit
		ELSE "It is too dark to see."
	DOES 
		"You feel no urge to sit down at present."
		-- (or, to make it work, use the following instead of the above:)
		-- IF hero lying_down 
		-- 	THEN "You get up and sit down on" SAY THE surface. "."
		--		MAKE hero NOT lying_down.
		--	ELSE "You sit down on" SAY THE surface. "."
		-- END IF.
		-- LOCATE hero IN surface.
		-- MAKE hero sitting.
  END VERB.
END ADD TO.


-- When the hero is sitting or lying down, it will be impossible for her/him to
-- perform certain actions, as numerous verbs in the library have checks for this. 
-- For example, if the hero is sitting and the player types 'attack [something]',
-- the response will be "It will be difficult to attack anything while
-- sitting down." 
-- Also, it is often essential to make certain objects NOT reachable when
-- sitting or lying down.



-- ==============================================================


----- SLEEP	(+ rest)


-- ==============================================================


SYNTAX sleep = sleep.


VERB sleep
	DOES 
		"There's no need to $v right now."
END VERB.


SYNONYMS rest = sleep.



-- ==============================================================


----- SMELL (smell0)


-- ==============================================================


SYNTAX smell0 = smell.


VERB smell0
    DOES
		"You smell nothing unusual."
END VERB.



-- ==============================================================


----- SMELL (+ obj)


-- ==============================================================


SYNTAX smell = smell (odour)!
		WHERE odour ISA THING
	    		ELSE "That's not something you can smell."


ADD TO EVERY THING
  VERB smell
	DOES 
	    	"You smell nothing unusual."	
  END VERB.
END ADD TO.



-- ==============================================================


----- SQUEEZE


-- ==============================================================


SYNTAX squeeze = squeeze (obj)
		WHERE obj ISA THING
	    		ELSE "That's not something you can squeeze."


ADD TO EVERY THING
    VERB squeeze
	CHECK obj IS examinable
		ELSE IF obj IS NOT plural
				THEN "That's not"
				ELSE "Those are not"
			END IF.
			"something you can squeeze."
	AND CURRENT LOCATION IS lit
		ELSE 
			IF obj = hero
				THEN "Nothing would be achieved by that."  
					-- you can squeeze yourself in the dark, as well
				ELSE "It is too dark to see."
			END IF.
	AND obj IS reachable
			ELSE SAY THE obj. 
				IF obj IS NOT plural
					THEN "is" 
					ELSE "are"
				END IF.
				"out of your reach."	
	
	DOES
	    	IF obj ISA ACTOR
			THEN "That wouldn't be polite."
			ELSE "Trying to squeeze" SAY THE obj. "wouldn't be sensible."
		END IF.
    END VERB.
END ADD TO.



-- ==============================================================


----- STAND


-- ==============================================================


SYNTAX stand = stand.

	
	 stand = stand 'up'.


VERB stand
	CHECK hero IS NOT lying_down
		ELSE "You get up."
			MAKE hero NOT lying_down.
	AND hero IS NOT sitting
		ELSE "You stand up."
			MAKE hero NOT sitting. 
	DOES 
		"You're standing up already."
END VERB.



-- ==============================================================


----- STAND_ON


-- ==============================================================


SYNTAX stand_on = stand 'on' (surface)
		WHERE surface ISA SUPPORTER
			ELSE 
				IF surface IS NOT plural
					THEN "That's not"
					ELSE "Those are not"
				END IF.
				"something you can stand on."


       stand_on = get 'on' (surface).  


ADD TO EVERY SUPPORTER
VERB stand_on
	CHECK CURRENT LOCATION IS lit
		ELSE "It is too dark to see."
	DOES 
		"You feel no urge to stand on" SAY THE surface. "."
		-- or, to make it work, use the following instead of the above:
		-- "You get on" SAY THE surface. "."
		-- LOCATE hero IN surface.
		-- MAKE hero NOT sitting. MAKE hero NOT lying_down.
END VERB.
END ADD TO.



-- ==============================================================


----- SWIM


-- ==============================================================


SYNTAX swim = swim.


VERB swim 
	CHECK hero IS NOT sitting
		ELSE "It is difficult to try swimming while sitting down."
	AND hero IS NOT lying_down
		ELSE "It is difficult to try swimming while lying down."
	AND CURRENT LOCATION IS lit
		ELSE "It is too dark to see."
	DOES 
		"There is no water suitable for swimming here."
END VERB.



-- ==============================================================


----- SWIM IN


-- ==============================================================


SYNTAX swim_in = swim 'in' (liq)
		WHERE liq ISA LIQUID
			ELSE 
				IF liq IS NOT plural
					THEN "That's not"
					ELSE "Those are not"
				END IF.
				"something you can swim in."



ADD TO EVERY OBJECT
VERB swim_in
	CHECK hero IS NOT sitting
		ELSE "It is difficult to swim anywhere while sitting down."
	AND hero IS NOT lying_down
		ELSE "It is difficult to swim anywhere while lying down."
	AND CURRENT LOCATION IS lit
		ELSE "It is too dark to see."
	DOES 
		IF liq IS NOT plural
			THEN "That's not"
			ELSE "Those are not"
		END IF.
		"something you can swim in."
END VERB.
END ADD TO.



-- ==============================================================


----- SWITCH 


-- ==============================================================


-- This is a mere 'switch' verb with no 'on' or 'off' following after it. 
-- This verb is defined further in 'classes.i', under 'device' and 'lightsource'.
-- This verb exists just to cover cases where the player forgets to write
-- 'on' or 'off' after 'switch'. 
-- If the player types 'switch tv', the tv object will be switched on 
-- if it is off, and vice cersa.
-- Below, just the basic syntax is declared.



SYNTAX switch = switch (app)			-- = apparatus, appliance
	WHERE app ISA THING 
		ELSE "That's not something you can switch."
   
     
ADD TO EVERY THING
	VERB switch
		DOES 
			IF app IS NOT plural
				THEN "That's not"
				ELSE "Those are not"
			END IF.
			"not something you can switch."
	END VERB.
END ADD TO.



-- ==============================================================


----- SWITCH ON


-- ==============================================================

	
----- The syntax for 'switch on' has been declared in the 'turn_on' verb.




-- ==============================================================


----- SWITCH OFF


-- ==============================================================


----- The syntax for 'switch off' has been declared in the 'turn_off' verb.




-- ==============================================================


----- TAKE	(+ carry, get, grab, hold, obtain, pick up)


-- ==============================================================


SYNTAX take = take (obj)
    		WHERE obj ISA OBJECT
      		ELSE 
				IF obj ISA ACTOR
					THEN 
						IF obj = hero
							THEN "Taking yourself is not possible."
							ELSE SAY THE obj. "would probably object to that."
						END IF.
					ELSE "That's not something you can take."
				END IF.


	take = get (obj).


  	take = pick up (obj).


  	take = pick (obj) up.


ADD TO EVERY OBJECT
  VERB take
	CHECK CURRENT LOCATION IS lit
		ELSE "It is too dark to see."
    	AND obj IS takeable
      	ELSE 
			IF obj ISA SCENERY
				THEN "Unimportant for your purposes, you leave the" SAY THE obj. "where it is."
				ELSE 
					IF obj IS NOT plural
						THEN "That's not"
						ELSE "Those are not"
					END IF.
					"something you can take."
			END IF.
    	AND obj IS movable
		ELSE SAY THE obj. 
			IF obj IS NOT plural
				THEN "is"
				ELSE "are"
			END IF.
			"much too heavy for you to move."
    	AND obj IS inanimate
		ELSE SAY THE obj. "would probably object to that."
    	AND obj IS reachable
		ELSE SAY THE obj. 
			IF obj IS NOT plural
				THEN "is" 
				ELSE "are"

			END IF.
			"out of your reach."
    	AND weight Of obj <=50					
      	ELSE SAY THE obj. "is too heavy to lift."
    	DOES
		IF obj DIRECTLY IN hero			
			-- i.e. the object to be taken is carried by the hero already						
			THEN "You already have" SAY THE obj. "."  	
		ELSIF obj DIRECTLY IN worn		
			-- i.e. the object to be taken is a piece of clothing that the player character is wearing;
			 -- here, this verb works in practise like 'take off'. 
			THEN "You take off" SAY THE obj. "and carry" 
				IF obj IS NOT plural
					THEN "it"
					ELSE "them"
				END IF.		
				"in your hands."
				LOCATE obj IN hero.		
		ELSE "Taken."				
			-- this covers also cases where the object to be taken is in another container,
			 -- such as a wallet that is in a jacket the hero is carrying or wearing.
			LOCATE obj IN hero.		
		END IF.			
  END VERB.
END ADD TO.


SYNONYMS
  carry, grab, hold, obtain = take.



-- ==============================================================


-----  TAKE FROM


-- ==============================================================


SYNTAX take_from = 'take' (obj) 'from' (holder)
    		WHERE obj ISA OBJECT
      		ELSE "You can only take objects."
    		AND holder ISA THING
      		ELSE "It's not possible to take things from there."
    		AND holder ISA CONTAINER
      		ELSE "It's not possible to take things from there."


 	 take_from = remove (obj)* 'from' (holder).

 
	 take_from = get (obj) 'from' (holder).


ADD TO EVERY OBJECT
  VERB take_from
    WHEN obj
	CHECK holder <> hero
		ELSE "You can't take things from yourself."
      AND obj NOT IN hero 		
	  	ELSE	"You already have" SAY THE obj. "."
	AND obj <> holder
		ELSE "You can't take something from itself."
	AND CURRENT LOCATION IS lit
		ELSE "It is too dark to see."
      AND obj IN holder
		ELSE
			IF obj ISA CLOTHING    -- A piece of clothing worn by an NPC is not *in* the NPC but in a special
						     -- npc_worn container (see 'classes.i', class 'actor'). We need to take the class 'clothing' separately
						     -- into account here.
				THEN		     -- Here, we allow the piece of clothing to be taken if it is takeable, skipping the remaining checks below.	
					FOR EACH nw ISA NPC_WORN DO
						IF carrier OF nw <> no_carrier
							THEN 
								IF obj IS takeable
									THEN LOCATE obj IN hero.
									    "You take" SAY THE obj. "from" SAY THE holder. "."
									ELSE 
							       		IF THIS IS NOT plural
											THEN "That's"
											ELSE "Those are"
										END IF.
										"not something you can take."
								END IF.	
						END IF.
					END FOR.
			ELSIF holder IS inanimate
	  			THEN SAY THE obj. 
					IF obj IS NOT plural
						THEN "is not"
						ELSE "are not"
					END IF.
						IF holder ISA SUPPORTER 
							THEN "on"
							ELSE "in" 
						END IF.
					SAY THE holder. "."
				ELSE SAY THE holder. 
					IF holder IS NOT plural
						THEN "doesn't"
						ELSE "don't"
					END IF.
					"have" SAY THE obj. "."
			END IF.
	AND obj IS reachable
		ELSE SAY THE obj. 
			IF obj IS NOT plural
				THEN "is" 
				ELSE "are"
			END IF.
			"out of your reach."
	AND holder IS NOT closed
		ELSE "You can't, since" SAY THE holder. 
			IF holder IS NOT plural
				THEN "is"
				ELSE "are"
			END IF.
			"closed."
	AND obj IS movable
		ELSE SAY THE obj. 
			IF obj IS NOT plural
					THEN "is"
					ELSE "are"
				END IF.
			"much too heavy for you to take."
	AND obj IS takeable
      	ELSE 
			IF obj ISA SCENERY
				THEN "Unimportant for your purposes, you leave" 
					SAY THE obj. "where" 
					IF obj IS NOT plural
						THEN "it is."
						ELSE "they are."
					END IF.
				ELSE 
					IF obj IS NOT plural
						THEN "That's not"
						ELSE "Those are not"
					END IF.
					"something you can take."
			END IF.
	AND weight Of obj <=50
      	ELSE SAY THE obj. 
			IF obj IS NOT plural
				THEN "is"
				ELSE "are"
			END IF.
			"too heavy."
	DOES
		LOCATE obj IN hero.
	    	"You take" SAY THE obj. "from" SAY THE holder. "."	
  END VERB.
END ADD TO.



-- ==============================================================


----- TALK


-- ==============================================================


SYNTAX talk = talk.


VERB talk
	DOES 
		"To talk to somebody, you can ASK PERSON ABOUT THING
		or TELL PERSON ABOUT THING."
END VERB.



-- ==============================================================


----- TALK_TO



-- ==============================================================


SYNTAX talk_to = talk 'to' (act) 
    		WHERE act ISA ACTOR
      		ELSE 
				IF act IS NOT plural
					THEN "That's not"
					ELSE "Those are not"
				END IF.
				"something you can talk to."
  

ADD TO EVERY ACTOR
  VERB talk_to
	DOES 
		"To talk to somebody, you can ASK PERSON ABOUT THING or
		TELL PERSON ABOUT THING."
  END VERB.
END ADD TO.


SYNTAX talk_to_a = talk 'to' (act) about (topic)!
    		WHERE act ISA ACTOR
      		ELSE 
				IF act IS NOT plural
					THEN "That's not"
					ELSE "Those are not"
				END IF.
				"something you can talk to."
		AND topic ISA THING
		      ELSE "That's not something you can talk about."
      

ADD TO EVERY ACTOR
  VERB talk_to_a
	WHEN act
		DOES 
			"To talk to somebody, you can ASK PERSON ABOUT THING or
  			TELL PERSON ABOUT THING."
  END VERB.
END ADD TO.


-- ==============================================================


----- TASTE		(+ lick)


-- ==============================================================


SYNTAX taste = taste (obj)
		WHERE obj ISA OBJECT
			ELSE 
				IF obj IS NOT plural
					THEN "That's not"
					ELSE "Those are not"
				END IF.
				"something you can taste."


ADD TO EVERY OBJECT
  VERB taste
	CHECK obj IS examinable
		ELSE 
			IF obj IS NOT plural
				THEN "That's not"
				ELSE "Those are not"
			END IF.
			"something you can taste."
	AND CURRENT LOCATION IS lit
		ELSE "It is too dark to see."
	AND obj IS reachable
		ELSE SAY THE obj. 
			IF obj IS NOT plural
				THEN "is" 
				ELSE "are"
			END IF.
			"out of your reach."
	DOES "You taste nothing unexpected."
  END VERB.
END ADD TO. 	



-- ==============================================================


----- TEAR	(+ rip)


-- ==============================================================


SYNTAX tear = tear (obj)
		WHERE obj ISA OBJECT
			ELSE 
				IF obj IS NOT plural
					THEN "That's not"
					ELSE "Those are not"
				END IF.
				"something you can tear."


ADD TO EVERY OBJECT
  VERB tear
	CHECK obj IS examinable
		ELSE 
			IF obj IS NOT plural
				THEN "That's not"
				ELSE "Those are not"
			END IF.
			"something you can tear."
	AND CURRENT LOCATION IS lit
		ELSE "It is too dark to see."
	AND obj IS reachable
		ELSE SAY THE obj. 
			IF obj IS NOT plural
				THEN "is" 
				ELSE "are"
			END IF.
			"out of your reach."
	DOES 
		"That would be futile."
  END VERB.
END ADD TO.


SYNONYMS rip = tear.



-- ==============================================================


----- TELL 	(+ enlighten, inform)


-- ==============================================================


SYNTAX tell = tell (act) about (topic)!
    		WHERE act ISA ACTOR
      		ELSE 
				IF act IS NOT plural
					THEN "That's not"
					ELSE "Those are not"
				END IF.
				"something you can talk to."
    		AND topic ISA THING
      		ELSE "That doesn't seem to be something you can talk
			      about with" SAY THE act. "."


ADD TO EVERY ACTOR
  VERB tell
    WHEN act
      CHECK act CAN talk
        	ELSE 
			IF act IS NOT plural
				THEN "That's not"
				ELSE "Those are not"
			END IF.
			"something you can talk to."
	AND act IS reachable
		ELSE SAY THE act. 
			IF act IS NOT plural
				THEN "is" 
				ELSE "are"
			END IF.
			"too far away."
	AND act <> hero
		ELSE "It doesn't make much sense to tell yourself about something."
      DOES
		IF topic IN act
			THEN SAY THE act. 
				IF act IS NOT plural
					THEN "doesn't"
					ELSE "don't"
				END IF.
				"seem to want to talk about" SAY THE topic. "."
	      ELSIF topic = act
			THEN SAY THE act. 
				IF act IS NOT plural
					THEN "chooses"
					ELSE "choose"
				END IF.
				"to be silent."
		ELSIF topic = hero
			THEN SAY THE act. 
				IF act IS NOT plural
					THEN "doesn't"
					ELSE "don't"
				END IF.
				"look interested."
		ELSE SAY THE act. 
				IF act IS NOT plural
					THEN "doesn't"
					ELSE "don't"
				END IF.
				"look interested."
		END IF.
  END VERB.
END ADD TO.


SYNONYMS enlighten, inform = tell.



-- ==============================================================


----- THINK		(+ ponder, meditate, reflect)


-- ==============================================================


SYNTAX think = think.


VERB think 
	DOES 
		"Nothing helpful comes to your mind."
END VERB.


SYNONYMS ponder, meditate, reflect = think.



-- ==============================================================


----- THINK ABOUT


-- ==============================================================


SYNTAX think_about = think 'about' (topic)!
		WHERE topic ISA THING
			ELSE "That's not something fruitful to think about."


ADD TO EVERY THING
  VERB think_about
	DOES 
		"Nothing helpful comes to your mind."
  END VERB.
END ADD TO.



-- ==============================================================


----- THROW   


-- ==============================================================


SYNTAX throw = throw (projectile) 
		WHERE projectile ISA OBJECT
			ELSE 
				IF projectile IS NOT plural
					THEN "That's not"
					ELSE "Those are not"
				END IF.
				"something you can throw."


ADD TO EVERY OBJECT
  VERB throw
	CHECK projectile IS examinable
		ELSE 
			IF projectile IS NOT plural
				THEN "That's not"
				ELSE "Those are not"
			END IF.
			"something you can throw."
	AND projectile IS takeable
		ELSE "You don't have" SAY THE projectile. "."
	AND CURRENT LOCATION IS lit
		ELSE "It is too dark to see."
	AND projectile IS reachable
		ELSE SAY THE projectile. 
			IF projectile IS NOT plural
				THEN "is" 
				ELSE "are"
			END IF.
			"out of your reach."
	DOES
		-- implicit taking:
		IF projectile NOT DIRECTLY IN hero
			THEN  "(taking" SAY THE projectile. "first)$n"
			LOCATE projectile IN hero.
		END IF.
		-- end of implicit taking.
				
		"You can't throw very far;" SAY THE projectile. 
			IF projectile IS NOT plural
				THEN "ends up"
				ELSE "end up"
			END IF.
			"on the"
			IF floor HERE
				THEN "floor"
				ELSE "ground"
			END IF.
		"nearby."
	    	LOCATE projectile AT hero.
			
  END VERB.
END ADD TO.




-- ==============================================================


----- THROW AT 	


-- ==============================================================


SYNTAX throw_at = throw (projectile) 'at' (target)
       	 WHERE projectile ISA OBJECT
	    		ELSE "You can only throw objects."
	  	 AND target ISA THING
	    		ELSE "It's not possible to throw things at that."



ADD TO EVERY OBJECT
  VERB throw_at
    WHEN projectile
	    CHECK projectile IS examinable
			ELSE 
				IF projectile IS NOT plural
					THEN "That's not"
					ELSE "Those are not"
				END IF.
				"something you can throw."
	    AND projectile IS takeable
		  	ELSE "You don't have" SAY THE projectile. "."
	    AND target IS examinable
		  	ELSE 
				IF target IS NOT plural
					THEN "That's not"
					ELSE "Those are not"
				END IF.
				"something you can throw things at."
	    AND projectile <> target
			ELSE "It doesn't make sense to throw something at itself."
	    AND target NOT IN hero
	        	ELSE "You are carrying" SAY THE target. "."
	    AND target <> hero
		   	ELSE "You cannot throw things at yourself."
	    AND CURRENT LOCATION IS lit
			ELSE "It is too dark to see."
	    AND projectile IS reachable
		  	ELSE SAY THE projectile. 
			IF projectile IS NOT plural
				THEN "is" 
				ELSE "are"
			END IF.
			"out of your reach."
	    DOES 
			-- implicit taking:
		  	IF projectile NOT DIRECTLY IN hero
				THEN  "(taking" SAY THE projectile. "first)$n"
					LOCATE projectile IN hero.
		  	END IF.
			-- end of implicit taking.

      	  	IF target IS inanimate
				THEN 
					IF target NOT DIRECTLY AT hero		-- e.g. the target is inside a box
						THEN "It wouldn't accomplish anything trying to throw something at" SAY THE target. "."
						ELSE 
							SAY THE projectile. 
								IF projectile IS NOT plural
									THEN "bounces"
									ELSE "bounce"
								END IF.
								"harmlessly off" 
							SAY THE target. "and"
								IF projectile IS NOT plural
									THEN "ends up"
									ELSE "end up"
								END IF.
								"on the"
		  						IF floor HERE
									THEN "floor"
									ELSE "ground"
		  						END IF.
		     					"nearby."
		  					LOCATE projectile HERE.
					END IF.
				ELSE "You throw" SAY THE projectile. "at" SAY THE target. "who" 
						IF target IS NOT plural
							THEN "ducks"
							ELSE "duck"
						END IF.	
						"just in time."
						SAY THE projectile. 
							 IF projectile IS NOT plural
								THEN "ends up"
								ELSE "end up"
							END IF.
						 "on the"
						 IF floor HERE
							THEN "floor"
							ELSE "ground"
		  				 END IF.
						 "."
					LOCATE projectile HERE.
		  	END IF.

  END VERB.
END ADD TO.



-- ==============================================================


----- THROW TO 	


-- ==============================================================


SYNTAX throw_to = throw (projectile) 'to' (recipient)
      	  WHERE projectile ISA OBJECT
	    		ELSE "You can only throw objects."
	  	  AND recipient ISA THING
	   		ELSE "It's not possible to throw things to that."
		  AND recipient ISA CONTAINER
			ELSE "It is not possible to throw things to that."


ADD TO EVERY OBJECT
  VERB throw_to
    WHEN projectile
	    CHECK projectile IS examinable
			ELSE 
				IF projectile IS NOT plural
					THEN "That's not"
					ELSE "Those are not"
				END IF.
				"something you can throw."
	    AND projectile IS takeable
		  	ELSE "You don't have" SAY THE projectile. "."
	    AND recipient IS examinable
		  	ELSE 
				IF recipient IS NOT plural
					THEN "That's not"
					ELSE "Those are not"
				END IF.
				"something you can throw things at."
	    AND projectile <> recipient
			ELSE "It doesn't make sense to throw something at itself."
	    AND recipient NOT IN hero
	        	ELSE "You are carrying" SAY THE recipient. "."
	    AND recipient <> hero
		   	ELSE "You cannot throw things at yourself."
	    AND CURRENT LOCATION IS lit
			ELSE "It is too dark to see."
	    AND projectile IS reachable
	    		ELSE SAY THE projectile. 
				IF projectile IS NOT plural
					THEN "is" 
					ELSE "are"
				END IF.
				"out of your reach."
	    AND recipient IS reachable
		  	ELSE SAY THE recipient. 
				IF recipient IS NOT plural
					THEN "is" 
					ELSE "are"
				END IF.
				"out of your reach."
	    DOES 
			-- implicit taking:
		  	IF projectile NOT DIRECTLY IN hero
				THEN  "(taking" SAY THE projectile. "first)$n"
					LOCATE projectile IN hero.
		  	END IF.
			-- end of implicit taking.

      	  	IF recipient IS inanimate
				THEN 
					IF recipient NOT DIRECTLY AT hero		-- e.g. the recipient is inside a box
						THEN "It wouldn't accomplish anything trying to throw something at" SAY THE recipient. "."
						ELSE 
							SAY THE projectile.
								IF projectile IS NOT plural
									THEN "bounces"
									ELSE "bounce"
								END IF.
							"harmlessly off" 
							SAY THE recipient. "and" 
								IF projectile IS NOT plural
									THEN "ends up"
									ELSE "end up"
								END IF.
								"on the"
		  						IF floor HERE
									THEN "floor"
									ELSE "ground"
		  						END IF.
		     					"nearby."
		  					LOCATE projectile HERE.
					END IF.
				ELSE "You throw" SAY THE projectile. "to" SAY THE recipient. "who"
						 IF recipient IS NOT plural
							THEN "catches"
							ELSE "catch"
							END IF.
						 IF projectile IS plural
							THEN "them."
							ELSE "it."
						 END IF.
					LOCATE projectile IN recipient.
		  	END IF.

  END VERB.
END ADD TO.



-- ==============================================================


------ THROW IN


-- ==============================================================


SYNTAX throw_in = throw (projectile) 'in' (cont)
		WHERE projectile ISA OBJECT
	    		ELSE 
				IF projectile IS NOT plural
					THEN "That's not"
					ELSE "Those are not"
				END IF.
				"something you can throw."
		AND cont ISA OBJECT
	    		ELSE 
				IF cont IS NOT plural
					THEN "That's not"
					ELSE "Those are not"
				END IF.
				"something you can throw things into."
		AND cont ISA CONTAINER
	    		ELSE 
				IF cont IS NOT plural
					THEN "That's not"
					ELSE "Those are not"
				END IF.
				"something you can throw things into."


ADD TO EVERY OBJECT
  VERB throw_in
    WHEN projectile
          CHECK projectile IS examinable
		  ELSE 
			IF projectile IS NOT plural
				THEN "That's not"
				ELSE "Those are not"
			END IF.
			"something you can throw."
	    AND projectile IS takeable
		  ELSE "You don't have" SAY THE projectile. "."
	    AND cont IS examinable
		  ELSE 
			IF cont IS NOT plural
				THEN "That's not"
				ELSE "Those are not"
			END IF.
			"something you can throw things into."
	    AND projectile <> cont
		ELSE "It doesn't make sense to throw something into itself."
	    AND cont <> hero
	        ELSE "You can't throw" SAY THE projectile. "into yourself."
	    AND CURRENT LOCATION IS lit
		  ELSE "It is too dark to see."
	    AND projectile NOT IN cont
		  ELSE SAY THE projectile. 
				IF projectile IS NOT plural
					THEN "is"
					ELSE "are"
				END IF.
				"in" SAY THE cont. "already."
	    AND projectile IS reachable
		  ELSE SAY THE projectile. 
			IF projectile IS NOT plural
				THEN "is" 
				ELSE "are"
			END IF.
			"out of your reach."
	    AND cont IS reachable
		  ELSE SAY THE cont. 
			IF cont IS NOT plural
				THEN "is" 
				ELSE "are"
			END IF.
			"out of your reach."
	    AND cont IS NOT closed
		  ELSE "You can't, since" SAY THE cont. 
				IF cont IS NOT plural
					THEN "is"
					ELSE "are"
				END IF.
				"closed."
	    DOES
		  "You can't throw" SAY THE projectile. "into" SAY THE cont. "."

		  -- To make it work, define:
	
		  -- implicit taking:
		  -- IF obj NOT DIRECTLY IN hero
		  --	THEN  "(taking" SAY THE obj. "first)$n"
		  --		LOCATE obj IN hero.
		  -- END IF.
		  -- end of implicit taking.

		  -- LOCATE obj IN cont.
		  -- "You throw" SAY THE obj. "into" SAY THE cont. "."
				
  END VERB.
END ADD TO.



-- ==============================================================


----- TIE


-- ==============================================================


SYNTAX tie = tie (obj) 
		WHERE obj ISA OBJECT
			ELSE 
				IF obj IS NOT plural
					THEN "That's not"
					ELSE "Those are not"
				END IF.
				"something you can tie."


ADD TO EVERY OBJECT
  VERB tie
	DOES 

		"You must state where do you want to tie" SAY obj. "."
  END VERB.
END ADD TO.



-- ==============================================================


----- TIE TO


-- ==============================================================


SYNTAX tie_to = tie (obj) 'to' (target)
		WHERE obj ISA OBJECT
			ELSE 
				IF obj IS NOT plural
					THEN "That's not"
					ELSE "Those are not"
				END IF.
				"something you can tie."
		AND target ISA OBJECT
			ELSE "Nothing can be tied to"
				IF target IS NOT plural
					THEN "that."
					ELSE "those."
				END IF.



ADD TO EVERY OBJECT
  VERB tie_to
	WHEN obj
	CHECK obj IS examinable
		  ELSE 
			IF obj IS NOT plural
				THEN "That's not"
				ELSE "Those are not"
			END IF.
			"something you can tie."
	AND target IS examinable
		  ELSE 
			IF target IS NOT plural
				THEN "That's not"
				ELSE "Those are not"
			END IF.
			"something you can tie things to."
	AND obj IS takeable
		  ELSE "You don't have" SAY THE obj. "." 
	AND obj <> target
		ELSE "It doesn't make sense to tie something to itself."
	AND CURRENT LOCATION IS lit
		ELSE "It is too dark to see."
	AND obj IS reachable
		ELSE SAY THE obj. 
			IF obj IS NOT plural
				THEN "is" 
				ELSE "are"
			END IF.
			"out of your reach."
	AND target IS reachable
		  ELSE SAY THE target. 
			IF target IS NOT plural
				THEN "is" 
				ELSE "are"
			END IF.
			"out of your reach."
	DOES 
		-- implicit taking:
		IF obj NOT DIRECTLY IN hero
			THEN  "(taking" SAY THE obj. "first)$n"
				LOCATE obj IN hero.
		END IF.
		-- end of implicit taking.
						
		LOCATE obj IN hero.
		"It's not possible to tie" SAY THE obj. "to" SAY THE target. "."	

  END VERB.
END ADD TO.



-- ==============================================================


----- TOUCH


-- ==============================================================


SYNTAX touch = touch (obj)
		WHERE obj ISA THING
	    		ELSE "That's not something you can touch."
    

ADD TO EVERY THING
  VERB touch
        CHECK obj IS examinable
            ELSE 
			IF obj IS NOT plural
				THEN "That's not"
				ELSE "Those are not"
			END IF.
			"something you can touch."
	  AND obj IS reachable
		ELSE SAY THE obj. 
			IF obj IS NOT plural
				THEN "is" 
				ELSE "are"
			END IF.
			"out of your reach."
	  AND obj <> hero
		ELSE "That wouldn't accomplish anything."
	  AND obj IS inanimate
		ELSE "You are not sure whether" SAY THE obj. "would appreciate that."
        DOES
	      "You feel nothing unexpected."
  END VERB.
END ADD TO.


SYNONYMS feel = touch.



-- ==============================================================


----- TOUCH WITH


-- ==============================================================


SYNTAX touch_with = touch (obj) 'with' (instr)
	WHERE obj ISA THING
   		ELSE "That's not something you can touch."
	AND instr ISA OBJECT
	    	ELSE "You can only use objects to touch with."


ADD TO EVERY THING
  VERB touch_with
	WHEN obj
	    CHECK obj IS examinable
	        ELSE 
			IF obj IS NOT plural
				THEN "That's not"
				ELSE "Those are not"
			END IF.
			"something you can touch."
	    AND instr IS examinable
		  ELSE 
			IF instr IS NOT plural
				THEN "That's not"
				ELSE "Those are not"
			END IF.
			"something you can touch things with."
	    AND obj <> instr
		ELSE "You can't touch something with itself."
	    AND instr <> hero
		ELSE "That doesn't make sense."
	    AND instr IN hero
		  ELSE "You don't have" SAY THE instr. "."
	    AND obj IS inanimate
		  ELSE "You are not sure whether" SAY THE obj. "would appreciate that."
	    AND CURRENT LOCATION IS lit
		  ELSE "It is too dark to see."
	    AND obj IS reachable
		  ELSE SAY THE obj. 
			IF obj IS NOT plural
				THEN "is" 
				ELSE "are"
			END IF.
			"out of your reach."
	    DOES
	        "You touch" SAY THE obj. "with" SAY THE instr. ". Nothing special happens."
  END VERB.
END ADD TO.



-- ==============================================================


----- TURN	(+ rotate)


-- ==============================================================


SYNTAX turn = turn (obj)
		WHERE obj ISA OBJECT
			ELSE 
				IF obj IS NOT plural
					THEN "That's not"
					ELSE "Those are not"
				END IF.
				"something you can turn."


       turn = rotate (obj).   -- we don't declare 'rotate' a synonym for 'turn'
				     -- through a SYNONYMS statement as we don't want
				     -- it to be possible for the player to type something
				     -- like 'rotate tv on' (see 'turn on' and 'turn off' below)


ADD TO EVERY OBJECT
  VERB turn
	CHECK obj IS examinable
		ELSE 
			IF obj IS NOT plural
				THEN "That's not"
				ELSE "Those are not"
			END IF.
			"something you can turn."
	AND obj IS movable
		ELSE "It's not possible to turn" SAY THE obj. "."
	AND CURRENT LOCATION IS lit
		ELSE "It is too dark to see."
	AND obj IS reachable
		ELSE SAY THE obj. 
			IF obj IS NOT plural
				THEN "is" 
				ELSE "are"
			END IF.
			"out of your reach."
	DOES "You turn" SAY THE obj. 
		IF obj IN hero
			THEN "in your hands"
		END IF.
		"$$. You notice nothing unusual about"
			IF obj IS NOT plural
				THEN "it"
				ELSE "them"
			END IF.
		IF obj NOT IN hero
			THEN "and return" 
				IF obj IS NOT plural
					THEN "it"
					ELSE "them"
				END IF.
			"to" 
				IF obj IS NOT plural
					THEN "its"
					ELSE "their"
				END IF.
			"original position"
		END IF.
		"."
  END VERB.
END ADD TO.



-- ==============================================================


----- TURN ON


-- ==============================================================


----- Only devices and lightsources can be turned on and off. These classes are 
----- defined in 'classes.i' with proper checks for 'on' and 'NOT on', 'lit' and 'NOT lit'. 
----- Trying to turn on or off an ordinary object will default here to "That's not 
----- something you can turn on".


SYNTAX turn_on = turn 'on' (app)
		WHERE app ISA OBJECT
	    		ELSE 
				IF app IS NOT plural
					THEN "That's not"
					ELSE "Those are not"
				END IF.
				"something you can $v on."

  	 turn_on = switch 'on' (app).


       turn_on = turn (app) 'on'.


       turn_on = switch (app) 'on'.
		


-- Note that 'switch' is not declared a synonym for 'turn'.
-- This is because 'turn' has also other meanings, e.g. 'turn page' which is
-- not equal with 'switch page'. 
-- A separate 'switch' verb is declared in 'classes.i', classes 'device' and 'lightsource'.
-- This verb merely covers cases where the player forgets (or doesn't bother) to type 'on' or 'off'.



ADD TO EVERY OBJECT
  VERB turn_on
	DOES
		IF app IS NOT plural
			THEN "That's not"
			ELSE "Those are not"
		END IF.
		"something you can $v on."
  END VERB.
END ADD TO.



-- ==============================================================


----- TURN OFF


-- ==============================================================


----- Only devices and lightsources can be turned on and off. These classes 
----- are defined in 'classes.i' with proper checks for 'on' and 'NOT on', 
----- 'lit' and 'NOT lit'. 


SYNTAX turn_off = turn off (app)
		WHERE app ISA OBJECT
	 	   	ELSE 
				IF app IS NOT plural
					THEN "That's not"
					ELSE "Those are not"
				END IF.
				"something you can $v off."

	turn_off = switch off (app).
		

    	turn_off = turn (app) off.
		
      
	turn_off = switch (app) off.
		


-- Note that 'switch' is not declared a synonym for 'turn'.
-- This is because 'turn' has also other meanings, e.g. 'turn page' which is
-- not equal with 'switch page'. 
-- A separate 'switch' verb is declared in 'classes.i', classes 'device' and 'lightsource'.
-- This verb merely covers cases where the player forgets to type 'on' or 'off'.
    	

ADD TO EVERY OBJECT
  VERB turn_off
	DOES
		IF app IS NOT plural
			THEN "That's not"
			ELSE "Those are not"
		END IF.
		"something you can $v off."
  END VERB.
END ADD TO.



-- ==============================================================


----- UNDRESS


-- ==============================================================


-- See the file 'classes.i', class CLOTHING for the definition
-- of this verb.



-- ==============================================================


----- UNLOCK


-- ==============================================================


SYNTAX unlock = unlock (obj)
	 WHERE obj ISA OBJECT
		    ELSE 
				IF obj IS NOT plural
					THEN "That's not"
					ELSE "Those are not"
				END IF.
				"something you can unlock."


ADD TO EVERY OBJECT
  VERB unlock
	CHECK obj IS lockable
	    ELSE 
			IF obj IS NOT plural
				THEN "That's not"
				ELSE "Those are not"
			END IF.
			"something you can unlock."
	AND CURRENT LOCATION IS lit
		ELSE "It is too dark to see."
	AND obj IS locked
	    ELSE 
			IF obj IS NOT plural
				THEN "It is"
				ELSE "They are"
			END IF.
			"already unlocked."
	AND obj IS reachable
		ELSE SAY THE obj. 
			IF obj IS NOT plural
				THEN "is" 
				ELSE "are"
			END IF.
			"out of your reach."
	DOES
	    "You must state what you want to unlock" SAY THE obj. "with."
  END VERB.
END ADD TO.



-- =============================================================


----- UNLOCK WITH


-- =============================================================


SYNTAX unlock_with = unlock (obj) 'with' (key)
		WHERE obj ISA OBJECT
	    		ELSE 
				IF obj IS NOT plural
					THEN "That's not"
					ELSE "Those are not"
				END IF.
				"something you can unlock."
		AND key ISA OBJECT
	    		ELSE "You can't unlock anything with"
				IF key IS NOT plural
					THEN "that."
					ELSE "those."
				END IF.


ADD TO EVERY OBJECT
  VERB unlock_with
        WHEN obj
	    CHECK obj IS lockable
	        ELSE 
			IF obj IS NOT plural
				THEN "That's not"
				ELSE "Those are not"
			END IF.
			"something you can unlock."
	    AND key In hero
		  ELSE "You don't have" SAY THE obj. "."
	    AND obj <> key
		ELSE "It doesn't make sense to unlock something with itself."
	    AND CURRENT LOCATION IS lit
		ELSE "It is too dark to see."
	    AND obj IS locked
		ELSE 
			IF obj IS NOT plural
				THEN "It is"
				ELSE "They are"
			END IF.
			"already unlocked."
	    AND obj IS reachable
		ELSE SAY THE obj. 
			IF obj IS NOT plural
				THEN "is" 
				ELSE "are"
			END IF.
			"out of your reach."
	  DOES
		SAY THE key. 
			IF key IS NOT plural
					THEN "doesn't"
					ELSE "don't"
			END IF.
		"unlock" SAY THE obj. "."
  END VERB.
END ADD TO.



-- ==============================================================


----- USE


-- ==============================================================


SYNTAX 'use' = 'use' (obj)
		WHERE obj ISA OBJECT
			ELSE 
				IF obj IS NOT plural
					THEN "That's not" 
					ELSE "Those are not"
				END IF.
				"something you can use."


ADD TO EVERY OBJECT
  VERB 'use'
	DOES
		"Please be more specific. How do you intend to use"
			IF obj IS NOT plural
				THEN "it?" 
				ELSE "them?"
			END IF.
  END VERB.
END ADD TO.



-- ==============================================================


----- USE WITH


-- ==============================================================


SYNTAX use_with = 'use' (obj) 'with' (instr)
		WHERE obj ISA OBJECT
	    		ELSE "You can only use objects."
		AND instr ISA OBJECT
	    		ELSE "You can only use objects."


ADD TO EVERY OBJECT
  VERB use_with
    WHEN obj
	CHECK obj <> instr
		ELSE "You can't use something with itself."
	DOES 
		"Please be more specific. How do you intend to use them together?"
  END VERB.
END ADD TO.




-- ==============================================================


----- VERBOSE (see also -> BRIEF)


-- ==============================================================


SYNTAX verbose = verbose.


VERB verbose
	DOES
		VISITS 0.
		"Verbose mode is now on. Location descriptions will be 
		always shown in full."
END VERB.



-- ==============================================================


----- WAIT (= z)


-- ==============================================================


SYNTAX 'wait' = 'wait'.


VERB 'wait'
	DOES
		"Time passes..."
END VERB.


SYNONYMS
	z = 'wait'.



-- ==============================================================


----- WEAR


-- ==============================================================


-- See the file 'classes.i', class CLOTHING for the definition
-- of this verb.



-- ==============================================================


----- WHAT AM I


-- ==============================================================


SYNTAX what_am_i = 'what' am i.


VERB what_am_i
	DOES 
		"Maybe examining yourself might help."
END VERB.



-- ==============================================================


----- WHAT IS


-- ==============================================================


SYNTAX what_is = 'what' 'is' (obj)!
		WHERE obj ISA THING
			ELSE 
				IF obj IS NOT plural
					THEN "That's not" 
					ELSE "Those are not"
				END IF.
				"something I know about."
	 
	what_is = 'what' 'are' (obj)!.


ADD TO EVERY THING
  VERB what_is
	DOES 
		"You'll have to find it out yourself."
  END VERB.
END ADD TO.



-- ==============================================================


----- WHERE AM I


-- ==============================================================


SYNTAX where_am_i = 'where' am i.


VERB where_am_i
	DOES 
		LOOK.
END VERB.



-- ==============================================================


----- WHERE IS


-- ==============================================================


SYNTAX where_is = 'where' 'is' (obj)!
		WHERE obj ISA THING
			ELSE 
				IF obj IS NOT plural
					THEN "That's not" 
					ELSE "Those are not"
				END IF.
				"something I know about."

	 where_is = 'where' 'are' (obj)!.


ADD TO EVERY THING
  VERB where_is 
	CHECK obj NOT AT hero
		ELSE 
			IF obj IS NOT plural
				THEN "That's" 
				ELSE "Those are"
			END IF.
			"right here!"
	DOES 
		"You'll have to find it out yourself."
  END VERB.
END ADD TO.



-- ==============================================================


----- WHO AM I


-- ==============================================================


SYNTAX who_am_i = who am i.


VERB who_am_i 
	DOES 
		"Maybe examining yourself might help."
END VERB.



-- ==============================================================


----- WHO IS


-- ==============================================================


SYNTAX who_is = 'who' 'is' (act)!
		WHERE act ISA ACTOR
			ELSE 
				IF act IS NOT plural
					THEN "That's not somebody" 
					ELSE "Those are not anybody"
				END IF.
				"I know."


ADD TO EVERY ACTOR
  VERB who_is
	DOES 
		"You'll have to find it out yourself."
  END VERB.
END ADD TO.



-- ==============================================================


----- WRITE


-- ==============================================================


SYNTAX write = write (txt) 'on' (obj)
		WHERE txt ISA STRING
			ELSE "Please state inside double quotes ("""") 
				what you want to write."
		AND obj ISA OBJECT
			ELSE "Nothing can be written there."
	

	 write = write (txt) 'in' (obj).


ADD TO EVERY OBJECT
  VERB write 
     WHEN obj 
        CHECK obj IS writeable 
		ELSE "Nothing can be written there."
	  AND CURRENT LOCATION IS lit
		ELSE "It is too dark to see."
	  AND obj IS reachable
		ELSE SAY THE obj. 
			IF obj IS NOT plural
				THEN "is" 
				ELSE "are"
			END IF.
			"out of your reach."
	  DOES 	
		 IF text OF obj = ""
					THEN SET text OF obj TO txt.
					ELSE SET text OF obj TO text OF obj + " " + txt. 
		  END IF.
				"You write ""$$" SAY txt. "$$"" on" SAY THE obj. "."
			   	MAKE obj readable.
  END VERB. 
END ADD TO.


-- A couple of other formulations are understood but they guide the player to
-- use the correct syntax:


SYNTAX write_error1 = write 'on' (obj)
	WHERE obj ISA OBJECT
		ELSE "Please use the formulation WRITE ""TEXT"" ON (IN) OBJECT
			to write something."


ADD TO EVERY OBJECT
	VERB write_error1
		DOES "Please use the formulation WRITE ""TEXT"" ON (IN) OBJECT
			to write something."
	END VERB.
END ADD TO.


SYNTAX write_error2 = write.

VERB write_error2 
	DOES "Please use the formulation WRITE ""TEXT"" ON (IN) OBJECT
			to write something."
END VERB.


SYNTAX write_error3 = write (txt)
	WHERE txt ISA STRING
		ELSE "Please use the formulation WRITE ""TEXT"" ON (IN) OBJECT
			to write something."


ADD TO EVERY STRING
	VERB write_error3
		DOES "Please use the formulation WRITE ""TEXT"" ON (IN) OBJECT
			to write something."
	END VERB.
END ADD TO.



-- ================================================================


----- YES


-- ================================================================


SYNTAX yes = yes.


VERB yes 
	DOES "You sound rather positive."
END VERB.



