/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: e <e@student.42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 16:36:12 by e                 #+#    #+#             */
/*   Updated: 2025/01/29 16:04:50 by e                ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	error_sig(char *str_n)
{
	if (!(*str_n == '+' || *str_n == '-' || (*str_n >= '0' && *str_n <= '9')))
		return (1);
	if ((*str_n == '+' || *str_n == '-')
		&& !(str_n[1] >= '0' && str_n[1] <= '9'))
		return (1);
	while (*++str_n)
	{
		if (!(*str_n >= '0' && *str_n <= '9'))
			return (1);
	}
	return (0);
}

int	error_duplicate(t_Node *a, int n)
{
	if (!a)
		return (0);
	while (a)
	{
		if (a->number == n)
			return (1);
		a = a->next;
	}
	return (0);
}

void	free_stack(t_Node **stack)
{
	t_Node	*tmp;
	t_Node	*current;

	if (!stack)
		return ;
	current = *stack;
	while (current)
	{
		tmp = current->next;
		current->number = 0;
		free(current);
		current = tmp;
	}
	*stack = NULL;
}

void	free_errors(t_Node **a)
{
	free_stack(a);
	ft_printf("Error\n");
	exit(1);
}
