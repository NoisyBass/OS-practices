#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <stdio.h>

int main( int argc, char **argv )
{
	const char *file_name = "prueba750";
	
	// Queremos poner 0750, asi que ponemos lo contrario
	umask(0027);

	if(open(file_name, O_CREAT, 0777) == -1)
	{
		perror("¡! Error en la función open");
		return -1;
	}

	printf("=> Fichero %s creado con éxito\n", file_name);
	
	return 0;
}
