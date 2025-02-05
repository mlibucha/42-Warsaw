/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: e <e@student.42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 16:37:12 by e                 #+#    #+#             */
/*   Updated: 2025/01/29 15:33:41 by e                ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_stack(t_Node **a, t_Node **b)
{
	int	len_a;

	len_a = stack_len(*a);
	if (len_a-- > 3 && !stack_sorted(*a))
		pb(a, b, true);
	if (len_a-- > 3 && !stack_sorted(*a))
		pb(a, b, true);
	while (len_a-- > 3 && !stack_sorted(*a))
	{
		init_nodes_a(*a, *b);
		move_ab(a, b);
	}
	sort_three(a);
	while (*b)
	{
		init_nodes_b(*a, *b);
		move_ba(a, b);
	}
	current_index(*a);
	min_on_top(a);
}

int	stack_is_sorted(t_Node *stack)
{
	while (stack && stack->next)
	{
		if (stack->number > stack->next->number)
			return (0);
		stack = stack->next;
	}
	return (1);
}

void	sort_stacks_three(t_Node **stack)
{
	int	first;
	int	second;
	int	third;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	first = (*stack)->number;
	second = (*stack)->next->number;
	third = INT_MIN;
	if ((*stack)->next->next)
		third = (*stack)->next->next->number;
	if (first > second && first > third)
		ra(stack, true);
	else if (second > first && second > third)
		rra(stack, true);
	if ((*stack)->number > (*stack)->next->number)
		sa(stack, true);
}

void	sort_three(t_Node **a)
{
	t_Node	*biggest_node;

	biggest_node = find_max(*a);
	if (biggest_node == *a)
		ra(a, true);
	else if ((*a)->next == biggest_node)
		rra(a, true);
	if ((*a)->number > (*a)->next->number)
		sa(a, true);
}
