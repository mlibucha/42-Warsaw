/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: e <e@student.42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 16:36:05 by e                 #+#    #+#             */
/*   Updated: 2025/01/29 16:23:14 by e                ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	set_target_b(t_Node *a, t_Node *b)
{
	t_Node	*current_a;
	t_Node	*target_node;
	long	best_match_index;

	while (b)
	{
		best_match_index = LONG_MAX;
		current_a = a;
		while (current_a)
		{
			if (current_a->number > b->number
				&& current_a->number < best_match_index)
			{
				best_match_index = current_a->number;
				target_node = current_a;
			}
			current_a = current_a->next;
		}
		if (best_match_index == LONG_MAX)
			b->target_node = find_min(a);
		else
			b->target_node = target_node;
		b = b->next;
	}
}

void	init_nodes_b(t_Node *a, t_Node *b)
{
	current_index(a);
	current_index(b);
	set_target_b(a, b);
}

void	current_index(t_Node *stack)
{
	int	i;
	int	median;

	i = 0;
	if (!stack)
		return ;
	median = stack_len(stack) / 2;
	while (stack)
	{
		stack->index_nbr = i;
		if (i <= median)
			stack->median = true;
		else
			stack->median = false;
		stack = stack->next;
		++i;
	}
}

void	set_target_a(t_Node *a, t_Node *b)
{
	t_Node	*current_b;
	t_Node	*target_node;
	long	best_match_index;

	while (a)
	{
		best_match_index = LONG_MIN;
		current_b = b;
		while (current_b)
		{
			if (current_b->number < a->number
				&& current_b->number > best_match_index)
			{
				best_match_index = current_b->number;
				target_node = current_b;
			}
			current_b = current_b->next;
		}
		if (best_match_index == LONG_MIN)
			a->target_node = find_max(b);
		else
			a->target_node = target_node;
		a = a->next;
	}
}

void	cost_analysis_a(t_Node *a, t_Node *b)
{
	int	len_a;
	int	len_b;

	len_a = stack_len(a);
	len_b = stack_len(b);
	while (a)
	{
		a->push_cost = a->index_nbr;
		if (!(a->median))
			a->push_cost = len_a - (a->index_nbr);
		if (a->target_node->median)
			a->push_cost += a->target_node->index_nbr;
		else
			a->push_cost += len_b - (a->target_node->index_nbr);
		a = a->next;
	}
}
