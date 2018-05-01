all:
	 gcc -c partitions.c
	 gcc -c main.c
	 gcc -o partitions.exe partitions.o main.o

partitionstest: clean
	 gcc -c partitions.c
	 gcc -c partitionstest.c
	 gcc -o partitionstest.exe partitions.o partitionstest.o
	 ./partitionstest.exe

test:	 partitionstest

clean:
	 rm *.out *.o *.exe || exit 0

partitions: clean
	 gcc -c partitions.c
	 gcc -c main.c
	 gcc -o partitions.exe partitions.o main.o

run: partitions
	 ./partitions.exe

runtest: partitions
	 ./maintest.tcl ./partitions.exe

