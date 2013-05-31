CC:=gcc
CFLAG:=-o
%.out:%.c
	$(CC) $(CFLAG) $@ $^
override FILES:=$(shell find -maxdepth 1 -iname '*.c')

RETURNS:=$(FILES:.c=.out)
#all:
	#echo $(RETURNS)
all:$(RETURNS)
#$(RETURNS):
