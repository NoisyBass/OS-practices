#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/time.h>

int main (int argc, char **argv)
{
	pid_t mi_pid, pid;

	pid = fork();

	switch(pid)
	{
		case -1: 
			perror("¡! Error fork");
			exit(-1);
		case 0: // Hijo
			mi_pid = getpid();
			printf("Ejecutando el proceso hijo (PID = %i, PPID = %i)...\n", mi_pid, getppid());
						
			printf("Creando una nueva sesion %d\n", setsid());
			chdir("/tmp");
					
		break;
		default: // Padre
			mi_pid = getpid();
			printf("Ejecutando el proceso padre (PID = %i, hijo = %i)...\n", mi_pid, pid);
		break;
	}
	return 0;
}
