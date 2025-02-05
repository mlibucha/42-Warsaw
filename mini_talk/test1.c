/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: e <e@student.42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 18:46:20 by e                 #+#    #+#             */
/*   Updated: 2025/01/05 13:44:29 by e                ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_talk.h"

void	handle_signal(int signum, siginfo_t *info, void *context)
{
	static unsigned char	c = 0;
	static int				bits = 0;

	(void)context;
	if (signum == SIGUSR1)
		c |= (1 << (7 - bits));
	bits++;
	if (bits == 8)
	{
		if (c == '\0')
			write(1, "\n", 1);
		else
			write(1, &c, 1);
		c = 0;
		bits = 0;
	}
	if (info && info->si_pid != 0)
	{
		if (kill(info->si_pid, SIGUSR1) == -1)
			printf("Error sending acknowledgment");
	}
}

int	main(void)
{
	struct sigaction	sa;
	pid_t				pid;

	pid = getpid();
	printf("Server Process ID (PID): %d\n", pid);
	sa.sa_sigaction = handle_signal;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	if (sigaction(SIGUSR1, &sa, NULL) == -1 || sigaction(SIGUSR2, &sa, NULL) == -1)
	{
		perror("Error setting up signal handler");
		return (EXIT_FAILURE);
	}
	printf("Server is waiting for signals...\n");
	while (1)
		pause();
	return (EXIT_SUCCESS);
}
