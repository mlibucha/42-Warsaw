/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_monitor.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: e <e@student.42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 13:07:21 by e                 #+#    #+#             */
/*   Updated: 2025/03/31 20:24:31 by e                ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

#include "philo.h"

bool check_death(t_philo *philo)
{
	bool    someone_died;

	pthread_mutex_lock(&philo->data->death_mutex);
	someone_died = philo->data->someone_died;
	pthread_mutex_unlock(&philo->data->death_mutex);
	return (someone_died);
}

int check_philosopher_death(t_data *data, int i)
{
	long long time_since_last_meal;

	pthread_mutex_lock(&data->philos[i].meal_mutex);
	time_since_last_meal = get_timestamp_ms() - data->philos[i].last_meal_time;
	if (time_since_last_meal > data->philos[i].time_to_die)
	{
		pthread_mutex_lock(&data->death_mutex);
		if (!data->someone_died)
		{
			data->someone_died = true;
			print_death(&data->philos[i]);
		}
		pthread_mutex_unlock(&data->death_mutex);
		pthread_mutex_unlock(&data->philos[i].meal_mutex);
		return 1;
	}
	pthread_mutex_unlock(&data->philos[i].meal_mutex);
	return 0;
}

int check_all_full(t_data *data)
{
	int i;
	int all_full;

	all_full = 1;
	i = 0;
	while (i < data->num_philosophers)
	{
		pthread_mutex_lock(&data->philos[i].meal_mutex);
		if (data->philos[i].num_meals != -1 && 
			data->philos[i].meals_eaten < data->philos[i].num_meals)
			all_full = 0;
		pthread_mutex_unlock(&data->philos[i].meal_mutex);
		i++;
	}
	return (all_full);
}

void *monitor_routine(void *arg)
{
	t_data *data = (t_data *)arg;
	int i;

	while (1)
	{
		i = 0;
		while (i < data->num_philosophers)
		{
			if (check_philosopher_death(data, i))
				return NULL;
			i++;
		}
		if (data->philos[0].num_meals != -1 && check_all_full(data))
		{
			print_all_full(data);
			return NULL;
		}
		usleep(1000);
	}
}
