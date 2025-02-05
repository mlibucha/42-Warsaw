/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test2c.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: e <e@student.42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 18:44:43 by e                 #+#    #+#             */
/*   Updated: 2025/01/29 20:03:44 by e                ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_talk.h"

volatile sig_atomic_t ack_received = 0;
volatile sig_atomic_t ack_printed = 0;

static void handle_ack(int signum)
{
	(void)signum;
	static int a = 0;

 	if (!ack_printed && a == 0) 
 	{
		
		printf("Acknowledgment received from server\n");
		ack_printed = 1;
		a == 1;
	}
	ack_received = 1;
}

static void send_bit(pid_t pid, int bit)
{
	ack_received = 0;

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
	while (!ack_received)
		usleep(100);
}

void send_message(pid_t pid, const char *message)
{
	unsigned char c;
	int i;

	ack_printed = 0;
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

int main(int ac, char **av)
{
	pid_t pid;
	int a;
	int b;

	a = 2;
	b = ac - 2;
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
	if (signal(SIGUSR1, handle_ack) == SIG_ERR)
	{
		printf("Error setting up acknowledgment handler");
		return (EXIT_FAILURE);
	}
	while (b-- > 0)
	{
		send_message(pid, av[a]);
		printf("Message sent to PID %d: \"%s\"\n", pid, av[a]);
		a++;
	}
	return (EXIT_SUCCESS);
}
