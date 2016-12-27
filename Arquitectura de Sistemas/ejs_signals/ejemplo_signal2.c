/* En línea de comandos:
	$ ./a.out &
	[1]	7216
	$ kill -USR1 7216
	$ kill -USR2 7216
	$ kill 7216
*/	

#include <stdio.h>
#include <signal.h>
#include <errno.h>

void sig_usr(int); /* una rutina de tratamiento para las dos senyales */
//gcc -o ejemplo_signal2 ejemplo_signal2.c
void main ()
{
	if (signal(SIGUSR1, sig_usr) == SIG_ERR)
		perror("no se puede capturar SIGUSR1");
	if (signal(SIGUSR2, sig_usr) == SIG_ERR)
		perror("no se puede capturar SIGUSR2");
	for (;;)
		pause();
	return;
}

void sig_usr (int sig)
{
	if (sig == SIGUSR1)
		printf("senyal SIGUSR1 recibida\n");
	else if (sig == SIGUSR2)
		printf("senyal SIGUSR2 recibida\n");
	else
		fprintf(stderr,"La senyal recibida es %d\n", sig);
	return;
}

