/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: e <e@student.42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 11:42:42 by e                 #+#    #+#             */
/*   Updated: 2025/04/29 12:11:43 by e                ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void init_timer(t_data *data)
{
	gettimeofday(&data->start_timeval, NULL);
}


long long get_timestamp_ms(t_data *data)
{
	struct timeval current_time;
	long long ms;

	gettimeofday(&current_time, NULL);
	ms = (current_time.tv_sec - data->start_timeval.tv_sec) * 1000LL;
	ms += (current_time.tv_usec - data->start_timeval.tv_usec) / 1000;
	return (ms);
}

void    ft_usleep(t_data *data, unsigned long long time_to_sleep)
{
	struct timeval  start;
	struct timeval  current;
	unsigned long long elapsed;
	unsigned long long remaining;

	gettimeofday(&start, NULL);
	while (1)
	{
		// Check if someone died (optional early exit)
		pthread_mutex_lock(&data->death_mutex);
		if (data->someone_died)
		{
			pthread_mutex_unlock(&data->death_mutex);
			break;
		}
		pthread_mutex_unlock(&data->death_mutex);

		// Check elapsed time
		gettimeofday(&current, NULL);
		elapsed = (current.tv_sec - start.tv_sec) * 1000000 + 
				 (current.tv_usec - start.tv_usec);
		
		if (elapsed >= time_to_sleep)
			break;
		
		// Calculate remaining time and sleep efficiently
		remaining = time_to_sleep - elapsed;
		if (remaining > 1000)
			usleep(remaining / 2);  // Sleep half remaining time
		else
			usleep(remaining);       // For small durations, sleep directly
	}
}
