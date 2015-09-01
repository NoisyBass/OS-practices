#include <time.h>
#include <stdio.h>

int main( int argc, char **argv )
{
	time_t fecha = time(NULL);

	printf("-> Fecha: %d\n", fecha);

	return 0;
}
