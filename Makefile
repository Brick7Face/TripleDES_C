
SHELL=/bin/sh
CC=g++
FLAGS=-c -ansi

all:		main main8bit

main:		main.o tdes.o test.o
	$(CC) -o main main.o tdes.o

main.o:		main.c main.h
	$(CC) $(FLAGS) -o main.o main.c

main8bit:	main8bit.o tdes8bit.o
	$(CC) -o main8bit main8bit.o tdes8bit.o

main8bit.o:	main8bit.c main8bit.h
	$(CC) $(FLAGS) -o main8bit.o main8bit.c

test:		test.o tdes.o
	$(CC) -o test test.o tdes.o

test.o:		test.c test.h
	$(CC) $(FLAGS) -o test.o test.c

test8bit:	test8bit.o tdes8bit.o
	$(CC) -o test8bit test8bit.o tdes8bit.o

tdes8bit.o:	tdes8bit.c tdes8bit.h
	$(CC) $(FLAGS) -o tdes8bit.o tdes8bit.c

tdes.o:		tdes.c tdes.h main.h
	$(CC) $(FLAGS) -o tdes.o tdes.c

clean:
	-rm *.o main main8bit test test8bit
