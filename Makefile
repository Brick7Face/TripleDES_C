
SHELL=/bin/sh
CC=g++
FLAGS=-c -ansi

all:		main

main:		main.o tdes.o test.o
	$(CC) -o main main.o tdes.o

main.o:		main.c main.h
	$(CC) $(FLAGS) -o main.o main.c

test:		test.o tdes.o
	$(CC) -o test test.o tdes.o

test.o:		test.c test.h
	$(CC) $(FLAGS) -o test.o test.c

tdes.o:		tdes.c tdes.h main.h
	$(CC) $(FLAGS) -o tdes.o tdes.c

clean:
	-rm *.o main test
