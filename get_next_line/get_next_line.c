/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlibucha <mlibucha@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 22:28:40 by mlibucha          #+#    #+#             */
/*   Updated: 2024/12/29 23:09:28 by mlibucha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_line(t_list *list)
{
	int		str_len;
	char	*next_str;

	if (!list)
		return (NULL);
	str_len = len_to_newline(list);
	next_str = malloc(str_len + 1);
	if (!next_str)
		return (NULL);
	copy_str(list, next_str);
	return (next_str);
}

void	ft_append_nodes(t_list **list, char *buf)
{
	t_list	*new_node;
	t_list	*last_node;

	if (!buf)
		return ;
	new_node = malloc(sizeof(t_list));
	if (!new_node)
	{
		free(buf);
		return ;
	}
	new_node->str_buf = buf;
	new_node->next = NULL;
	if (!*list)
		*list = new_node;
	else
	{
		last_node = find_last_node(*list);
		last_node->next = new_node;
	}
}

void	ft_createlist(t_list **list, int fd)
{
	int		char_read;
	char	*buf;

	while (!found_newline(*list))
	{
		buf = malloc(BUFFER_SIZE + 1);
		if (!buf)
		{
			ft_dealloc(list, NULL, NULL);
			return ;
		}
		char_read = read(fd, buf, BUFFER_SIZE);
		if (char_read <= 0)
		{
			free(buf);
			return ;
		}
		buf[char_read] = '\0';
		ft_append_nodes(list, buf);
	}
}

void	clear_nodes(t_list **list)
{
	t_list	*last_node;
	t_list	*clean_node;
	char	*buf;
	int		i;
	int		k;

	if (!list || !*list)
		return ;
	last_node = find_last_node(*list);
	buf = malloc(BUFFER_SIZE + 1);
	clean_node = malloc(sizeof(t_list));
	if (!buf || !clean_node)
		return (free(buf), free(clean_node), ft_dealloc(list, NULL, NULL));
	i = -1;
	k = 0;
	while (last_node->str_buf[++i] && last_node->str_buf[i] != '\n')
		;
	while (last_node->str_buf[i] && last_node->str_buf[++i])
		buf[k++] = last_node->str_buf[i];
	buf[k] = '\0';
	clean_node->str_buf = buf;
	clean_node->next = NULL;
	ft_dealloc(list, clean_node, buf);
}

char	*get_next_line(int fd)
{
	static t_list	*list = NULL;
	char			*next_line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	ft_createlist(&list, fd);
	if (!list)
		return (NULL);
	next_line = get_line(list);
	clear_nodes(&list);
	return (next_line);
}
