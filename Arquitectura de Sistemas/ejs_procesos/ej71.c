#include <stdio.h>
#include <errno.h>
#include <unistd.h>
//gcc -o ej71 ej71.c
void main (argc, argv) /* lanza comando sin parametros */
int argc; char *argv[];
{
	switch (fork()) {
	case -1: /* error */
		fprintf(stderr,"no se puede crear proceso nuevo\n");
		perror("fork");
	case 0: /* hijo */
		execlp(argv[1], argv[1], NULL);
		printf("No se puede ejecutar %s\n", argv[1]);
		perror("execlp");
	default: /* padre */
		if (wait(NULL) == -1)
			perror ("wait"); /* trat. erroneo */
		printf("Ejecutado %s\n", argv[1]);
	}
}
/*
Salida:
	bucle_fork.c  ej60.c  ej61.c  ej62.c  ej70.c  ej71  ej71.c  fork_1.c  fork_2.c	fork.c	time_fork.c
	Ejecutado ls
*/
