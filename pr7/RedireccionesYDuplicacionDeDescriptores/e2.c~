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
	int dstd = dup2(fd, 1);
	if(dstd == -1)
	{
		perror("¡! Error dup2");
		return -1;
	}
	// Ahora redirijimos también la salida de error(2) al fichero
	int derror = dup2(fd, 2);
	if(derror == -1)
	{
		perror("¡! Error dup2");
		return -1;
	}

	printf("Probando la redirección de la salida estandar\n");
	perror("Probando la redirección de la salida de error\n");

	// También podemos hacer dup(1)
	dup2(dstd, fd);
	dup2(derror, fd);

	return 0;
}
