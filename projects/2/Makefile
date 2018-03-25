LIB := $(shell find ./lib -name '*.o')
all:
	 gcc -c tidy.c
	 gcc -c main.c
	 gcc -o tidy.exe tidy.o main.o $(LIB)

tidytest: clean
	 gcc -c tidy.c
	 gcc -c tidytest.c
	 gcc -o tidytest.exe tidy.o tidytest.o
	 ./tidytest.exe

test:	 tidytest

clean:
	 rm *.out *.o *.exe || exit 0

tidy: clean
	 gcc -c tidy.c
	 gcc -c main.c
	 gcc -o tidy.exe tidy.o main.o $(LIB)

run: tidy
	 ./tidy.exe

runtest: tidy
	 ./maintest.tcl ./tidy.exe

