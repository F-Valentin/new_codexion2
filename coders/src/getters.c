#include "getters.h"

long	get_long(long *value, pthread_mutex_t *mutex)
{
	long	v;

	pthread_mutex_lock(mutex);
	v = *value;
	pthread_mutex_unlock(mutex);
	return (v);
}
