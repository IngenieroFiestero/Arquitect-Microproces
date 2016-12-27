#include <sys/types.h>
	/* para funciones rel. con el pid; depende del sistema.
	 */
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
//gcc -o ej701 ej701.c
void main()
{
	pid_t getpid();
	int pidh;

	printf( "Inicio prueba\n" );

	if ( (pidh=fork())==0 ){
		fprintf( stderr, "\n\tSoy el hijo: %d\n", getpid() );
		fprintf( stdout, "\n\tFork me devuelve: %d\n", pidh );
		exit( 0 );
	}

	fprintf( stderr, "Antes de sleep\n");
	sleep( 7 );
	if( -1 ==wait(NULL))
	{
		perror("Error: wait");
	}
	fprintf( stderr, "Despues de sleep\n");
	fprintf( stdout, "\n\tSoy el padre: %d\n", getpid() );
	fprintf( stdout, "\n\tFork me devuelve: %d\n", pidh );
}
/*
Salida:
	Inicio prueba
	Antes de sleep

		Soy el hijo: 18089

		Fork me devuelve: 0
	Despues de sleep

		Soy el padre: 18088

		Fork me devuelve: 18089

*/