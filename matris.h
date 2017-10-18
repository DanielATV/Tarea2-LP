#ifndef __lista_en_h__
#define __lista_en_h__

#include <stdlib.h>

typedef struct elemento{
 int comienzo;
 int final;
} elemento;

typedef struct nodo {
 elemento info; // el elemento en sí
 struct nodo *sig; // puntero autoreferencial
                   // al proximo nodo
} tNodo;

#endif
