// Duplicacion de Descriptores
#include <unistd.h>
// printf
#include <stdio.h>
// Gestion de errores
#include <errno.h>
#include <stdio.h>
// Apertura de ficheros
#include <sys/types.h>
#include <fcntl.h>

int main( int argc, char **argv )
{
	if(argc != 2)
	{
		printf("¡! ERROR: número inválido de argumentos\n");
		return -1;
	}

	int fd = open(argv[1], O_CREAT | O_RDWR, 0777);
	if(fd == -1)
	{
		perror("¡! Error open");
		return -1;
	}

	// Redirijimos la salida estandar(1) al fichero
	int ds = dup2(fd, 1);
	if(ds == -1)
	{
		perror("¡! Error dup2");
		return -1;
	}

	printf("Probando la redirección de la salida\n");

	// También podemos hacer dup(1)
	dup2(ds, fd);

	return 0;
}
