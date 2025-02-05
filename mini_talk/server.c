/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: e <e@student.42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 15:39:25 by e                 #+#    #+#             */
/*   Updated: 2025/01/01 14:24:57 by e                ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_talk.h"

void	handle_signal(int signum)
{
	static unsigned char	c = 0;
	static int				bits = 0;

	if (signum == SIGUSR1)
		c |= (1 << (7 - bits));
	bits++;
	if (bits == 8)
	{
		if (c == '\0')
		{
			write(1, "\n", 1);
		}
		else
			write(1, &c, 1);
		c = 0;
		bits = 0;
	}
}

int	main(void)
{
	pid_t	pid;

	pid = getpid();
	printf("Process ID (PID): %d\n", pid);
	if (signal(SIGUSR1, handle_signal) == (void (*)(int)) -1
		|| signal(SIGUSR2, handle_signal) == SIG_ERR)
	{
		printf("Error setting signal handler");
		return (EXIT_FAILURE);
	}
	printf("Waiting for signals...\n");
	while (1)
		pause();
	return (EXIT_SUCCESS);
}
