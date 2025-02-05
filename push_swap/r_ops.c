/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_ops.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: e <e@student.42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 16:36:51 by e                 #+#    #+#             */
/*   Updated: 2025/01/29 16:04:50 by e                ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_Node **a, bool print)
{
	t_Node	*first;
	t_Node	*last;

	if (!a || !(*a) || !(*a)->next)
		return ;
	first = *a;
	last = *a;
	while (last->next)
		last = last->next;
	*a = first->next;
	first->next = NULL;
	last->next = first;
	if (print)
		ft_printf("ra\n");
}

void	rb(t_Node **b, bool print)
{
	t_Node	*first;
	t_Node	*last;

	if (!b || !(*b) || !(*b)->next)
		return ;
	first = *b;
	last = *b;
	while (last->next)
		last = last->next;
	*b = first->next;
	first->next = NULL;
	last->next = first;
	if (print)
		ft_printf("rb\n");
}

void	rr(t_Node **a, t_Node **b, bool print)
{
	ra(a, false);
	rb(b, false);
	if (print)
		ft_printf("rr\n");
}

void	rra(t_Node **a, bool print)
{
	t_Node	*prev;
	t_Node	*last;

	if (!a || !(*a) || !(*a)->next)
		return ;
	prev = NULL;
	last = *a;
	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	prev->next = NULL;
	last->next = *a;
	*a = last;
	if (print)
		ft_printf("rra\n");
}

void	rrb(t_Node **b, bool print)
{
	t_Node	*prev;
	t_Node	*last;

	if (!b || !(*b) || !(*b)->next)
		return ;
	last = *b;
	prev = NULL;
	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	prev->next = NULL;
	last->next = *b;
	*b = last;
	if (print)
		ft_printf("rrb\n");
}
