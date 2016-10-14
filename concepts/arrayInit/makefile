all: main

main: utils.o arrayInit.c 
	gcc arrayInit.c utils.o -I../../lib/ -o arrayInit

utils.o: ../../lib/utils.h ../../lib/utils.c
	gcc -c ../../lib/utils.c -I../../lib/
