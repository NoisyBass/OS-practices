#include <time.h>
#include <stdio.h>

int main( int argc, char **argv )
{
	time_t fecha = time(NULL);

	printf("-> Fecha: %d\n", fecha);
	printf("-> Fecha en un formato legible: %s\n", ctime(&fecha));

	return 0;
}
