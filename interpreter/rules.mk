#######################################################################
# This is a set of common rules for building Alan Interpreters
# It is included from Makefile to complement rules and settings
# specific to the host it is run on, set in such files as
# Makefile.thoni, Makefile.cygwin, Makefile.Darwin, also included from
# Makefile
# This file will build a standard command line arun and all unittests
BUILD := $(shell if [ -f ../BUILD_NUMBER ] ; then cat ../BUILD_NUMBER; else echo 0; fi)

CFLAGS	= $(COMPILEFLAGS) $(EXTRA_COMPILER_FLAGS) $(WARNINGFLAGS) -DBUILD=$(BUILD)
LDFLAGS = $(LINKFLAGS)

#######################################################################
# Standard console Arun
ARUNOBJDIR = .arun
ARUNOBJECTS = $(addprefix $(ARUNOBJDIR)/,${ARUNSRCS:.c=.o}) $(ARUNOBJDIR)/alan.version.o

# Dependencies
-include $(ARUNOBJECTS:.o=.d)

# Rule to compile objects to subdirectory
$(ARUNOBJECTS): $(ARUNOBJDIR)/%.o: %.c
	$(CC) $(CFLAGS) $(DEPENDENCY) -o $@ -c $<

$(ARUNOBJDIR):
	@mkdir $(ARUNOBJDIR)

arun: $(ARUNOBJDIR) $(ARUNOBJECTS)
	$(LINK) -o $@ $(LINKFLAGS) $(ARUNOBJECTS) $(LIBS)
	cp $@ ../bin/

#######################################################################
#
# CGreen unit tests
#
# Define
#	CGREEN to something ("yes") to build with cgreen unit tests
#	CGREENINCLUDE so that #include "cgreen/cgreen.h" works if needed
#	CGREENLIB to something to link with (e.g. -lcgreen)

UNITTESTSOBJDIR = .unittests
UNITTESTSOBJECTS = $(addprefix $(UNITTESTSOBJDIR)/,${UNITTESTSSRCS:.c=.o}) $(UNITTESTSOBJDIR)/alan.version.o

# Dependencies, if they exist yet
-include $(UNITTESTSOBJECTS:.o=.d)

# Rule to compile objects to subdirectory
$(UNITTESTSOBJECTS): $(UNITTESTSOBJDIR)/%.o: %.c
	$(CC) $(CFLAGS) -MMD -o $@ -c $<

#Create directory if it doesn't exist
$(UNITTESTSOBJDIR):
	@mkdir $(UNITTESTSOBJDIR)

unittests: CFLAGS += $(CGREENINCLUDE)
unittests: LIBS = $(CGREENLIB) $(ALLOCLIBS)
unittests: $(UNITTESTSOBJDIR) $(UNITTESTSOBJECTS)
	$(LINK) -o $@ $(LINKFLAGS) $(UNITTESTSOBJECTS) $(LIBS)

.PHONY: unit
ifneq ($(CGREEN),yes)
unit:
	echo "No unit tests run, cgreen not available"
else
unit: unittests
	@echo
	@echo "        Unit Tests"
	@echo
	@./unittests
	@echo
	@echo
endif

#######################################################################
.PHONY: clean
clean:
	-rm *.o .*/*.o


###################################################################
#
# Run all tests!
# No tests except unit tests are available
#
.PHONY: test
test: unit


# Extra dependencies for WinGLK case, really needed? How to make them work in subdirs?
readline.o : resources.h
glkstart.o: glkstart.c args.h types.h sysdep.h acode.h main.h \
  glkstart.h glkio.h resources.h utils.h
glkio.o: glkio.c glkio.h
