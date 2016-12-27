#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

//gcc -o fork_2 fork_2.c
void main ()
{
    int id;
    printf("Comienza la ejecucion\n");
    id = fork();
    if (id == 0)
    {
        printf("Soy el hijo\n");
    }
    else
    {
	    printf("Soy el padre\n");
    }
    printf("Termina la ejecucion\n");
    exit (0); /* ejecutado por ambos */
}
