/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: e <e@student.42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 22:29:08 by mlibucha          #+#    #+#             */
/*   Updated: 2024/12/30 03:00:48 by e                ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

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
void	ft_append_nodes(t_list **list, char *buf, int fd);
char	*get_line(t_list *list);
int		len_to_newline(t_list *list);
void	copy_str(t_list *list, char *str);
void	clear_nodes(t_list **list);
int		found_newline(t_list *list);
t_list	*find_last_node(t_list *list);
void	ft_dealloc(t_list **list, t_list *clean_node, char *buf);

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif

#endif
