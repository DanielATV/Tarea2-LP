main.o: main.c
	gcc -c main.c -Wall

matris: matris.c matris.h
	gcc -c matris.c -Wall

dispersa: dispersa.c dispersa.h matris.h
	gcc -c dispersa.c -Wall



tarea: main.o dispersa.o matris.o
	gcc main.o dispersa.o matris.o -o tarea
