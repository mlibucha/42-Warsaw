/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: e <e@student.42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 16:50:21 by e                 #+#    #+#             */
/*   Updated: 2025/04/15 00:35:41 by e                ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_strlen(const char *c)
{
	int	a;

	a = 0;
	while (c[a])
		a++;
	return (a);
}

char	*file_path(char *cmd, char **envp)
{
	char	**paths;
	char	*path;
	char	*slash_cmd;
	int		i;

	if (access(cmd, X_OK) == 0)
		return (ft_strdup(cmd));
	while (*envp && ft_strncmp(*envp, "PATH=", 5) != 0)
		envp++;
	if (!*envp)
		return (NULL);
	paths = ft_split(*envp + 5, ':');
	if (!paths)
		return (NULL);
	i = -1;
	while (paths[++i])
	{
		slash_cmd = ft_strjoin("/", cmd);
		path = ft_strjoin(paths[i], slash_cmd);
		free(slash_cmd);
		if (access(path, X_OK) == 0)
		{
			ft_free(paths);
			return (path);
		}
		free(path);
	}
	ft_free(paths);
	return (NULL);
}

void	execute_command(char *cmd, char **envp)
{
	char	*path;
	char	**arg;
	int		exit_code;

	arg = ft_split(cmd, ' ');
	if (!arg || !arg[0])
	{
		if (arg)
			ft_free(arg);
		write(2, "pipex: command not found\n", 25);
		exit(127);
	}
	path = file_path(arg[0], envp);
	if (!path)
	{
		write(2, "pipex: command not found: ", 26);
		write(2, arg[0], ft_strlen(arg[0]));
		write(2, "\n", 1);
		ft_free(arg);
		exit(127);
	}
	if (execve(path, arg, envp) == -1)
	{
		exit_code = 1;
		if (errno == EACCES)
			exit_code = 126;
		perror(arg[0]);
		free(path);
		ft_free(arg);
		exit(exit_code);
	}
}

static int	decode_status(int status)
{
	if (WIFEXITED(status))
		return (WEXITSTATUS(status));
	if (WIFSIGNALED(status))
		return (128 + WTERMSIG(status));
	return (1);
}

static void	child_process(t_pipex *pipex, int in_fd, int *next_pipe, char *cmd,
		char **envp)
{
	if (in_fd < 0)
		exit(1);
	if (dup2(in_fd, STDIN_FILENO) == -1)
	{
		perror("dup2");
		exit(1);
	}
	if (next_pipe)
	{
		if (dup2(next_pipe[1], STDOUT_FILENO) == -1)
		{
			perror("dup2");
			exit(1);
		}
	}
	else
	{
		if (pipex->outfile_fd < 0)
			exit(1);
		if (dup2(pipex->outfile_fd, STDOUT_FILENO) == -1)
		{
			perror("dup2");
			exit(1);
		}
	}
	if (next_pipe)
	{
		close(next_pipe[0]);
		close(next_pipe[1]);
	}
	close(in_fd);
	if (pipex->outfile_fd >= 0)
		close(pipex->outfile_fd);
	execute_command(cmd, envp);
}

int	execute_pipeline(t_pipex *pipex, char **argv, char **envp)
{
	int		current;
	int		next_pipe[2];
	int		children;
	int		status;
	int		last_status;
	int		in_fd;
	pid_t	last_pid;
	pid_t	pid;
	pid_t	waited;

	current = pipex->cmd_start;
	in_fd = pipex->infile_fd;
	children = pipex->cmd_end - pipex->cmd_start + 1;
	last_status = 1;
	last_pid = -1;
	while (current <= pipex->cmd_end)
	{
		if (current < pipex->cmd_end && pipe(next_pipe) == -1)
			return (perror("pipe"), 1);
		pid = fork();
		if (pid < 0)
			return (perror("fork"), 1);
		if (pid == 0)
		{
			if (current < pipex->cmd_end)
				child_process(pipex, in_fd, next_pipe, argv[current], envp);
			else
				child_process(pipex, in_fd, NULL, argv[current], envp);
		}
		if (current == pipex->cmd_end)
			last_pid = pid;
		if (in_fd >= 0)
			close(in_fd);
		if (current < pipex->cmd_end)
		{
			close(next_pipe[1]);
			in_fd = next_pipe[0];
		}
		current++;
	}
	while (children > 0)
	{
		waited = wait(&status);
		if (waited < 0)
			break ;
		if (waited == last_pid)
			last_status = status;
		children--;
	}
	return (decode_status(last_status));
}
