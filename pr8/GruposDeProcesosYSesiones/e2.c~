#include <unistd.h>
#include <sys/time.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/resource.h>

int main (int argc, char **argv)
{
	pid_t pid = getpid();
	struct rlimit rlim;
	int size = 100;
	char buffer[size];
	

	printf("-> Identificador: %d\n", pid);
	printf("-> Identificador de grupo: %d\n", getpgid(pid));
	printf("-> Identificador de sesión: %d\n", getsid(pid));
	
	getrlimit(RLIMIT_NOFILE, &rlim);
	printf("-> Max num de descriptores de archivo: %d\n", rlim.rlim_cur);

	printf("-> Directorio de trabajo %s\n", getcwd(&buffer, size));

	return 0;
}
