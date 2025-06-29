/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   one_phil.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: e <e@student.42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 17:23:41 by e                 #+#    #+#             */
/*   Updated: 2025/06/16 17:25:52 by e                ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*single_philosopher_routine(void *arg)
{
	t_philo		*philo;
	long long	start_time;

	philo = (t_philo *)arg;
	start_time = get_timestamp_ms(philo->data);
	pthread_mutex_lock(&philo->left_fork->mutex);
	print_status(philo, "has taken a fork", "");
	while (1)
	{
		if (get_timestamp_ms(philo->data) - start_time >= philo->time_to_die)
		{
			pthread_mutex_lock(&philo->data->death_mutex);
			philo->data->someone_died = true;
			pthread_mutex_unlock(&philo->data->death_mutex);
			print_death(philo);
			pthread_mutex_unlock(&philo->left_fork->mutex);
			return (NULL);
		}
		usleep(1000);
	}
	return (NULL);
}

int	handle_single_philosopher(t_data *data)
{
	if (pthread_create(&data->philos[0].thread, NULL,
			single_philosopher_routine, &data->philos[0]) != 0)
	{
		perror(RED "Failed to create single philosopher thread" RESET);
		return (1);
	}
	pthread_join(data->philos[0].thread, NULL);
	cleanup(data);
	return (0);
}
