export ROOTDIR=$(shell pwd)
export PRODUCT_BUILD_DATE=$(shell date '+%Y-%m-%d %H:%M:%S')
export PRODUCT_DATE=$(shell date '+y%m%d')
export PRODUCT_BUILD_NAME=$(shell whoami) 


$(shell mkdir -p $())

DIRS = blog  cpp  go wifi 

all:subdirs

.PHONY: subdirs

subdirs:$(DIRS)
	for d in $(DIRS); do [ -d $$d ] && $(MAKE) -C $$d || exit 1; done

clean:
	echo $(DIRS)
	for d in $(DIRS); do [ -d $$d ] && $(MAKE) -C $$d clean || exit 1; done

install:
	for d in $(DIRS); do [ -d $$d ] && $(MAKE) -C $$d install || exit 1; done

