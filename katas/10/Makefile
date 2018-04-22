LIB := $(shell find ./lib -name '*.o')
all:
	 gcc -c utf8.c
	 gcc -c main.c
	 gcc -o utf8.exe utf8.o main.o $(LIB)

utf8test: clean
	 gcc -c utf8.c
	 gcc -c utf8test.c
	 gcc -o utf8test.exe utf8.o utf8test.o
	 ./utf8test.exe

test:	 utf8test

clean:
	 rm *.out *.o *.exe || exit 0

utf8: clean
	 gcc -c utf8.c
	 gcc -c main.c
	 gcc -o utf8.exe utf8.o main.o $(LIB)

run: utf8
	 ./utf8.exe

runtest: utf8
	 ./maintest.tcl ./utf8.exe

