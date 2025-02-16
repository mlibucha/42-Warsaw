/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: e <e@student.42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 14:55:21 by e                 #+#    #+#             */
/*   Updated: 2025/02/15 17:12:24 by e                ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include "print-f/ft_printf.h"

void	handle_ack(int signum)
{
	if (signum == SIGUSR1)
	{
		write(1, "Acknowledgment received from server!\n", 36);
	}
}

static void	send_bit(pid_t pid, int bit)
{
	if (bit)
	{
		if (kill(pid, SIGUSR1) == -1)
		{
			ft_printf("Error sending SIGUSR1\n");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		if (kill(pid, SIGUSR2) == -1)
		{
			ft_printf("Error sending SIGUSR2\n");
			exit(EXIT_FAILURE);
		}
	}
	usleep(50);
}

void	send_message(pid_t pid, const char *message)
{
	unsigned char	c;
	int				i;

	while (*message)
	{
		c = (unsigned char)*message++;
		i = 8;
		while (i--)
			send_bit(pid, (c >> i) & 1);
	}
	c = '\0';
	i = 8;
	while (i--)
		send_bit(pid, (c >> i) & 1);
}

int	ft_atoi(const char *c)
{
	int	a;
	int	j;
	int	res;
	int	si;

	a = 0;
	res = 0;
	j = 0;
	si = 1;
	while (c[a] == ' ' || c[a] == '\t' || c[a] == '\n'
		||c[a] == '\v' || c[a] == '\f' || c[a] == '\r')
		a++;
	while (c[a] == '-' || c[a] == '+')
	{
		if (c[a] == '-')
			si = si * -1;
		a++;
		j++;
	}
	while (c[a] >= '0' && c[a] <= '9')
		res = res * 10 + (c[a++] - '0');
	if (j > 1)
		return (0);
	return (res * si);
}

int	main(int ac, char **av)
{
	pid_t	pid;

	if (ac != 3)
	{
		ft_printf("Usage: %s <PID> <MESSAGE>\n", av[0]);
		return (EXIT_FAILURE);
	}
	pid = (pid_t)ft_atoi(av[1]);
	if (pid <= 0)
	{
		ft_printf("Invalid PID: %s\n", av[1]);
		return (EXIT_FAILURE);
	}
	if (signal(SIGUSR1, handle_ack) == SIG_ERR)
	{
		ft_printf("Error setting up acknowledgment handler\n");
		return (EXIT_FAILURE);
	}
	send_message(pid, av[2]);
	return (EXIT_SUCCESS);
}
