
SHELL=/bin/sh
CC=g++
FLAGS=-c -ansi

all:		main

main:		main.o tdes.o
	$(CC) -o main main.o tdes.o

main.o:		main.c main.h
	$(CC) $(FLAGS) -o main.o main.c

tdes.o:		tdes.c tdes.h main.h
	$(CC) $(FLAGS) -o tdes.o tdes.c

clean:
	-rm *.o main test
