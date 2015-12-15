#
# Back end
#
SRC_CC += create.cc scalar_init.c

INC_DIR += $(REP_DIR)/lib/producer

vpath % $(REP_DIR)/lib/producer

LIBS += stdcxx
#
# Shared library
#
SHARED_LIB  = yes
