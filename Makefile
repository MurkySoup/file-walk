# Makefile for this project

CC		= gcc
CC_OPT		= -Wall -Wextra -O2 -fPIC -ftrapv -static
#CC_OPT		= -Wall -Wextra -O2 -fPIC -ftrapv

all:		file-walk

file-walk:	file-walk.c
		$(CC) $(CC_OPT) -o file-walk file-walk.c

clean:
		rm file-walk

# end of Makefile

