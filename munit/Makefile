ifndef TOPDIR
TOPDIR := ../
endif

include $(TOPDIR)/Config.mk

TARGET := build-in.o
SUBDIRS :=
OBJS := $(patsubst %.S, %.o, $(wildcard *.S))
OBJS += $(patsubst %.c, %.o, $(wildcard *.c))


all : compile $(OBJS)
	$(LD) -r $(addsuffix /$(TARGET), $(SUBDIRS)) $(OBJS) -o $(TARGET)

#print_debug:
#	@echo $(OBJS)

include $(TOPDIR)/Rules.mk