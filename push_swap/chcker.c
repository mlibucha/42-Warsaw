/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chcker.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: e <e@student.42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 14:23:40 by e                 #+#    #+#             */
/*   Updated: 2025/01/29 16:04:50 by e                ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	ft_strlen(const char *c)
{
	int	a;

	a = 0;
	while (c[a] != '\0')
	{
		a++;
	}
	return (a);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	a;

	a = 0;
	while ((s1[a] != '\0' || s2[a] != '\0'))
	{
		if (s1[a] != s2[a])
			return ((unsigned char)s1[a] - (unsigned char)s2[a]);
		a++;
	}
	return (0);
}

void	clean_line(char *line)
{
	size_t	len;

	if (!line)
		return ;
	len = ft_strlen(line);
	if (len > 0 && line[len - 1] == '\n')
		line[len - 1] = '\0';
}

static int	execute_command(t_Node **a, t_Node **b, char *line)
{
	if (!ft_strcmp(line, "sa"))
		sa(a, false);
	else if (!ft_strcmp(line, "sb"))
		sb(b, false);
	else if (!ft_strcmp(line, "ss"))
		ss(a, b, false);
	else if (!ft_strcmp(line, "pa"))
		pa(a, b, false);
	else if (!ft_strcmp(line, "pb"))
		pb(a, b, false);
	else if (!ft_strcmp(line, "ra"))
		ra(a, false);
	else if (!ft_strcmp(line, "rb"))
		rb(b, false);
	else if (!ft_strcmp(line, "rr"))
		rr(a, b, false);
	else if (!ft_strcmp(line, "rra"))
		rra(a, false);
	else if (!ft_strcmp(line, "rrb"))
		rrb(b, false);
	else if (!ft_strcmp(line, "rrr"))
		rrr(a, b, false);
	else
		return (0);
	return (1);
}

char	*check_input(t_Node **a, t_Node **b, char *line)
{
	if (!execute_command(a, b, line))
		ft_printf("Error: Unknown operation %s\n", line);
	free(line);
	return (get_next_line(0));
}
