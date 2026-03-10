#ifndef GETTERS_H
# define GETTERS_H

# include <pthread.h>

long	get_long(long *value, pthread_mutex_t *mutex);
#endif