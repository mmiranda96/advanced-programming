CC=gcc

default: clean anagrams

anagrams: hashtable.o
	$(CC) anagrams.c hashtable.o -o anagrams.out

hashtable.o:
	$(CC) -c hashtable.c -o hashtable.o

clean:
	$(RM) *.out
	$(RM) *.o