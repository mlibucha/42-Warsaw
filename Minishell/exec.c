#include "mini.h"

char    *ft_strtok(char *str, const char *delim)
{
	static char *save_ptr = NULL;
	char        *token_start;
	char        *token_end;

	if (str != NULL)
		save_ptr = str;
	if (save_ptr == NULL || *save_ptr == '\0')
		return (NULL);
	while (*save_ptr && ft_strchr(delim, *save_ptr))
		save_ptr++;
	if (*save_ptr == '\0')
		return (NULL);
	token_start = save_ptr;
	token_end = save_ptr;
	while (*token_end && !ft_strchr(delim, *token_end))
		token_end++;
	if (*token_end != '\0')
	{
		*token_end = '\0';
		save_ptr = token_end + 1;
	}
	else
		save_ptr = token_end;
	return (token_start);
}

void update_path(t_mini *mini)
{
	char *pwd = getcwd(NULL, 0);
	if (!pwd)
	{
		ft_putstr_fd("mini: error: cannot get current directory: ", STDERR_FILENO);
		ft_putendl_fd(strerror(errno), STDERR_FILENO);
		mini->status = 1;
		return;
	}
	free(mini->path);
	mini->path = pwd;
	mini->status = 0;
}

int	handle_redirections(t_cmd *cmd)
{
	int	fd;

	if (cmd->input)
	{
		fd = open(cmd->input, O_RDONLY);
		if (fd < 0)
		{
			perror("mini: open input");
			return (1);
		}
		dup2(fd, STDIN_FILENO);
		close(fd);
	}
	if (cmd->output)
	{
		fd = open(cmd->output, O_WRONLY | O_CREAT | (cmd->append ? O_APPEND : O_TRUNC), 0644);
		if (fd < 0)
		{
			perror("mini: open output");
			return (1);
		}
		dup2(fd, STDOUT_FILENO);
		close(fd);
	}
	return (0);
}

char *find_executable(t_mini *mini, char *cmd)
{
	char    *path;
	char    *path_copy;
	char    *dir;
	char    *full_path;
	size_t  len;

	if (ft_strchr(cmd, '/'))
	{
		if (access(cmd, X_OK) == 0)
			return (ft_strdup(cmd));
		return (NULL);
	}
	path = getenv("PATH");
	if (!path)
		return (NULL);
	path_copy = ft_strdup(path);
	dir = ft_strtok(path_copy, ":");
	while (dir)
	{
		len = ft_strlen(dir) + ft_strlen(cmd) + 2;
		full_path = malloc(len);
		if (!full_path)
			break ;
		ft_strlcpy(full_path, dir, len);
		ft_strlcat(full_path, "/", len);
		ft_strlcat(full_path, cmd, len);
		mini->full_path = full_path;
		if (access(full_path, X_OK) == 0)
		{
			free(path_copy);
			return (full_path);
		}
		free(full_path);
		dir = ft_strtok(NULL, ":");
	}
	free(path_copy);
	return (NULL);
}

int	execute_command(char **args, t_mini *mini)
{
	pid_t	pid;
	int		status;
	char	*path;

	pid = fork();
	if (pid == 0)
	{
		if (handle_redirections(mini->cmds) != 0)
			exit(EXIT_FAILURE);
		path = find_executable(mini, args[0]);
		if (!path)
		{
			ft_putstr_fd("mini: command not found: ", 2);
			ft_putendl_fd(args[0], 2);
			exit(127);
		}
		// write(1, "\033[32mmini> \033[0m", 15);
		execve(path, args, mini->envp);
		perror("mini");
		free(path);
		exit(EXIT_FAILURE);
	}
	else if (pid < 0)
	{
		perror("mini: fork");
		return (1);
	}
	waitpid(pid, &status, 0);
	if (WIFEXITED(status))
		return (WEXITSTATUS(status));
	return (1);
}