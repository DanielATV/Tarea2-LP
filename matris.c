#include <stdio.h>
#include <stdlib.h>
#include "matris.h"

int encontrar_valor(void* A, int i, int j){
	tNodo *pt;
	tNodo *ptaux;
	tNodo aux;
	int valor;
	valor = 0;

	aux = (((tMatris *)A)->arreglo)[j];
	pt = aux.sig;

	if (pt == NULL) return valor;

	else{

		while (pt != NULL){

			if(pt->i == i){

				valor = pt->valor;
				return valor;

			}



			ptaux = pt -> sig;
			pt = ptaux;
		}
		return valor;
	}
	
}

int agregar(int a){

	return a + 1;

}
