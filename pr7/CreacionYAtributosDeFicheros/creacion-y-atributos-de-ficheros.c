#include <sys/types>
#include <sys/stat>
#include <fcntl.h>

// Apertura y/o creacion de un archivo a dispositivo
// Permisos = mode & (~umask)
int open(const char *file_name, int flags);
int open(const char *file_name, int flags, mode_t mode);

/* Flags:
	O_RDONLY: solo lectura
	O_WRONLY: solo escritura
	O_RDWR: lectura y escritura
	O_CREAT: si el archivo no existe lo crea (con los permisos de mode)
	O_EXCL: usado en combinacion con O_CREAT provoca un error si el archivo existe
	O_TRUNC: una vez abierto el archivo puede ser truncado (a pesar de O_RDONLY)
	O_APPEND: antes de realizar cualquier escritura se posiciona el puntero de archivo en la ultima posicion del fichero
	O_NONBLOCK: abre el archivo en modo no bloqueante
	O_SYNC: abre el archivo en modo sincrono, bloqueando las llamadas write hasta que los datos sean fisicamente escritos
*/

// Creacion de la mascara de permisos para la apertura de ficheros (cmask & 0777)
mode_t umask(mode_t cmask);

// Obtencion del estado de un fichero
int stat(const char *file_name, struct stat *buf);

// Obtencion del estado de ficheros y links
int lstat(const char *file_name, struct stat *buf);

// Obtencion del estado de ficheros mediante descriptores
int fstat(int filedes, struct stat *buf);

struct stat {
	dev_t st_dev; /* Dispositivo */
	ino_t st_ino; /* I-nodo */
	mode_t st_mode; /* Permisos */
	nlink_t st_link; /* Enlaces simbolicos (hard) */
	uid_t st_uid; /* UID del propietario */
	gid_t st_gid; /* GID del propietario */
	dev_t st_rdev; /* Tipo de dispositivo (major+minor) */
	off_t st_size; /* Tamaño (bytes) */
	unsigned long st_blksize; /* Tamaño de bloque E/S */
	unsigned long st_blocks; /* Bloques reservados */
	time_t st_atime; /* Ultimo acceso */
	time_t st_mtime; /* Ultima modificacion */
	time_t st_ctime; /* Ultimo cambio (I-nodo) */
}
