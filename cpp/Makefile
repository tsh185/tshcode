ifeq "$(ROOTDIR)" ""
export ROOTDIR=$(shell while true; do if [ -f BuildEnv.mk ]; then pwd; exit; else cd ..;fi; done;)
endif

include $(ROOTDIR)/BuildEnv.mk


