/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enviromentals.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: e <e@student.42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 12:56:16 by estolarc          #+#    #+#             */
/*   Updated: 2025/05/12 19:33:39 by e                ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

// Add prototype at the top
static char	**env_list_to_array(t_env *list);

void	update_env_array(t_mini *mini)
{
	int	i;

	i = 0;
	if (mini->envp)
	{
		while (mini->envp[i])
		{
			free(mini->envp[i]);
			i++;
		}
		free(mini->envp);
	}
	mini->envp = env_list_to_array(mini->env_list);
}

char	*split_key(char *str)
{
	int		i;
	int		j;
	char	*key;

	i = -1;
	key = NULL;
	while (str[++i])
	{
		if (str[i] == '=')
		{
			if (i == 0)
				return (NULL);
			key = malloc(i + 1);
			j = -1;
			while (++j < i)
				key[j] = str[j];
			key[j] = '\0';
			return (key);
		}
	}
	return (key);
}

char	*split_value(char *str)
{
	int		i;
	int		j;
	int		k;
	char	*value;

	j = 0;
	i = -1;
	while (str[++i])
	{
		if (str[i] == '=')
		{
			j = i;
			k = 0;
			while (str[j])
				j++;
			if (j - i < 2)
				return (NULL);
			value = malloc(j - i + 1);
			while (str[++i])
				value[k++] = str[i];
			value[k] = '\0';
			return (value);
		}
	}
	return (NULL);
}

void	add_env(t_env **list, char *key, char *value)
{
	if (key == NULL)
		return;
	if (get_value(list, key) == NULL)
		list_add(list, key, value);
	else
		swap_value(list, key, value);
}

void	del_env(t_env **list, char *key)
{
	if (list == NULL || key == NULL)
		return;
	list_del(list, key);
}

static char	**env_list_to_array(t_env *list)
{
	t_env	*node;
	char	**envp;
	int		count;
	int		i;
	char	*temp;

	count = 0;
	node = list;
	while (node)
	{
		count++;
		node = node->next;
	}
	envp = malloc(sizeof(char *) * (count + 1));
	if (!envp)
		return (NULL);
	node = list;
	i = 0;
	while (node)
	{
		temp = ft_strjoin(node->key, "=");
		envp[i] = ft_strjoin(temp, node->value ? node->value : "");
		free(temp);
		node = node->next;
		i++;
	}
	envp[i] = NULL;
	return (envp);
}

t_env	*init_envs(char **envp, t_mini *mini)
{
	t_env	*list;
	int		i;

	i = -1;
	list = NULL;
	while (envp[++i])
		add_env(&list, split_key(envp[i]), split_value(envp[i]));
	mini->envp = env_list_to_array(list);
	return (list);
}

void	print_envs(t_env **list)
{
	t_env	*node;

	node = *list;
	while (node)
	{
		printf("%s=", node->key);
		if (node->value)
			printf("%s", node->value);
		printf("\n");
		node = node->next;
	}
}