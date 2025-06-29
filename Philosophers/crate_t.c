/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   crate_t.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: e <e@student.42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 17:55:03 by e                 #+#    #+#             */
/*   Updated: 2025/06/16 17:25:05 by e                ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	assign_data(t_data *data, int argc, char **argv)
{
	int	i;

	i = 0;
	while (i < data->num_phil)
	{
		data->philos[i].id = i + 1;
		data->philos[i].left_fork = &data->forks[i];
		data->philos[i].right_fork = &data->forks[(i + 1) % data->num_phil];
		data->philos[i].time_to_eat = ft_atoi(argv[3]);
		data->philos[i].time_to_sleep = ft_atoi(argv[4]);
		data->philos[i].time_to_die = ft_atoi(argv[2]);
		data->philos[i].last_meal_time = get_timestamp_ms(data);
		data->philos[i].meals_eaten = 0;
		data->philos[i].full = false;
		data->philos[i].data = data;
		if (argc == 6)
			data->philos[i].num_meals = ft_atoi(argv[5]);
		else
			data->philos[i].num_meals = -1;
		pthread_mutex_init(&data->philos[i].meal_mutex, NULL);
		i++;
	}
	pthread_mutex_init(&data->print_mutex, NULL);
	pthread_mutex_init(&data->death_mutex, NULL);
	data->someone_died = false;
}

int	init_data(t_data *data, int argc, char **argv)
{
	int	i;

	if (argc < 5 || argc > 6)
	{
		printf(RED "Incorrect amount of arguments\n");
		return (1);
	}
	if (check_input(argc, argv) != 0)
		return (1);
	data->num_phil = ft_atoi(argv[1]);
	data->philos = malloc(sizeof(t_philo) * data->num_phil);
	data->forks = malloc(sizeof(t_fork) * data->num_phil);
	if (!data->philos || !data->forks)
	{
		printf(RED "Error: Memory allocation failed.\n");
		return (1);
	}
	i = 0;
	while (i < data->num_phil)
	{
		pthread_mutex_init(&data->forks[i].mutex, NULL);
		i++;
	}
	assign_data(data, argc, argv);
	return (0);
}

int	create_threads(t_data *data)
{
	int			i;
	pthread_t	monitor_thread;

	data->start_time = get_timestamp_ms(data);
	if (data->num_phil == 1)
		return (handle_single_philosopher(data));
	if (pthread_create(&monitor_thread, NULL, monitor_routine, data) != 0)
		return (perror(RED "Failed to create monitor thread" RESET), 1);
	i = 0;
	while (i < data->num_phil)
	{
		if (pthread_create(&data->philos[i].thread,
				NULL, philosopher_routine, &data->philos[i]) != 0)
			return (perror(RED "Failed to create thread" RESET), 1);
		i++;
	}
	pthread_join(monitor_thread, NULL);
	i = 0;
	while (i < data->num_phil)
	{
		pthread_join(data->philos[i].thread, NULL);
		i++;
	}
	cleanup(data);
	return (0);
}
