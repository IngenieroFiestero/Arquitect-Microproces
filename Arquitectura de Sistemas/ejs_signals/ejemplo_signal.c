#include <stdio.h>
#include <signal.h>

void fcaptura(int sig);
//gcc -o ejemplo_signal ejemplo_signal.c
void main ()
{
	void (*p)(int);

	p = signal(SIGALRM, fcaptura);/*Almacenar el handler por defecto para esta alarma*/
	alarm(6); /* el proceso programa una alarma:
		      dentro de 6 segundos se generara
		      la senyal SIGALRM */ 
	pause(); /* suspende al proceso hasta que se
		    recibe una senyal */
	printf("Trabajo terminado\n");
	signal(SIGALRM, p); /* establezco comportamiento
			       por defecto (SIG_DFL) */
	alarm(6);
	pause();
	printf("Trabajo terminado 2\n");
	return;
}

void fcaptura(int sig)
{
	printf("Estoy en la rutina de tratamiento de SIGALRM (%d)\n", sig);
	return;
}

