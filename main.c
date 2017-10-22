#include <stdio.h>
#include <stdlib.h>
#include "dispersa.h"


int main(){
	void *a;
	void *b;
	void *c;
	

	a = alloc_dispersa(2, 2);
	b = alloc_dispersa(2, 2);


	ingresar_valor(a,1,1,1);
	ingresar_valor(a,0,1,1);
	ingresar_valor(a,0,0,1);
	ingresar_valor(a,1,0,1);

	imprimir_matriz(a);

	printf("----------------\n");

	ingresar_valor(b,1,1,2);
	ingresar_valor(b,0,1,0);
	ingresar_valor(b,0,0,0);
	ingresar_valor(b,1,0,2);


	imprimir_matriz(b);

	printf("----------------\n");


	c = multiplicacion(a,b);

	imprimir_matriz(c);




	free_dispersa(a);
	free_dispersa(b);
	free_dispersa(c);





}
