/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: e <e@student.42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 22:29:00 by mlibucha          #+#    #+#             */
/*   Updated: 2025/01/29 01:59:05 by e                ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	copy_str(t_list *list, char *str)
{
	int	i;
	int	k;

	if (!list || !str)
		return ;
	k = 0;
	while (list)
	{
		i = 0;
		while (list->str_buf[i])
		{
			if (list->str_buf[i] == '\n')
			{
				str[k++] = '\n';
				str[k] = '\0';
				return ;
			}
			str[k++] = list->str_buf[i++];
		}
		list = list->next;
	}
	str[k] = '\0';
}

t_list	*find_last_node(t_list *list)
{
	if (!list)
		return (NULL);
	while (list->next)
		list = list->next;
	return (list);
}

void	ft_dealloc(t_list **list, t_list *clean_node, char *buf)
{
	t_list	*tmp;

	if (!list || !(*list))
		return ;
	while (*list)
	{
		tmp = (*list)->next;
		free((*list)->str_buf);
		free(*list);
		*list = tmp;
	}
	*list = NULL;
	if (clean_node && clean_node->str_buf[0])
		*list = clean_node;
	else
	{
		free(buf);
		free(clean_node);
	}
}

int	found_newline(t_list *list)
{
	int	i;

	while (list)
	{
		i = 0;
		while (list->str_buf[i])
		{
			if (list->str_buf[i] == '\n')
				return (1);
			i++;
		}
		list = list->next;
	}
	return (0);
}

int	len_to_newline(t_list *list)
{
	int	i;
	int	len;

	len = 0;
	while (list)
	{
		i = 0;
		while (list->str_buf[i])
		{
			if (list->str_buf[i] == '\n')
				return (++len);
			len++;
			i++;
		}
		list = list->next;
	}
	return (len);
}
