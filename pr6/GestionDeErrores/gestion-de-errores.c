#include <errno.h>
#include <stdio.h>

/* Imprime por pantalla un mensaje de error perteneciente a la ultima 
 llamada al sistema realizada */
void perror (const char *s);

/* Variables */
const char *sys_errlist[];
int sys_nerr;
int errno; // Código de error
