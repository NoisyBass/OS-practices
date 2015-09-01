#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
#include <pwd.h>

int main( int argc, char **argv )
{
	struct passwd *info;
	
	info = getpwuid(getuid());

	printf("-> Nombre de usuario: %s\n",        info->pw_name);
	printf("-> Directorio HOME: %s\n",          info->pw_dir);
	printf("-> Identificador de usuario: %d\n", info->pw_uid);
	printf("-> Nombre real de usuario: %s\n",   info->pw_gecos);

	return 0;
}
