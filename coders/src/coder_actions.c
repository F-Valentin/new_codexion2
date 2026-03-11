#include <stdbool.h>
#include <stdio.h>
#include "codexion.h"

bool	compiling(t_data *data)
{
	pthread_mutex_lock(&data->log_mutex);
	pthread_mutex_unlock(&data->log_mutex);
}
