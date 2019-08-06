# Makefile for this project

CC		= gcc
CC_OPT		= -Wall -O2 -fPIC -ftrapv -static

all:		file-walk

filewalk:	file-walk.c
		$(CC) $(CC_OPT) -o file-walk file-walk.c

clean:
		rm file-walk

# end of Makefile
