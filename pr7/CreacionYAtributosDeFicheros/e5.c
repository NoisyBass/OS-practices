#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <stdio.h>

int main( int argc, char **argv )
{
	const char *file_name = "prueba645";
	
	// Queremos poner 0645, asi que ponemos lo contrario
	mode_t old_mask = umask(0132);

	if(open(file_name, O_CREAT, 0777) == -1)
	{
		umask(old_mask);
		perror("¡! Error open");
		return -1;
	}

	umask(old_mask);
	printf("=> Fichero %s creado con éxito\n", file_name);
	
	return 0;
}
