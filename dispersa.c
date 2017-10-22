#include <stdio.h>
#include <stdlib.h>
#include "matris.h"

/******** Funcion: alloc_dispersa ********************
Descripcion: Constructor de matrices, pide la memoria para la matriz y la inicializa.

Parametros:
m: entero.
n: entero.

Retorno: Puntero a void de la nueva matriz de dimension mxn.
************************************************/

void* alloc_dispersa(int m, int n){
	tMatris *pter;
	tNodo *pt;
	int i;
	tNodo aux;
	aux.sig = NULL;

	pter = (tMatris *)malloc(sizeof(tMatris));
	pt = (tNodo *)malloc(n*sizeof(tNodo));
	pter->filas = m;
	pter->columnas = n;
	pter->arreglo = pt;
	
	// Inicializa el arreglo de la matriz con un "dummy" en cada celda del arreglo.
	for (i = 0; i < n; i++){
		(pter->arreglo)[i] = aux;
	}


	return (void *)pter;
}

/******** Funcion: free_dispersa ********************
Descripcion: Destructor de matrices, libera la memoria utilizada para la matriz.

Parametros:
A: void.

Retorno: Notorna parametro.
************************************************/

void free_dispersa(void* A){
	tNodo *pt;
	tNodo *ptaux;
	tNodo aux;
	int n;
	int i;

	n = ((tMatris *)A)-> columnas;
	
	//Iteracion sobre las columnas.

	for (i = 0; i<n ; i++){

		aux = (((tMatris *)A)->arreglo)[i];

		pt = aux.sig;

		if (pt == NULL) continue;

		else{
			//Iteracion sobre las filas.
			while (pt != NULL){

				ptaux = pt -> sig;
				free(pt);
				pt = ptaux;

			}

		}
	}

	free(((tMatris *)A)->arreglo);
	free(A);

}

/******** Funcion: ingresar_valor ********************
Descripcion: Se ingresa un valor a la posicion dada de la matriz.

Parametros:
A: void.
i: entero.
j: entero.
valor: entero.

Retorno: Retorna 1 si no se efectuo la operacion y 0 en el caso contrario.
************************************************/

int ingresar_valor(void* A, int i, int j, int valor){
	tNodo *pter;
	tNodo *ptaux;
	tNodo *ptaux2;
	tNodo aux;
	
	//Caso de error.
	if (i >= ((tMatris *)A)-> filas || j >= ((tMatris *)A)-> columnas){
		printf("Fuera de las dimensiones de la matris\n");
		return 1;

	} 

	else{

		//En el caso que el valor sea distinto de 0.
		if (valor != 0){
			
			aux = (((tMatris *)A)->arreglo)[j];
			
			//En el caso que la columna este vacia agrega el nuevo elemento.
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
				
				//Si ya existe cambia su valor.
				
				while (ptaux != NULL){

					if (ptaux->i == i && ptaux->j == j){
						ptaux->valor = valor;
						return 0;
					}
					else{
						ptaux2 = ptaux;
						ptaux = ptaux->sig;

					} 

				}
				
				//Si no existe lo agrega.
				pter = (tNodo *)malloc(sizeof(tNodo));
				pter->i = i;
				pter->j = j;
				pter->valor = valor;
				pter->sig = NULL;
				ptaux2->sig = pter;
				return 0;
			}

		}

		//Si el valor es 0.
		else{

			aux = (((tMatris *)A)->arreglo)[j];

			ptaux = aux.sig;
			ptaux2 = NULL;


			while (ptaux != NULL){
				if (ptaux->i == i && ptaux->j == j){
					//Si lo encuentra lo elimina.
					if (ptaux2 != NULL){
						ptaux2->sig = ptaux->sig;
						free(ptaux);
						return 0;
					}
					//En el caso que sea el primer elemento de la columna.
					else{
						((((tMatris *)A)->arreglo)[j]).sig = NULL;
						free(ptaux);
						return 0;
					}


				}
				else{

					ptaux2 = ptaux;
					ptaux = ptaux->sig;
	
				}

			}
			//Si no lo encuentra no hace nada.
			return 0;
		}
	}

}

/******** Funcion: imprimir_matriz ********************
Descripcion: Imprime por pantalla los elementos no nulos de la matriz de la forma (i,j) = valor.

Parametros:
A: void.

Retorno: No retorna parametro.
************************************************/

void imprimir_matriz(void* A){
	tNodo *pt;
	tNodo *ptaux;
	tNodo aux;
	int n,k;
	int i,j,valor;

	n = ((tMatris *)A)-> columnas;

	
	//Iteracion sobre las columnas.
	for (k = 0; k<n ; k++){

		aux = (((tMatris *)A)->arreglo)[k];

		pt = aux.sig;

		if (pt == NULL) continue;

		else{
			//Iteracion sobre las filas.
			while (pt != NULL){

				i = pt-> i;
				j = pt-> j;
				valor = pt-> valor;

				printf("(%d,%d) = %d\n",i,j,valor );

				ptaux = pt -> sig;
				pt = ptaux;

			}

		}
	}

}

/******** Funcion: suma ********************
Descripcion: Suma dos matrices.

Parametros:
A: void.
B: void.

Retorno: Puntero a void con la matriz resultante luego de realizar la operacion.
************************************************/

void* suma(void*A,void*B){
	void *resultado;
	int m,n;
	int h,l;
	tNodo aux,aux2;
	tNodo *ptaux;
	tNodo *ptaux2;
	int k,u;
	tNodo *pt;
	tNodo *pt2;
	int valor;


	m = ((tMatris *)A)->filas;
	n = ((tMatris *)A)->columnas;

	h = ((tMatris *)B)->filas;
	l= ((tMatris *)B)->columnas;
	
	//Caso de error.
	if (m != h || n != l){
		printf("Error de dimensiones\n");
		exit(0);
	}

	resultado = alloc_dispersa(m,n);

	//Iteracion sobre las columnas.
	for (k = 0; k<n ; k++){

		aux = (((tMatris *)A)->arreglo)[k];

		pt = aux.sig;

		if (pt == NULL) continue;

		else{
			//Iteracion sobre las filas.
			while (pt != NULL){


				valor = pt->valor;
				valor = valor + encontrar_valor(B,pt->i,pt->j);
				ingresar_valor(resultado,pt->i,pt->j,valor);


				ptaux = pt -> sig;
				pt = ptaux;

			}

		}
	}

	return resultado;

}

/******** Funcion: multiplicacion ********************
Descripcion: Multiplica dos matrices.

Parametros:
A: void.
B: void.

Retorno: Puntero a void con la matriz resultante luego de realizar la operacion.
************************************************/

void* multiplicacion(void*A,void*B){
	void *resultado;
	int m,n;
	int h,l;
	int k,u,o;
	int valor;
	valor = 0;


	m = ((tMatris *)A)->filas;
	n = ((tMatris *)A)->columnas;

	h = ((tMatris *)B)->filas;
	l= ((tMatris *)B)->columnas;
	//Caso de error.
	if (n != h){
		printf("Error de dimensiones\n");
		exit(0);
	}

	resultado = alloc_dispersa(m,l);
	//Iteracion de las filas de la nueva matriz.
	for (k = 0; k< m; k++){
		//Iteracion de las columnas de la nueva matriz.
		for (u = 0; u< l; u++){
			//Iteracion de los elementos de A y B.
			for(o = 0; o< h; o++){
				valor = valor + encontrar_valor(A,k,o)*encontrar_valor(B,o, u);
			}
			ingresar_valor(resultado,k,u,valor);
			valor = 0;

		}
	}

	return resultado;

}

/******** Funcion: binaria ********************
Descripcion: Efectua una funcion binaria sobre dos matrices.

Parametros:
*fun(void,void): Puntero a funcion.
A: void.
B: void.

Retorno: No retorna parametro.
************************************************/

void binaria(void* (*fun)(void*,void*), void* A, void* B){
	void * c;

	c = (*fun)(A,B);

	imprimir_matriz(c);
	free_dispersa(c);
}

/******** Funcion: transponer ********************
Descripcion: Transpone la matriz ingresada.

Parametros:
A: void.

Retorno: Puntero a void con la matriz resultante luego de realizar la operacion.
************************************************/

void* transponer(void* A){
	void * resultado;
	tNodo *pt;
	tNodo *ptaux;
	tNodo aux;
	int n,m,k;
	int i,j,valor;

	m = ((tMatris *)A)-> filas;
	n = ((tMatris *)A)-> columnas;

	resultado = alloc_dispersa(n,m);
	//Iteracion de las columnas.
	for (k = 0; k<n ; k++){

		aux = (((tMatris *)A)->arreglo)[k];

		pt = aux.sig;

		if (pt == NULL) continue;

		else{
			//Iteracion de las filas.
			while (pt != NULL){

				i = pt-> i;
				j = pt-> j;
				valor = pt-> valor;

				ingresar_valor(resultado,j,i,valor);


				ptaux = pt -> sig;
				pt = ptaux;

			}

		}
	}



	return resultado;
}

/******** Funcion: diagonal ********************
Descripcion: Encuentra la diagonal principal de una matriz dada.

Parametros:
A: void.

Retorno: Puntero a void con la matriz resultante luego de realizar la operacion.
************************************************/

void* diagonal(void* A){
	void *resultado;
	int n,m,k;
	int valor;
	m = ((tMatris *)A)-> filas;
	n = ((tMatris *)A)-> columnas;

	resultado = alloc_dispersa(m,n);
	//En el caso para matrices cuadradas y no cuadradas con mas filas que columnas.
	if (m>= n){
		for (k = 0;k<n; k++){
			valor = encontrar_valor(A,k,k);
			ingresar_valor(resultado,k,k,valor);

		}
		return resultado;

	}
	//En el caso para no cuadradas con mas columnas que filas.
	else{
		for (k = 0;k<m; k++){
			valor = encontrar_valor(A,k,k);
			ingresar_valor(resultado,k,k,valor);

		}
		return resultado;

	}



}

/******** Funcion: unaria ********************
Descripcion: Efectua una funcion unaria sobre una matrices.
Parametros:
*fun(void*): Puntero a funcion.
A: void.
Retorno: No retorna parametro.
************************************************/

void unaria(void* (*fun)(void*), void* A){
	void * c;

	c = (*fun)(A);

	imprimir_matriz(c);
	free_dispersa(c);

}

/******** Funcion: element_wise_op ********************
Descripcion: Efectua una funcion sobre cada elemento de la matriz.

Parametros:
*fun(int): Puntero a funcion.
A: void.

Retorno: Puntero a void con la matriz resultante luego de realizar la operacion.
************************************************/

void* element_wise_op(int (*fun)(int), void* A){
	int m,n;
	int k,u;
	int valor;
	void *resultado;


	m = ((tMatris *)A)-> filas;
	n = ((tMatris *)A)-> columnas;

	resultado = alloc_dispersa(m,n);
	//Iteracion sobre cada elemento de la matriz.
	for (k = 0;k < n; k++){
		for(u = 0; u<m; u++){

			valor = encontrar_valor(A,u,k);
			valor = (*fun)(valor);
			ingresar_valor(resultado,u,k,valor);
		}
	}

	return resultado;


}
