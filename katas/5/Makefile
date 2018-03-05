default: wordcount

hash.o:
	gcc -c hash.c -o hash.o

clean:
	 rm *.out *.o *.exe || exit 0

wordcount: clean hash.o
	 gcc -c wordcount.c
	 gcc -c main.c
	 gcc -o wordcount.exe hash.o wordcount.o main.o

