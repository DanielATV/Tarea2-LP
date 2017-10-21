#include <stdio.h>
#include <stdlib.h>
#include "dispersa.h"


int main(){
	void *a;
	int b,c;

	a = alloc_dispersa(2, 2);


	ingresar_valor(a,1,1,3);
	ingresar_valor(a,0,1,4);
	ingresar_valor(a,0,0,2);
	ingresar_valor(a,1,0,7);

	imprimir_matriz(a);

	printf("----------------\n");

	ingresar_valor(a,1,0,9);


	imprimir_matriz(a);


	free_dispersa(a);





}
