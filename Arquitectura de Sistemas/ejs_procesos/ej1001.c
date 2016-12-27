#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <stdlib.h>

#define BUFSIZE 1024
#define TRUE 1
#define FALSE 0
//gcc -o ej1001 ej1001.c
void main ()
{
	static char s[BUFSIZE];
	char *argt[BUFSIZE];
	int i, parate, pid;

	while(1)
	{
		fprintf(stderr,"\n_$ ");
		gets(s);
		argt[0] = strtok(s, " ");
		if (0 == strcmp(argt[0], "quit"))
		{
			printf("logout\n");
			exit(0);
		}
		
		for (i=1; (argt[i] = strtok(NULL, " ")) != NULL; i++);

		if (0 == strcmp(argt[0], "soo"))
			parate = TRUE;
		else if (0 == strcmp(argt[0], "arre"))
			parate = FALSE;
		else
		{
			printf("\n Mande? ");
			continue;
		}
		
		switch (pid = fork())
		{
			case -1: /* error */
				fprintf(stderr,"\nNo se puede crear proceso nuevo\n");
				perror("fork");

			case 0: /* hijo */
				if (!parate)
					sleep (10); /* para que se note mas */
				execvp(argt[1], &argt[1]);
				fprintf(stderr,"\nNo se puede ejecutar %s\n", argt[1]);
				perror("execvp");

			default: /* padre */
				if (parate)
				{
					while (pid != wait(NULL))
					{
						if (pid == -1)
						{
							fprintf(stderr,"\nMuy raro. Bye\n");
							exit (1);
						}
					}
				}
		} /* switch */
	} /* while */
} /* main */
