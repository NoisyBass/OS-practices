// Para uname
#include <sys/utsname.h>
// Para la gestion de errores
#include <errno.h>
#include <stdio.h>

int main( int argc, char **argv )
{
	struct utsname buffer;

	// int uname(struct utsname *buffer)
	if (uname(&buffer) == -1)
	{
		// void perror(const char *s)
		perror("Error uname");
		printf("Código de error: %i\n", errno);
		return -1;
	}
	
	printf("-> Nombre del sistema: %s\n", buffer.sysname);
	printf("-> Nombre de la máquina: %s\n", buffer.nodename);
	printf("-> Release: %s\n", buffer.release);
	printf("-> Versión: %s\n", buffer.version);
	printf("-> Hardware: %s\n", buffer.machine);

	return 0;
}

