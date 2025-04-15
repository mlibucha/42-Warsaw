/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: e <e@student.42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 14:30:31 by e                 #+#    #+#             */
/*   Updated: 2025/04/15 00:17:06 by e                ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

void	data_in(t_pip *pip, char **argv)
{
	pip->cmd1 = argv[2];
	pip->cmd2 = argv[3];
	pip->file1 = argv[1];
	pip->file2 = argv[4];
}

int	main(int argc, char **argv, char **envp)
{
	t_pip	pip;
	int		status;

	if (argc != 5)
		return (write(2, "Error: incorrect number of arguments\n", 37), 2);
	data_in(&pip, argv);
	pip.fd1 = open(pip.file1, O_RDONLY);
	if (pip.fd1 < 0)
	{
		perror("Error opening input file");
		exit(EXIT_FAILURE);
	}
	pip.fd2 = open(pip.file2, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (pip.fd2 < 0)
	{
		close(pip.fd1);
		perror("Error opening output file");
		exit(EXIT_FAILURE);
	}
	status = forking_your_mom(pip, envp);
	close(pip.fd1);
	close(pip.fd2);
	return (status);
}
