#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <stdio.h>

int main( int argc, char **argv )
{
	const char *file_name = "prueba";

	if(open(file_name, O_CREAT, 00645) == -1)
	{
		perror("¡! Error en la función open");
		return -1;
	}

	printf("=> Fichero %s creado con éxito\n", file_name);
	
	return 0;
}
