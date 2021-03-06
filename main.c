#include <stdio.h>
#include <stdlib.h>
#include "dispersa.h"
#include "matris.h"


int main(){
	void *a;
	void *b;
	void *c;

	a = alloc_dispersa(2, 2);
	b = alloc_dispersa(2, 2);

	printf("Primera matris\n");
	ingresar_valor(a,1,1,2);
	ingresar_valor(a,0,1,1);
	ingresar_valor(a,0,0,1);
	ingresar_valor(a,1,0,2);

	imprimir_matriz(a);

	printf("----------------\n");
	printf("Segunda matris\n");

	ingresar_valor(b,1,1,2);
	ingresar_valor(b,1,0,2);
	ingresar_valor(b,1,0,0);



	imprimir_matriz(b);

	printf("----------------\n");
	printf("Multiplicacion\n");


	binaria(&multiplicacion,a,b);
	printf("----------------\n");
	printf("Suma\n");
	binaria(&suma,a,b);

	printf("----------------\n");
	printf("Traspuesta de la primera\n");

	unaria(&transponer,a);

	printf("----------------\n");
	printf("Diagonal de la primera\n");

	unaria(&diagonal,a);

	printf("----------------\n");
	printf("Sumarle 1 a todos los elementor de la segunda\n");

	c = element_wise_op(&agregar, b);

	imprimir_matriz(c);

	


	free_dispersa(a);
	free_dispersa(b);
	free_dispersa(c);
	return 0;





}
