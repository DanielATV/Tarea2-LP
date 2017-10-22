#ifndef __matris_h__
#define __matris_h__

typedef struct nodo {
	int i;
	int j;
	int valor;
	struct nodo *sig; 
                   
} tNodo;

typedef struct matris{
	int filas;
 	int columnas;
	tNodo *arreglo;
} tMatris;

int encontrar_valor(void* A, int i, int j);

#endif
