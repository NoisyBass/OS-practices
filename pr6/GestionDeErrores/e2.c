#include <errno.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main( int argc, char **argv )
{
	if (setuid(0) == -1)
	{
		perror("¡! Error en la función setuid");
		printf("=> Código de error: %i\n", errno);
		return -1;
	}
	return 0;
}
