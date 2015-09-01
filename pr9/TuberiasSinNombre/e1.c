#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>
#include <sys/wait.h>
// Tuberias sin nombre
#include <unistd.h>
// Gestion de errores
#include <errno.h>
#include <stdio.h>

#define PADRE 1
#define HIJO 0

int main (int argc, char **argv)
{
	int tuberia[2];
	pid_t pid;
	
	pipe(tuberias);

	pid = fork();

	if(pid == -1)
	{
		perror("¡! Error fork");
		return -1;
	}
	else if(pid == 0) // HIJO
	{	
		printf("Ejecutando el proceso hijo...");
		close(tuberia[PADRE]);
		dup2(tuberia[HIJO], 0);
		close(tuberia[HIJO]);
		execlp(argv[3], argv[3], argv[4], NULL);
	}
	else // PADRE
	{
		printf("Ejecutando el proceso padre...");
		close(tuberia[HIJO]);
		dup2(tuberia[PADRE], 1);
		close(tuberia[PADRE]);
		execlp(argv[1], argv[1], argv[2], NULL);
	}
	waitpid(pid, NULL, 0);
	return(0);
}
