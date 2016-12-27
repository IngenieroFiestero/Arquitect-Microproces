#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
//gcc -o ej70 ej70.c
int main()
{
    int pid;
    printf("Inicio prueba\n");
    pid = fork();
    printf( "Soy el proceso %d, fork() me ha devuelto %d\n", getpid(), pid);
    exit(0);
}
/*
Salida:
    Inicio prueba
    Soy el proceso 15915, fork() me ha devuelto 15916
    Soy el proceso 15916, fork() me ha devuelto 0
*/