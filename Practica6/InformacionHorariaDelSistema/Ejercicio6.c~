// Para time y localtime
#include <time.h>
// Para printf
#include <stdio.h>

int main( int argc, char **argv )
{
	time_t hora = time(NULL);
	char buffer[25];

	// struct tm *localtime(const time_t *time)
	struct tm *ltime = localtime(&hora);

	printf("-> Estamos en el año %d\n", ltime->tm_year+1900);

	
	// size_t strftime(char *s, size_t max, const char*format, const struct tm *tm)
	strftime(buffer, 25, "-> Hoy es %A, %H:%M", ltime);
	printf("%s\n", buffer);
	
}
