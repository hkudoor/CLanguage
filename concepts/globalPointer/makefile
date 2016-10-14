all: main

main: globalPointer.c utils.o
	gcc globalPointer.c utils.o -I../../lib -o globalPointer

utils.o: ../../lib/utils.h ../../lib/utils.c
	gcc -c ../../lib/utils.c -I../../lib
