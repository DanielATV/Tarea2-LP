#include <stdio.h>
#include <stdlib.h>
#include "dispersa.h"


int main(){
	void *a;

	a = alloc_dispersa(2, 2);

	free_dispersa(a);



}
