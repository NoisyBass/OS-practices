#include <unistd.h>
#include <sys/time.h>
#include <stdio.h>

int main( int argc, char **argv )
{
	int i = 0;
	struct timeval tinicial;
	struct timeval tfinal;

	gettimeofday(&tinicial, NULL);
	while (i < 10000)
	{
		i++;
	}
	gettimeofday(&tfinal, NULL);

	printf("-> El bucle ha tardado %d segundos y %d microsegundos\n", tfinal.tv_sec-tinicial.tv_sec, tfinal.tv_usec-tinicial.tv_usec);

	return 0;
}
