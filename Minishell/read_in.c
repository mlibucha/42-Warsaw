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

static int is_special_char(char c)
{
    return (c == '|' || c == '<' || c == '>');
}

static char **split_special_chars(char *token)
{
    char **result = malloc(sizeof(char *) * 4);
    int i = 0;

    if (!result)
        return NULL;

    // Find first special character
    while (token[i] && !is_special_char(token[i]))
        i++;

    if (token[i]) // Found a special character
    {
        if (i > 0)
        {
            result[0] = ft_substr(token, 0, i);
            result[1] = ft_substr(token, i, 1);
            if (token[i+1])
                result[2] = ft_strdup(token + i + 1);
            else
                result[2] = NULL;
        }
        else // Special character at start
        {
            result[0] = ft_substr(token, 0, 1);
            if (token[1])
                result[1] = ft_strdup(token + 1);
            else
                result[1] = NULL;
            result[2] = NULL;
        }
    }
    else // No special characters found
    {
        result[0] = ft_strdup(token);
        result[1] = NULL;
        result[2] = NULL;
    }
    result[3] = NULL;
    return result;
}

static char **tokenize_input(char *input)
{
    char **space_tokens = ft_split(input, ' ');
    char **final_tokens = NULL;
    char **temp;
    char **sub_tokens;
    int count = 0;
    int i, j;

    if (!space_tokens)
        return NULL;

    // First count total tokens after full tokenization
    for (i = 0; space_tokens[i]; i++)
    {
        temp = split_special_chars(space_tokens[i]);
        for (j = 0; temp[j]; j++)
            count++;
        ft_free(temp);
    }

    // Allocate space for all tokens
    final_tokens = malloc(sizeof(char *) * (count + 1));
    if (!final_tokens)
    {
        ft_free(space_tokens);
        return NULL;
    }

    // Now populate the final tokens array
    count = 0;
    for (i = 0; space_tokens[i]; i++)
    {
        sub_tokens = split_special_chars(space_tokens[i]);
        for (j = 0; sub_tokens[j]; j++)
        {
            final_tokens[count++] = sub_tokens[j];
        }
        free(sub_tokens); // Just free the array, not the strings
    }
    final_tokens[count] = NULL;

    ft_free(space_tokens);
    return final_tokens;
}

int check_input(char *input, t_mini *mini)
{
    char **args;
    int ret;

    args = tokenize_input(input);
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