#set environment variables for installation

PREFIX_3PARTY=/data/3party
PREFIX_INC=/data/include
PREFIX_LIB=/data/lib
PREFIX_BIN=/data/sbin
PREFIX_SHELL=/data/shell
PREFIX_CONFIG_DEF=/data/etc/config
PREFIX_CRON=/data/etc/cron


export CCACHE_DIR=/home/ccache_cache
export CCACHE_BASEDIR=/home/ccache_cache
export CCACHE_UMASK=002
export CCACHE_LOGFILE=/home/ccache.log

include $(ROOTDIR)/BaseVar.mk

