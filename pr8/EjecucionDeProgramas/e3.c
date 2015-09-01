#include <unistd.h>
#include <stdio.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <stdlib.h>

int main (int argc, char **argv)
{
	if (argc < 2)
	{
		printf("¡! Error en el número de argumentos. Uso: ./e3 programa [argumentos]\n");
		return -1;
	}

	pid_t mi_pid, pid;

	pid = fork();

	switch(pid)
	{
		case -1: 
			perror("¡! Error fork");
			exit(-1);
		break;

		case 0: // Hijo
			mi_pid = getpid();
			printf("Ejecutando el proceso hijo (PID = %i, PPID = %i)...\n", mi_pid, getppid());

			/****************************************/
			pid_t nsid = setsid();
			if (nsid == -1)
			{
				perror("No se ha podido crear una nueva sesión");
				return(-1);
			}

			int dt = chdir("/tmp");
			if (dt == -1)
			{
				perror("No se ha podido cambiar el directorio de trabajo");
				return -1;
			}

			int din = open("/dev/null", O_RDWR | O_CREAT);
			int dout = open("daemon.out", O_RDWR | O_CREAT);
			int derr = open("daemon.err", O_RDWR | O_CREAT);
			if (din == -1 || dout == -1 || derr == -1)
			{
				perror("¡! Error open");
				return(-1);
			}

			dup2(din, 0); // STDIN_FILENO
			dup2(dout, 1); // STDOUT_FILENO
			dup2(derr, 2); // STDERR_FILENO

			close(din);
			close(dout);
			close(derr);

			execlp(argv[1], argv[1], argv[2], NULL);
			/****************************************/
		break;

		default: // Padre
			mi_pid = getpid();
			printf("Ejecutando el proceso padre (PID = %i, hijo = %i)...\n", mi_pid, pid);

			int status;
			wait(&status);
			
			if (status == -1)
			{
				perror("Command failed");
				return -1;
			}
		break;
	}

	return 0;
}
