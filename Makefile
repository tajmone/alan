#######################################################################
# This is the general Makefile for building the Alan System
# It figures out on which host platform (and possibly on which computer)
# it is running and will include specific Makefiles to build on that
# particular host
#
#
include mk/common.mk

all: everything

# Include the correct main Makefile depending on the OS/environment
INCLUDED = true
#
-include Makefile.$(OS)

include Makefile.common

everything: unit build test $(EXTRA_TARGETS)

#######################################################################
# Check to see if we are running on ThoNi's machine, if so include
# special rules
ifeq ($(shell uname -n), thoni64)
-include Makefile.thoni
endif
