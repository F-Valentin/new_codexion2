#include <stdbool.h>
#include "codexion.h"
#include "getters.h"
#include "time.h"

static long	get_elapsed_time(
	long start,
	long *end,
	pthread_mutex_t *mutex
)
{
	return (start - get_long(end, mutex));
}

bool	check_coders_burnout(t_data *data)
{
	int		i;
	long	elapsed;
	long	time;
	t_coder	*coder;

	i = 0;
	while (i < data->number_of_coders)
	{
		coder = &data->coders[i];
		time = get_time_in_ms();
		elapsed = get_elapsed_time(time,
				&coder->last_compile_start, &coder->coder_mutex);
		if (get_long(&coder->compilation_count, &coder->coder_mutex)
			!= get_long(data->number_of_compiles_required, &data->data_mutex)
			&& elapsed >= get_long(&data->time_to_burnout, &data->data_mutex))
			return (true);
		i++;
	}
	return (false);
}
