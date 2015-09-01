#include <unistd.h>
#include <stdio.h>

int main( int argc, char **argv )
{
	printf("-> Longitud máxima de los argumentos: %ld\n", sysconf(_SC_ARG_MAX));

	printf("-> Número máximo de hijos: %ld\n", sysconf(_SC_CHILD_MAX));

	printf("-> Número máximo de ficheros abiertos para un proceso: %ld\n", sysconf(_SC_OPEN_MAX));

	return 0;
}
