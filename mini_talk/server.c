/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: e <e@student.42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 14:55:10 by e                 #+#    #+#             */
/*   Updated: 2025/02/15 17:12:16 by e                ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include "print-f/ft_printf.h"

void	handle_signal(int signum, siginfo_t *info, void *context)
{
	static unsigned char	c = 0;
	static int				bits = 0;
	static pid_t			client_pid = 0;

	(void)context;
	if (!client_pid)
		client_pid = info->si_pid;
	if (signum == SIGUSR1)
		c |= (1 << (7 - bits));
	bits++;
	if (bits == 8)
	{
		if (c == '\0')
		{
			write(1, "\n", 1);
			write(1, "Message received completely!\n", 29);
			kill(client_pid, SIGUSR1);
			client_pid = 0;
		}
		else
			write(1, &c, 1);
		c = 0;
		bits = 0;
	}
}

int	main(void)
{
	struct sigaction	sa;
	pid_t				pid;

	pid = getpid();
	ft_printf("Server Process ID (PID): %d\n", pid);
	sa.sa_sigaction = handle_signal;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	if (sigaction(SIGUSR1, &sa, NULL) == -1
		|| sigaction(SIGUSR2, &sa, NULL) == -1)
	{
		perror("Error setting up signal handler");
		return (EXIT_FAILURE);
	}
	ft_printf("Server is waiting for signals...\n");
	while (1)
		;
	return (EXIT_SUCCESS);
}
