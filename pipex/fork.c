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

	arg = ft_split(cmd, ' ');
	if (!arg)
	{
		write(2, "ERROR", 5);
		exit(EXIT_FAILURE);
	}
	path = file_path(cmd, envp);
	if (!path)
	{
		ft_free(arg);
		perror("Command not found");
		exit(EXIT_FAILURE);
	}
	if (execve(path, arg, envp) == -1)
	{
		free(path);
		ft_free(arg);
		perror("Error executing command");
		exit(EXIT_FAILURE);
	}
}

void	child_pr1(t_pip pip, int *pipefd, char **envp)
{
	close(pipefd[0]);
	if (dup2(pip.fd1, STDIN_FILENO) == -1)
	{
		perror("dup2 failed for pip.fd1");
		exit(EXIT_FAILURE);
	}
	if (dup2(pipefd[1], STDOUT_FILENO) == -1)
	{
		perror("dup2 failed for pipefd[1]");
		exit(EXIT_FAILURE);
	}
	close(pip.fd1);
	close(pipefd[1]);
	execute_command(pip.cmd1, envp);
}

void	child_pr2(t_pip pip, int *pipefd, char **envp)
{
	close(pipefd[1]);
	if (dup2(pipefd[0], STDIN_FILENO) == -1)
	{
		perror("dup2 failed for pipefd[0]");
		exit(EXIT_FAILURE);
	}
	if (dup2(pip.fd2, STDOUT_FILENO) == -1)
	{
		perror("dup2 failed for pip.fd2");
		exit(EXIT_FAILURE);
	}
	close(pipefd[0]);
	close(pip.fd2);
	execute_command(pip.cmd2, envp);
}

int	forking_your_mom(t_pip pip, char **envp)
{
	int		pipefd[2];
	pid_t	pid1;
	pid_t	pid2;
	int		status;

	if (pipe(pipefd) == -1)
		return (perror("Pipe error"), 1);
	pid1 = fork();
	if (pid1 < 0)
		return (perror("Fork error"), 1);
	if (pid1 == 0)
		child_pr1(pip, pipefd, envp);
	pid2 = fork();
	if (pid2 < 0)
		return (perror("Fork error"), 1);
	if (pid2 == 0)
		child_pr2(pip, pipefd, envp);
	close(pipefd[0]);
	close(pipefd[1]);
	waitpid(pid1, &status, 0);
	waitpid(pid2, &status, 0);
	return (WEXITSTATUS(status));
}
