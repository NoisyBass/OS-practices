// Control de ficheros
#include <unistd.h>
#include <fcntl.h>
// printf
#include <stdio.h>
// Gestion de errores
#include <errno.h>
// Apertura de ficheros
#include <sys/types.h>

int main( int argc, char **argv )
{
	if(argc != 2)
	{
		printf("¡! ERROR: número inválido de argumentos\n");
		return -1;
	}
	
	int fd;
	struct flock fl;

	fd = open(argv[1], O_CREAT | O_RDWR, 0777);

	if(fd == -1)
	{
		perror("¡! Error open");
		return -1;
	}

	if(fcntl(fd, F_GETLK, &fl) == -1)
	{
		perror("¡! Error fcntl");
		return -1;
	}

	// Ya tenemos el cerrojo, ahora tenemos que comprobar de que tipo es
	if(fl.l_type == F_WRLCK)
	{
		printf("El proceso %ld ya tiene un cerrojo de escritura\n", fl.l_pid);
		return(0);
	}
	else if(fl.l_type == F_RDLCK)
	{
		printf("El proceso %ld ya tiene un cerrojo de lectura\n", fl.l_pid);
		return(0);
	}
	else // No tiene cerrojo
	{
		printf("El proceso %ld no tiene cerrojo\n", fl.l_pid);
		
		fl.l_type = F_WRLCK;
		if(fcntl(fd, F_SETLK, &fl) == -1)
		{
			perror("¡! Error fcntl");
			return -1;
		}

		printf("He cogido el cerrojo\n");
		sleep(30);
		
		fl.l_type = F_UNLCK;
		if(fcntl(fd, F_SETLK, &fl) == -1)
		{
			perror("¡! Error fcntl");
			return -1;
		}

		printf("He soltado el cerrojo\n");
	}
	close(fd);
	return 0;
	
}
