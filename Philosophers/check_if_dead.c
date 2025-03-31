/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_if_dead.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: e <e@student.42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 19:36:49 by e                 #+#    #+#             */
/*   Updated: 2025/03/31 21:05:25 by e                ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	error_msg(char *msg)
{
	printf(RED "%s\n" RESET, msg);
	return 1;
}

void	print_status(t_philo *philo, char *message, char *color)
{
	pthread_mutex_lock(&philo->data->death_mutex);
	if (!philo->data->someone_died)
	{
		pthread_mutex_lock(&philo->data->print_mutex);
		printf("%lld %s%d %s\n" RESET, 
			   get_timestamp_ms(), color, philo->id, message);
		pthread_mutex_unlock(&philo->data->print_mutex);
	}
	pthread_mutex_unlock(&philo->data->death_mutex);
}

void	print_death(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->print_mutex);
	printf("%lld " RED "%d died\n" RESET, 
		   get_timestamp_ms(), philo->id);
	pthread_mutex_unlock(&philo->data->print_mutex);
}

void	print_all_full(t_data *data)
{
	pthread_mutex_lock(&data->print_mutex);
	printf("%lld " GREEN "All philosophers have eaten enough\n" RESET, 
		   get_timestamp_ms());
	pthread_mutex_unlock(&data->print_mutex);
	pthread_mutex_lock(&data->death_mutex);
	data->someone_died = true;
	pthread_mutex_unlock(&data->death_mutex);
}

void	cleanup(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->num_philosophers)
	{
		pthread_mutex_destroy(&data->forks[i].mutex);
		pthread_mutex_destroy(&data->philos[i].meal_mutex);
		i++;
	}
	pthread_mutex_destroy(&data->print_mutex);
	pthread_mutex_destroy(&data->death_mutex);
	free(data->philos);
	free(data->forks);
}
