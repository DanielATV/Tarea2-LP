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

int ingresar_valor(void* A, int i, int j, int valor){
	tNodo *pter;
	tNodo *ptaux;
	tNodo *ptaux2;
	tNodo aux;

	if (i >= ((tMatris *)A)-> filas || j >= ((tMatris *)A)-> columnas){
		printf("Fuera de las dimensiones de la matris\n");
		return 1;

	} 

	else{


		if (valor != 0){
			
			aux = (((tMatris *)A)->arreglo)[j];

			if (aux.sig == NULL){
				pter = (tNodo *)malloc(sizeof(tNodo));
				pter->i = i;
				pter->j = j;
				pter->valor = valor;
				pter->sig = NULL;

				((((tMatris *)A)->arreglo)[j]).sig = pter;

				return 0;
			}

			else{

				ptaux = aux.sig;
				ptaux2 = ptaux;
				
				while (ptaux != NULL){

					if (ptaux->i == i && ptaux->j == j){
						ptaux->valor == valor;
						return 0;
					}
					else{
						ptaux2 = ptaux;
						ptaux = ptaux->sig;

					} 

				}
				pter = (tNodo *)malloc(sizeof(tNodo));
				pter->i = i;
				pter->j = j;
				pter->valor = valor;
				pter->sig = NULL;
				ptaux2->sig = pter;
				return 0;
			}

		}

		
		else{
			return 0;
		}
	}


}
