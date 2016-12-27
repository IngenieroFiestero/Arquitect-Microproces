#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <stdlib.h>
#define BUFSIZE 1024
//gcc -o ej73 ej73.c
void main () /* lanza comando con parametros */
{
	static char s[BUFSIZE];
	char *argt[BUFSIZE];
	int i;

	for (;;) //while(1)
	{
		fprintf(stderr,"\n_$ ");
		if (gets(s) == NULL)
		{
			printf("logout\n");
			exit(0);
		}
		
		argt[0] = strtok(s, " ");
		printf("Arg 0: %s\n", argt[0]);

		if (0 == strcmp(argt[0], "quit"))
		{
			printf("logout\n");
			exit(0);
		}

		for (i=1; (argt[i] = strtok(NULL, " ")) != NULL; i++)
			printf("Arg[%d]: %s\n", i, argt[i]);
		
		switch (fork())
		{
			case -1: /* error */
				fprintf(stderr,"\nNo se puede crear proceso nuevo\n");
				perror("fork");
			case 0: /* hijo */
				execvp(argt[0], &argt[0]);
				fprintf(stderr,"\nNo se puede ejecutar %s\n", argt[0]);
				perror("execvp");
			default: /* padre */
				if (wait(NULL) == -1)
					perror("wait");
		}
	}
}
		
		
