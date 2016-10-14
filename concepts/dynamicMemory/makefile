all: dynamicMemory

dynamicMemory: utils.o dynamicMemory.c
	gcc dynamicMemory.c utils.o -I../../lib/ -o dynamicMemory

utils.o: ../../lib/utils.h ../../lib/utils.c
	gcc -c ../../lib/utils.c -I../../lib/
