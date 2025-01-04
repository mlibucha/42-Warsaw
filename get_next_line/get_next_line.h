/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlibucha <mlibucha@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 16:23:33 by e                 #+#    #+#             */
/*   Updated: 2024/12/29 23:04:14 by mlibucha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <stdint.h>

typedef struct s_list
{
	char			*str_buf;
	struct s_list	*next;
}				t_list;

char	*get_next_line(int fd);
void	ft_creatlist(t_list **list, int fd);
void	ft_append_nodes(t_list **list, char *buf);
char	*get_line(t_list *list);
int		len_to_newline(t_list *list);
void	copy_str(t_list *list, char *str);
void	clear_nodes(t_list **list);
int		found_newline(t_list *list);
t_list	*find_last_node(t_list *list);
void	ft_dealloc(t_list	**list, t_list *clean_node, char *buf);

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif

#endif