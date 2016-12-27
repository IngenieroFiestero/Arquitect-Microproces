#include<stdio.h>
#include<stdlib.h>
#include <unistd.h>
int global;
//gcc -o fork fork.c
void main()
{
	int local;

	local = 1;
	if( fork() == 0)
	{
		global = 2;
		local = 3;
		printf( "Hijo: global %d local %d \n", global, local);
		exit(0);
	}
	sleep(1);
	printf( "global %d local %d \n", global, local);
	/*
	Salida:
		Hijo: global 2 local 3 
		global 0 local 1 
	El hijo no modifica las variables del padre.
	*/
}
