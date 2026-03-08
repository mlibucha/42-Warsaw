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

static int	is_here_doc(char *arg)
{
	if (ft_strlen(arg) != 8)
		return (0);
	return (ft_strncmp(arg, "here_doc", 9) == 0);
}

static int	line_is_limiter(char *line, char *limiter)
{
	int	i;

	i = 0;
	while (line[i] && limiter[i] && line[i] == limiter[i])
		i++;
	if (line[i] == '\0' && limiter[i] == '\0')
		return (1);
	return (0);
}

static char	*read_stdin_line(void)
{
	char	*line;
	char	c;
	int		i;
	int		bytes;

	line = malloc(10000);
	if (!line)
		return (NULL);
	i = 0;
	bytes = read(STDIN_FILENO, &c, 1);
	while (bytes > 0)
	{
		if (c == '\n')
			break ;
		if (i < 9999)
			line[i++] = c;
		bytes = read(STDIN_FILENO, &c, 1);
	}
	if (bytes <= 0 && i == 0)
		return (free(line), NULL);
	line[i] = '\0';
	return (line);
}

static int	setup_here_doc(char *limiter)
{
	int		pfd[2];
	char	*line;

	if (pipe(pfd) == -1)
		return (perror("pipe"), -1);
	line = read_stdin_line();
	while (line)
	{
		if (line_is_limiter(line, limiter))
		{
			free(line);
			break ;
		}
		write(pfd[1], line, ft_strlen(line));
		write(pfd[1], "\n", 1);
		free(line);
		line = read_stdin_line();
	}
	close(pfd[1]);
	return (pfd[0]);
}

static int	init_pipex(t_pipex *pipex, int argc, char **argv)
{
	if (argc < 5)
		return (write(2, "Usage: ./pipex file1 cmd1 ... cmdn file2\n", 40), 1);
	pipex->here_doc = is_here_doc(argv[1]);
	if (pipex->here_doc)
	{
		if (argc < 6)
			return (write(2, "Usage: ./pipex here_doc LIMITER cmd1 cmd2 file\n", 47), 1);
		pipex->cmd_start = 3;
		pipex->cmd_end = argc - 2;
		pipex->infile_fd = setup_here_doc(argv[2]);
		pipex->outfile_fd = open(argv[argc - 1], O_WRONLY | O_CREAT | O_APPEND, 0644);
	}
	else
	{
		pipex->cmd_start = 2;
		pipex->cmd_end = argc - 2;
		pipex->infile_fd = open(argv[1], O_RDONLY);
		if (pipex->infile_fd < 0)
			perror(argv[1]);
		pipex->outfile_fd = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	}
	if (pipex->outfile_fd < 0)
		perror(argv[argc - 1]);
	return (0);
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex	pipex;
	int		status;

	if (init_pipex(&pipex, argc, argv) != 0)
		return (1);
	status = execute_pipeline(&pipex, argv, envp);
	if (pipex.infile_fd >= 0)
		close(pipex.infile_fd);
	if (pipex.outfile_fd >= 0)
		close(pipex.outfile_fd);
	return (status);
}
