#ifndef MINI_H
# define MINI_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <signal.h>
# include <errno.h>
# include <sys/stat.h>
# include <dirent.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "libft/libft.h"

# define MAX_ARGS 64
# define MAX_PIPES 10

typedef struct s_cmd
{
	char	*args[MAX_ARGS];
	int		argc;
	char	*input;
	char	*output;
	int		append;
}	t_cmd;

typedef struct s_mini
{
	char	**envp;
	char	*path;
	t_cmd	*cmds;
	int		cmd_count;
	int		pipe_count;
	int		status;
	int		last_status;
	char	*full_path;
}	t_mini;

void	set_values(t_mini *mini, char **envp);
void	free_values(t_mini *mini);
int		read_input(t_mini *mini);
int		parse_input(t_mini *mini, char *input);
int		execute_commands(t_mini *mini);
int		execute_command(char **args, t_mini *mini);
int		execute_builtin(t_mini *mini, t_cmd *cmd);
int		handle_redirections(t_cmd *cmd);
void	reset_redirections(t_cmd *cmd);
void	update_path(t_mini *mini);
char	*find_executable(t_mini *mini, char *cmd);

int		mini_exit(t_mini *mini, t_cmd *cmd);
int		mini_cd(t_mini *mini, t_cmd *cmd);
int		mini_pwd(t_mini *mini, t_cmd *cmd);
int		mini_echo(t_mini *mini, t_cmd *cmd);
int		mini_env(t_mini *mini, t_cmd *cmd);
int		mini_export(t_mini *mini, t_cmd *cmd);
int		mini_unset(t_mini *mini, t_cmd *cmd);

char	*ft_strtok(char *str, const char *delim);

#endif