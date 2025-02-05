/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: e <e@student.42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 16:37:06 by e                 #+#    #+#             */
/*   Updated: 2025/01/29 15:33:41 by e                ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_both(t_Node **a, t_Node **b, t_Node *cheapest_node)
{
	while (*b != cheapest_node->target_node && *a != cheapest_node)
		rr(a, b, true);
	current_index(*a);
	current_index(*b);
}

void	rev_rotate_both(t_Node **a, t_Node **b, t_Node *cheapest_node)
{
	while (*b != cheapest_node->target_node && *a != cheapest_node)
		rrr(a, b, true);
	current_index(*a);
	current_index(*b);
}

void	move_ab(t_Node **a, t_Node **b)
{
	t_Node	*cheapest_node;

	cheapest_node = get_cheapest(*a);
	if (!cheapest_node)
		return ;
	if (cheapest_node->median && cheapest_node->target_node->median)
		rotate_both(a, b, cheapest_node);
	else if (!(cheapest_node->median)
		&& !(cheapest_node->target_node->median))
		rev_rotate_both(a, b, cheapest_node);
	prep_push(a, cheapest_node, 'a');
	prep_push(b, cheapest_node->target_node, 'b');
	pb(a, b, true);
}

void	move_ba(t_Node **a, t_Node **b)
{
	if (!(*b))
		return ;
	prep_push(a, (*b)->target_node, 'a');
	pa(a, b, true);
}

void	min_on_top(t_Node **a)
{
	while ((*a)->number != find_min(*a)->number)
	{
		if (find_min(*a)->median)
			ra(a, true);
		else
			rra(a, true);
	}
}
