#include <unistd.h>
#include <stdio.h>
#include <errno.h>

int main (int argc, char **argv)
{
	if (argc != 2)
	{
		printf("¡! Error en el número de argumentos\n");
		return -1;
	}

	execv(argv[1], argv);

	printf("El comando termino de ejecutarse\n");

	return 0;
}
