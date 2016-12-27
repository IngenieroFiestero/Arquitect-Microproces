#include <stdio.h>
#include <unistd.h>
//gcc -o exec_1 exec_1.c
void main ()
{
    execl("/bin/ls", "ls", "-l", NULL);
    printf("Error\n");
}
