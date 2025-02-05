/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: e <e@student.42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 15:39:25 by e                 #+#    #+#             */
/*   Updated: 2025/01/03 14:39:01 by e                ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_talk.h"

static void	send_bit(pid_t pid, int bit)
{
	if (bit)
	{
		if (kill(pid, SIGUSR1) == -1)
		{
			printf("Error sending SIGUSR1");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		if (kill(pid, SIGUSR2) == -1)
		{
			printf("Error sending SIGUSR2");
			exit(EXIT_FAILURE);
		}
	}
	usleep(500);
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
	i = 8;
	while (i--)
		send_bit(pid, 0);
}

int	main(int ac, char **av)
{
	pid_t	pid;
	int		a;
	int		b;

	if (ac < 3)
	{
		printf("Usage: %s <PID> <MESSAGE>...\n", av[0]);
		return (EXIT_FAILURE);
	}
	pid = (pid_t)atoi(av[1]);
	if (pid <= 0)
	{
		printf("Invalid PID: %s\n", av[1]);
		return (EXIT_FAILURE);
	}
	a = 2;
	b = ac - 2;
	while (b-- > 0)
	{
		send_message(pid, av[a]);
		// printf("Message sent to PID %d: \"%s\"\n", pid, av[a]);
		a++;
	}
	return (EXIT_SUCCESS);
}
