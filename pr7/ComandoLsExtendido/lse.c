// printf
#include <stdio.h>
// Acceso a directorios
#include <sys/types.h>
#include <dirent.h>
// Gestion de errores
#include <errno.h>
// Permisos
#include <unistd.h>
// Atributos de Ficheros
#include <sys/stat.h>

int main( int argc, char **argv )
{
	if(argc != 2)
	{
		printf("¡! ERROR: número inválido de argumentos\n");
		return -1;
	}

	DIR *dir;

	dir = opendir(argv[1]);
	if(!dir)
	{
		perror("¡! Error opendir");
		return -1;
	}
	printf("Directorio %s abierto correctamente\n", argv[1]);
	/*******************************************************/

	struct dirent *entradadir;
	int tamdir = 0;
	struct stat buf;
	const int tamlink = 1000;
	char buflink[tamlink];
	
	entradadir = readdir(dir);
	while(entradadir)
	{
		if(lstat(entradadir->d_name, &buf) == -1)
		{
			perror("¡! Error lstat");
			return -1;
		}

		if(entradadir->d_type == DT_REG)
		{
			tamdir+=buf.st_size;
			
			if(access(entradadir->d_name, X_OK) == 0)
			{
				printf("=> [ %s* ] Fichero ejecutable %d\n", entradadir->d_name, buf.st_size);
			}
			else
			{
				printf("=> [ %s ] Fichero regular %d\n", entradadir->d_name, buf.st_size);
			}
		}
		else if(entradadir->d_type == DT_DIR)
		{
			tamdir+=buf.st_size;
			
			printf("=> [ %s/ ] Directorio %d\n", entradadir->d_name, buf.st_size);
		}
		else if(entradadir->d_type == DT_LNK)
		{
			tamdir+=buf.st_size;
			
			int tam = readlink(entradadir->d_name, buflink, tamlink);
			if(tam == -1)
			{
				perror("¡! Error readlink");
				return -1;
			}
			
			buflink[tam] = '\0';
			printf("=> [ %s->%s ] Enlace simbólico %d\n", entradadir->d_name, buflink, buf.st_size);
		}

		entradadir = readdir(dir);
	}

	printf("Tamaño total del directorio: %i bytes\n", tamdir);

	/*******************************************************/
	if(closedir(dir) == -1)
	{
		perror("¡! Error closedir");
		return -1;
	}
	
	printf("Directorio %s cerrado correctamente\n", argv[1]);
}
