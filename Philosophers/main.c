/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: e <e@student.42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 17:54:52 by e                 #+#    #+#             */
/*   Updated: 2025/03/31 20:21:49 by e                ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int main(int argc, char **argv)
{
	t_data data;

	init_timer();
	if (init_data(&data, argc, argv) != 0)
		return 1;
	if (create_threads(&data) != 0)
		return 1;
	int i = 0;
	while (i < data.num_philosophers)
	{
		pthread_mutex_destroy(&data.forks[i].mutex);
		i++;
	}
	free(data.philos);
	free(data.forks);
	return 0;
}

