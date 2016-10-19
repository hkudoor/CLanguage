hello: helloLinkedList.c linkedList
	gcc helloLinkedList.c linkedList.o -I. -o helloLinkedList

stack: stack.c linkedList
	gcc stack.c linkedList.o -I. -o stack

queue: queue.c linkedList
	gcc queue.c linkedList.o -I. -o queue 

linkedList: linkedList.h linkedList.c
	gcc -c linkedList.c -I. -o linkedList.o
