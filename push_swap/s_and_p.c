/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_and_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: e <e@student.42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 16:36:58 by e                 #+#    #+#             */
/*   Updated: 2025/01/29 16:04:50 by e                ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_Node **a, bool print)
{
	t_Node	*first;
	t_Node	*second;

	if (!a || !(*a) || !(*a)->next)
		return ;
	first = *a;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*a = second;
	if (print)
		ft_printf("sa\n");
}

void	sb(t_Node **b, bool print)
{
	t_Node	*first;
	t_Node	*second;

	if (!b || !(*b) || !(*b)->next)
		return ;
	first = *b;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*b = second;
	if (print)
		ft_printf("sb\n");
}

void	ss(t_Node **a, t_Node **b, bool print)
{
	sa(a, false);
	sb(b, false);
	if (print)
		ft_printf("ss\n");
}

void	pb(t_Node **a, t_Node **b, bool print)
{
	t_Node	*temp;

	if (!a || !(*a))
		return ;
	temp = *a;
	*a = (*a)->next;
	temp->next = *b;
	*b = temp;
	if (print)
		ft_printf("pb\n");
}

void	pa(t_Node **a, t_Node **b, bool print)
{
	t_Node	*temp;

	if (!b || !(*b))
		return ;
	temp = *b;
	*b = (*b)->next;
	temp->next = *a;
	*a = temp;
	if (print)
		ft_printf("pa\n");
}

