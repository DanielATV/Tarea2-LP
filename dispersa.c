#include <stdio.h>
#include <stdlib.h>
#include "matris.h"



void* alloc_dispersa(int m, int n){
	tMatris *pter;
	tNodo *pt;
	int i;
	tNodo aux;
	aux.sig = NULL;

	pter = (tMatris *)malloc(sizeof(tMatris));
	pt = (tNodo *)malloc(n*sizeof(tNodo));
	pter->filas = m;
	pter->filas = n;
	pter->arreglo = pt;

	for (i = 0; i < n; i++){
		(pter->arreglo)[i] = aux;
	}


	return (void *)pter;
}

void free_dispersa(void* A){
	tNodo *pt;
	tNodo *ptaux;
	tNodo aux;
	int n;
	int i;

	n = ((tMatris *)A)-> columnas;

	

	for (i = 0; i<n ; i++){

		aux = (((tMatris *)A)->arreglo)[i];

		pt = aux.sig;

		if (pt == NULL) continue;

		else{

			while (pt != NULL){

				ptaux = pt -> sig;
				free(pt);
				pt = ptaux;

			}

		}
	}

	free(((tMatris *)A)->arreglo);




}
