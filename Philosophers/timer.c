/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: e <e@student.42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 11:42:42 by e                 #+#    #+#             */
/*   Updated: 2025/03/31 20:20:52 by e                ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static struct timeval start_time;

void init_timer(void)
{
	gettimeofday(&start_time, NULL);
}

long long get_timestamp_ms(void)
{
	struct timeval current_time;
	long long ms;

	gettimeofday(&current_time, NULL);
	ms = (current_time.tv_sec - start_time.tv_sec) * 1000LL;
	ms += (current_time.tv_usec - start_time.tv_usec) / 1000;
	return (ms);
}
