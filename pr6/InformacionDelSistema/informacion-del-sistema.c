#include <sys/utsname.h>

// Obtencion de informacion sobre el kernel actual
int uname (struct utsname *buffer);

// La informacion se devuelve en la estructura buffer, de la forma: 
struct utsname {
	char sysname[SYS_NMLN];
	char nodename[SYS_NMLN];
	char release[SYS_NMLN];
	char version[SYS_NMLN];
	char machine[SYS_NMLN];
}


#include <unistd.h>

// Obtencion de informacion sobre el sistema operativo
long sysconf (int name);

/* Donde el argumento name puede ser:
	-> _SC_ARG_MAX: Longitud maxima de los argumentos de las funciones exec()
	-> _SC_CLK_TCK: Numero de ticks de reloj por segundo (Hz)
	-> _SC_OPEN_MAX: Numero maximo de ficheros que puede abrir el proceso
	-> _SC_PAGESIZE: Tamaño de pagina (bytes)
	-> _SC_CHILD_MAX: Numero maximo de procesos simultaneos por usuario
*/


#include <unistd.h>

// Obtencion de infomacion sobre el sistema de ficheros
long pathconf (char *path, int name);
long fpathconf(int filedes, int name);

/* Donde el argumento name puede ser:
	-> _PC_LINK_MAX: Numero maximo de enlaces al archivo/directorio
	-> _PC_NAME_MAX: Longitud maxima del nombre de archivo en el directorio indicado por path
	-> _PC_PATH_MAX: Longitud maxima del path relativo
	-> _PC_CHOWN_RESTRICTED: Devuelve un valor no nulo si no puede efectuarse un cambio de permisos sobre el archivo
	-> _PC_PIPE_BUF: Tamaño del pipe asociado a path o filedes
*/



















	
