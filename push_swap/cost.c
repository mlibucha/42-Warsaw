/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: e <e@student.42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 16:35:56 by e                 #+#    #+#             */
/*   Updated: 2025/01/29 15:34:22 by e                ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	append_node(t_Node **stack, int n)
{
	t_Node	*node;
	t_Node	*last_node;

	if (!stack)
		return ;
	node = malloc(sizeof(t_Node));
	if (!node)
		return ;
	node->next = NULL;
	node->number = n;
	node->cheapest = 0;
	if (!(*stack))
	{
		*stack = node;
		node->prev = NULL;
	}
	else
	{
		last_node = find_last(*stack);
		last_node->next = node;
		node->prev = last_node;
	}
}

void	init_stack_a(t_Node **a, char **argv)
{
	long	n;
	int		i;

	i = 0;
	while (argv[i])
	{
		if (error_sig(argv[i]))
			free_errors(a);
		n = ft_atol(argv[i]);
		if (n > INT_MAX || n < INT_MIN)
			free_errors(a);
		if (error_duplicate(*a, (int)n))
			free_errors(a);
		append_node(a, (int)n);
		i++;
	}
}

t_Node	*get_cheapest(t_Node *stack)
{
	t_Node	*cheapest_node;

	cheapest_node = NULL;
	if (!stack)
		return (NULL);
	while (stack)
	{
		if (stack->cheapest)
		{
			cheapest_node = stack;
			break ;
		}
		stack = stack->next;
	}
	return (cheapest_node);
}

void	prep_push(t_Node **stack, t_Node *top_node, char stack_name)
{
	while (*stack != top_node)
	{
		if (stack_name == 'a')
		{
			if (top_node->median)
				ra(stack, true);
			else
				rra(stack, true);
		}
		else if (stack_name == 'b')
		{
			if (top_node->median)
				rb(stack, true);
			else
				rrb(stack, true);
		}
	}
}
