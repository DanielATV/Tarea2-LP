#include <stdio.h>
#include <stdlib.h>
#include "dispersa.h"


int main(){
	void *a;
	int b,c;

	a = alloc_dispersa(2, 2);





	ingresar_valor(a,1,1,3);
	ingresar_valor(a,0,1,4);


	free_dispersa(a);





}
