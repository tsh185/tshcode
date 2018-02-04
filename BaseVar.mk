# set base variable
#

ifeq ($(V),1)
Q=
else
Q=@
endif

MAKE = make
PERL = perl
AWK  = awk
