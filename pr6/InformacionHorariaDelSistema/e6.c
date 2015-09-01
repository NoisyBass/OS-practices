#include <time.h>
#include <stdio.h>

int main( int argc, char **argv )
{
	time_t hora = time(NULL);
	char buffer[25];

	struct tm *ltime = localtime(&hora);

	printf("-> Estamos en el año %d\n", ltime->tm_year+1900);

	strftime(buffer, 25, "-> Today is %A, %H:%M", ltime);
	printf("%s\n", buffer);
	
	return 0;
}
