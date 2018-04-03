LIB := $(shell find ./lib -name '*.o')
all:
	 gcc -c reversewords.c
	 gcc -c main.c
	 gcc -o reversewords.exe reversewords.o main.o $(LIB)

reversewordstest: clean
	 gcc -c reversewords.c
	 gcc -c reversewordstest.c
	 gcc -o reversewordstest.exe reversewords.o reversewordstest.o
	 ./reversewordstest.exe

test:	 reversewordstest

clean:
	 rm *.out *.o *.exe || exit 0

reversewords: clean
	 gcc -c reversewords.c
	 gcc -c main.c
	 gcc -o reversewords.exe reversewords.o main.o $(LIB)

run: reversewords
	 ./reversewords.exe

runtest: reversewords
	 ./maintest.tcl ./reversewords.exe

