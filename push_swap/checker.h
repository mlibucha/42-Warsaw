/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: e <e@student.42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 18:48:45 by e                 #+#    #+#             */
/*   Updated: 2025/01/29 14:27:21 by e                ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "push_swap.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdint.h>
# include <limits.h>

typedef struct s_list
{
	char			*str_buf;
	struct s_list	*next;
}					t_list;

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

int		ft_strcmp(const char *s1, const char *s2);
char	*check_input(t_Node **a, t_Node **b, char *line);
int		ft_strlen(const char *c);
void	clean_line(char *line);

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

#endif
