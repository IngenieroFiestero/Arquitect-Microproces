#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
//gcc -o bucle_fork bucle_fork.c 
void main (int argc, char **argv)
{
	int i, N;
	//Convierte de string a entero
	N = atoi(argv[1]);
	//Hace N forks
	for (i=0;i<N;i++){
		fork();
	}
	//Cada proceso imprime por pantalla que PID tiene y acaba
	fprintf(stdout, "Acabo: soy %d\n", getpid());
	exit(0);
}
