LIB := $(shell find ./lib -name '*.o')
all:
	 gcc -c numericstr.c
	 gcc -c main.c
	 gcc -o numericstr.exe numericstr.o main.o $(LIB)

numericstrtest: clean
	 gcc -c numericstr.c
	 gcc -c numericstrtest.c
	 gcc -o numericstrtest.exe numericstr.o numericstrtest.o
	 ./numericstrtest.exe

test:	 numericstrtest

clean:
	 rm *.out *.o *.exe || exit 0

numericstr: clean
	 gcc -c numericstr.c
	 gcc -c main.c
	 gcc -o numericstr.exe numericstr.o main.o $(LIB)

run: numericstr
	 ./numericstr.exe

runtest: numericstr
	 ./maintest.tcl ./numericstr.exe

