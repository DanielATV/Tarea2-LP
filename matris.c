#include <stdio.h>
#include <stdlib.h>
#include "matris.h"

/******** Funcion: encontrar_valor ********************
Descripcion: Encuentra el valor de la matriz en los indices dados.

Parametros:
A: void
i: entero
j: entero

Retorno: Retorna el valor encontrado, en caso de no ser encontrado retorna 0.
************************************************/

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

/******** Funcion: agregar ********************
Descripcion: Le suma 1 al valor ingresado.

Parametros:
a: entero

Retorno: El valor ingresado luego de sumarle 1.
************************************************/

int agregar(int a){

	return a + 1;

}
