#include <time.h>

// Tiempo en segundos desde el 1 de enero de 1970
time_t time(time_t *t);


#include <unistd.h>
#include <sys/time.h>

// Funciones para fijar y obtener la fecha del sistema:
int gettimeofday(struct timeval *tv, struct timezone *tz);
int settimeofday(const struct timeval *tv, const struct timezone *tz);

struct timeval {
	long tv_sec; /* segundos */
	long tv_usec; /* microsegundos */
}

// El campo timezone es un campo obsoleto que nunca debe ser utilizado



#include <time.h>

// Conversion de la informacion temporal a cadena:
char *ctime(const time_t *time);

// Coordinate Universal Time (UTC)
struct tm *gmtime(const time_t *time);

// Tiempo relativo a la zona horaria especificada
struct tm *localtime8const time_t *time);

struct tm {
	int tm_sec; /* segundos 0-59 */
	int tm_min; /* minutos 0-59 */
	int tm_hour; /* horas 0-23 */
	int tm_mday; /* dia del mes 1-31 */
	int tm_mon; /* mes 0-11 */
	int tm_year; /* años desde 1900 */
	int tm_wday; /* dia de la semana 0-6 */
	int tm_yday; /* dia del año 0-365 */
	int tm_isdst; /* ahorro de energia */
}



#include <time.h>

// Conversion de la informacuion temporal a cadena a medida:
size_t strftime(char *s, size_t max, const char *format, const struct tm *tm);

/* El parametro format es una cadena donde:
	%a: dia de la semana abreviado
	%A: dia de la semana completo
	%b: mes abreviado
	%B: mes completo
	%d: dia del mes en decimal
	%H: hora en decimal(24)
	%I: hora en decimal(12)
	%M: minutos en decimal
	%S: segundos en decimal
	%n: retorno de carro
	%p: PM, AM
	%r: la hora en am/pm = "%I:%M:%S %p"
*/
