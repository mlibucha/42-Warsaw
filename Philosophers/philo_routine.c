/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: e <e@student.42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 14:12:47 by e                 #+#    #+#             */
/*   Updated: 2025/03/31 20:52:54 by e                ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void update_meal_info(t_philo *philo)
{
	pthread_mutex_lock(&philo->meal_mutex);
	philo->last_meal_time = get_timestamp_ms();
	philo->meals_eaten++;
	pthread_mutex_unlock(&philo->meal_mutex);
}

void eat(t_philo *philo)
{
	if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(&philo->right_fork->mutex);
		// print_status(philo, "has taken a right fork", "");
		pthread_mutex_lock(&philo->left_fork->mutex);
		// print_status(philo, "has taken a left fork", "");
	}
	else
	{
		pthread_mutex_lock(&philo->left_fork->mutex);
		// print_status(philo, "has taken a left fork", "");
		pthread_mutex_lock(&philo->right_fork->mutex);
		// print_status(philo, "has taken a right fork", "");
	}
	print_status(philo, "has taken a fork", "");
	print_status(philo, "is eating", GREEN);
	update_meal_info(philo);
	usleep(philo->time_to_eat * 1000);
	pthread_mutex_unlock(&philo->left_fork->mutex);
	pthread_mutex_unlock(&philo->right_fork->mutex);
}

void philosopher_cycle(t_philo *philo)
{
	while (!check_death(philo))
	{
		print_status(philo, "is thinking", "");
		eat(philo);
		if (philo->num_meals != -1 && 
			philo->meals_eaten >= philo->num_meals)
		{
			philo->full = true;
			break;
		}
		print_status(philo, "is sleeping", BLUE);
		usleep(philo->time_to_sleep * 1000);
	}
}

void *philosopher_routine(void *arg)
{
	t_philo *philo = (t_philo *)arg;
	
	if (philo->id % 2 == 0)
		usleep(1000);
	philosopher_cycle(philo);
	return NULL;
}
