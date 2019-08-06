# Makefile for this project

CC							= gcc
CC_OPT					= -Wall -Wextra -O2 -fPIC -ftrapv -static
#CC_OPT					= -Wall -Wextra -O2 -fPIC -ftrapv

all:						filewalk

filewalk:				filewalk.c
								$(CC) $(CC_OPT) -o filewalk filewalk.c

clean:
								rm filewalk

# end of Makefile
