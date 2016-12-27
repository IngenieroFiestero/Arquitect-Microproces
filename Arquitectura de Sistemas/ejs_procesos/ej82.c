#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
//gcc -o ej82 ej82.c
void main()
{ 
	int pid;
	int estado;
	switch(fork()) { 
		case -1:/*error*/
			perror("fork");
		case 0 :/*hijo*/
			sleep(2); 
			printf("Soy el hijo y me muero...\n");
			exit(8);
		default:/*padre*/
			sleep(10);/*damos tiempo a que el hijo termine y se 
		       		quede zombie un rato.*/
			/*
			The wait() system call suspends execution of the calling process until one of its children terminates.
			*/
			if( -1 == wait(&estado) )
				perror( "wait" );
			printf("Estado hijo = %x\n", estado);
			exit(0);
	}
}
/*
Salida
	Soy el hijo y me muero...
	Estado hijo = 800
*/
