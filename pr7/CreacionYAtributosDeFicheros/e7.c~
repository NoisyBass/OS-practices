// Atributos de ficheros
#include <sys/types.h>
#include <sys/stat.h>
// printf
#include <stdio.h>
// Fecha
#include <time.h>

int main( int argc, char **argv )
{
	if(argc != 2)
	{
		printf("¡! ERROR: número inválido de argumentos\n");
		return -1;
	}
	
	struct stat buf;
	const char *file_name = argv[1];

	if(stat(file_name, &buf) == -1)
	{
		perror("¡! Error open");
		return -1;
	}

	printf("=> Número major: %i\n", major(buf.st_dev));
	printf("=> Número minor: %i\n", minor(buf.st_dev));
	printf("=> Inodo: %d\n", buf.st_ino);
	printf("=> Hora del último acceso: %s", ctime(&buf.st_atime));
	
	if(S_ISREG(buf.st_mode))
	{
		printf("=> Tipo de fichero: normal\n");
	}
	else if(S_ISDIR(buf.st_mode))
	{
		printf("=> Tipo de fichero: directorio\n");
	}
	else if(S_ISLNK(buf.st_mode))
	{
		printf("=> Tipo de fichero: enlace simbólico\n");
	}

	return 0;
}
