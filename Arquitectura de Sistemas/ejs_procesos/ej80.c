#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <errno.h>
//gcc -o ej80 ej80.c
int main()
{ 
    int pid;

    switch(fork()) {
        case -1:
    	    perror("fork");
        case 0:
            pid = getppid();
            printf("pid padre antes = %d\n",pid);
            sleep(4); 
            pid = getppid();
            printf("pid padre despues = %d\n",pid);
            exit(15);
        default:
            sleep(2);
            exit(0);
    } 
}
/*
Salida:
    pid padre antes = 17227
    pid padre despues = 1442
El padre acaba pero el hijo aun no, luego el padre muere y el hijo vuelve a llamar al padre que cambia de PID.
*/
