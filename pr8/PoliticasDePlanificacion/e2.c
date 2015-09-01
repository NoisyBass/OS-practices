#include <sched.h>
#include <stdio.h>

int main (int argc, char **argv)
{
	int sched = sched_getscheduler(0);
	struct sched_param sp;

	switch(sched)
	{
		case SCHED_OTHER: printf("-> Política de planificación: SCHED_OTHER\n"); break;
		case SCHED_FIFO: printf("-> Política de planificación: SCHED_FIFO\n"); break;
		case SCHED_RR: printf("-> Política de planificación: SCHED_RR\n"); break;
		default: break;
	}

	sched_getparam(0, &sp);
	printf("-> Prioridad: %d\n", sp.sched_priority);

	printf("-> Valor máximo de la prioridad para esta política: %d\n", sched_get_priority_max(sched));
	printf("-> Valor mínimo de la prioridad para esta política: %d\n", sched_get_priority_min(sched));

	return 0;
}
