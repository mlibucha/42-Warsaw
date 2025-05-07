#include "mini.h"

static int	parse_to_cmd(t_mini *mini, char **args)
{
	t_cmd	*cmd;
	int		i;

	cmd = malloc(sizeof(t_cmd));
	if (!cmd)
		return (1);
	ft_memset(cmd, 0, sizeof(t_cmd));
	i = 0;
	while (args[i] && i < MAX_ARGS - 1)
	{
		cmd->args[i] = args[i];
		i++;
	}
	cmd->argc = i;
	cmd->args[i] = NULL;
	mini->cmds = cmd;
	return (execute_builtin(mini, cmd));
}

int	check_input(char *input, t_mini *mini)
{
	char	**args;
	int		ret;

	args = ft_split(input, ' ');
	if (!args)
		return (1);
	ret = parse_to_cmd(mini, args);
	if (ret == 0 || ret == 1)
	{
		ft_free(args);
		return (ret);
	}
	ret = execute_command(args, mini);
	ft_free(args);
	free(mini->cmds);
	mini->cmds = NULL;
	return (ret);
}

int	read_input(t_mini *mini)
{
	char	*input;

	update_path(mini);
	using_history();
	while (1)
	{
		input = readline("\033[32mmini> \033[0m");
		if (!input)
		{
			ft_putendl_fd("exit", 1);
			break ;
		}
		if (*input)
		{
			add_history(input);
			check_input(input, mini);
		}
		free(input);
	}
	return (0);
}