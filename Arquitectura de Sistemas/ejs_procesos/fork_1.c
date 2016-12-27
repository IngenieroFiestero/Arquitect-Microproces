#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
//gcc -o fork_1 fork_1.c
void main ()
{
    int id;
    id = fork();
    if (id == 0)
    {
        printf("Soy el hijo\n");
    }
    else
    {
	    printf("Soy el padre\n");
    }
    exit (0); /* ejecutado por ambos */
}
