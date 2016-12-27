#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

//gcc -o time_fork time_fork.c
void main ()
{
	int N = 4, i, pid, time;

	for(i=0;i<N;i++)
	{
		pid = fork();
		if (pid == 0)
			break;
	}
	
	if (pid == 0) /* N hijos */
	{
		srand(getpid());
		time =  rand() % 10;
		printf("Tiempo: %d, %d \n", time, getpid());
		sleep (time);
		printf("Soy hijo %d: He dormido %d segundos\n", getpid(), time);
		exit(0);
	}
	else /* padre */
	{
		for (i=0;i<N;i++)
		{
			if (-1 == wait(NULL))
			{
				perror("wait");
				exit(0);
			}
		}
	}
}
