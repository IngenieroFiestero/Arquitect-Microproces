#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <fcntl.h>
//gcc -o ej61 ej61.c
void main()
{
	execl( "/bin/ls", "ls", "-c", 0 );
	syserr( "execlp" );
}
