/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: e <e@student.42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 01:11:04 by e                 #+#    #+#             */
/*   Updated: 2025/01/29 16:04:50 by e                ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_Node *stack, const char *text)
{
	t_Node	*current;

	current = stack;
	ft_printf ("%s: ", text);
	while (current)
	{
		ft_printf("%d ", current->number);
		current = current->next;
	}
	ft_printf ("\n");
}

void	rrr(t_Node **a, t_Node **b, bool print)
{
	rra(a, false);
	rrb(b, false);
	if (print)
		ft_printf("rrr\n");
}

void	set_cheapest(t_Node *stack)
{
	long	cheapest_value;
	t_Node	*cheapest_node;

	if (!stack)
		return ;
	cheapest_value = LONG_MAX;
	while (stack)
	{
		if (stack->push_cost < cheapest_value)
		{
			cheapest_value = stack->push_cost;
			cheapest_node = stack;
		}
		stack = stack->next;
	}
	if (cheapest_node)
		cheapest_node->cheapest = true;
}

void	init_nodes_a(t_Node *a, t_Node *b)
{
	current_index(a);
	current_index(b);
	set_target_a(a, b);
	cost_analysis_a(a, b);
	set_cheapest(a);
}
