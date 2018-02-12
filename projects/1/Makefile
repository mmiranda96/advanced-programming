CC=gcc

default: main

main: graph.o list.o hashtable.o
	$(CC) main.c graph.o list.o hashtable.o -o main.out

graph.o:
	$(CC) -c graph.c -o graph.o

list.o:
	$(CC) -c list.c -o list.o

hashtable.o:
	$(CC) -c hashtable.c -o hashtable.o

clean:
	$(RM) *.out
	$(RM) *.o