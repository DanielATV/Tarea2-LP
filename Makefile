main.o: main.c
	gcc -c main.c -Wall

dispersa: dispersa.c dispersa.h matris.h
	gcc -c dispersa.c -Wall

matris: main.o dispersa.o
	gcc main.o dispersa.o -o matris
