#include <errno.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main( int argc, char **argv )
{
	if (setuid(0) == -1)
	{
		printf("¡! Error en la función setuid\n");
		return -1;
	}
	return 0;
}
