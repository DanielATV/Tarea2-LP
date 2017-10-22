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
	// Va a la columna j de la matriz.
	aux = (((tMatris *)A)->arreglo)[j];
	pt = aux.sig;
	
	// Si esta vacia retorna 0.
	if (pt == NULL) return valor;

	else{
		//Itera sobre los elementos de la columna.
		while (pt != NULL){

			if(pt->i == i){

				valor = pt->valor;
				return valor;

			}



			ptaux = pt -> sig;
			pt = ptaux;
		}
		//Si no lo encuentra retorna 0.
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
