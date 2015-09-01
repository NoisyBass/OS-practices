#include <unistd.h>
#include <sys/types>

// Obtencion del UID y GID
uid_t getuid(void);
gid_t getgid(void);

// Obtencion del EUID y EGID
uid_t geteuid(void);
gid_t getegid(void);



#include <pwd.h>
#include <sys/types.h>

// Obtencion de la informacion de usuario accediendo a la base de datos de contraseñas
struct passwd *getpwnam(const char *name);
struct passwd *getpwuid(uid_t uid);

struct passwd {
	char *pw_name; /* Nombre de usuario */
	char *pw_passwd; /* Contraseña */
	uid_t pw_uid; /* Identificador de usuario */
	gid_t pw_gid; /* Identificador de grupo */
	char *pw_gecos; /* Nombre real de usuario */
	char *pw_dir; /* Directorio home */
	char *pw_shell; /* Shell */
}

