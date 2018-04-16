all: clean movies
	gcc -o movies.exe main.c movies.o hash.o

test: clean movies
	gcc -o moviestest.exe moviestest.c movies.o hash.o
	./moviestest.exe

clean:
	rm *.out *.o *.exe || exit 0

movies:
	gcc -c hash.c -o hash.o
	gcc -c movies.c -o movies.o

run: all
	./movies.exe