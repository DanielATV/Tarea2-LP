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
	pter->columnas = n;
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
						ptaux->valor = valor;
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

			aux = (((tMatris *)A)->arreglo)[j];

			ptaux = aux.sig;
			ptaux2 = NULL;


			while (ptaux != NULL){
				if (ptaux->i == i && ptaux->j == j){

					if (ptaux2 != NULL){
						ptaux2->sig = ptaux->sig;
						free(ptaux);
						return 0;
					}

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
		}
	}

}

void imprimir_matriz(void* A){
	tNodo *pt;
	tNodo *ptaux;
	tNodo aux;
	int n,k;
	int i,j,valor;

	n = ((tMatris *)A)-> columnas;

	

	for (k = 0; k<n ; k++){

		aux = (((tMatris *)A)->arreglo)[k];

		pt = aux.sig;

		if (pt == NULL) continue;

		else{

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

	if (m != h || n != l){
		printf("Error de dimensiones\n");
		exit(0);
	}

	resultado = alloc_dispersa(m,n);

	for (k = 0; k<n ; k++){

		aux = (((tMatris *)A)->arreglo)[k];

		pt = aux.sig;

		if (pt == NULL) continue;

		else{

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

	if (n != h){
		printf("Error de dimensiones\n");
		exit(0);
	}

	resultado = alloc_dispersa(m,l);

	for (k = 0; k< m; k++){

		for (u = 0; u< l; u++){

			for(o = 0; o< h; o++){
				valor = valor + encontrar_valor(A,k,o)*encontrar_valor(B,o, u);
			}
			ingresar_valor(resultado,k,u,valor);
			valor = 0;

		}
	}

	return resultado;

}

void binaria(void* (*fun)(void*,void*), void* A, void* B){
	void * c;

	c = (*fun)(A,B);

	imprimir_matriz(c);
	free_dispersa(c);
}

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

	for (k = 0; k<n ; k++){

		aux = (((tMatris *)A)->arreglo)[k];

		pt = aux.sig;

		if (pt == NULL) continue;

		else{

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
void* diagonal(void* A){
	void *resultado;
	int n,m,k;
	int valor;
	m = ((tMatris *)A)-> filas;
	n = ((tMatris *)A)-> columnas;

	resultado = alloc_dispersa(m,n);

	if (m>= n){
		for (k = 0;k<n; k++){
			valor = encontrar_valor(A,k,k);
			ingresar_valor(resultado,k,k,valor);

		}
		return resultado;

	}
	else{
		for (k = 0;k<m; k++){
			valor = encontrar_valor(A,k,k);
			ingresar_valor(resultado,k,k,valor);

		}
		return resultado;

	}



}
void unaria(void* (*fun)(void*), void* A){
	void * c;

	c = (*fun)(A);

	imprimir_matriz(c);
	free_dispersa(c);

}
