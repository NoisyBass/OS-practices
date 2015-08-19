// Para la gestion de errores
#include <errno.h>
#include <stdio.h>
// Para setuid
#include <sys/types.h>
#include <unistd.h>

int main( int argc, char **argv )
{
	// int setuid(uid_t uid)
	int rc = setuid(0);
	if (rc == -1)
	{
		int errsv = errno;
		// void perror(const char *s)
		perror("Error setuid");
		printf("Código de error: %i\n", errsv);
		return -1;
	}
	return 0;
}
