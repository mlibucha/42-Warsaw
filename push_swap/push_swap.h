/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: e <e@student.42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 16:36:44 by e                 #+#    #+#             */
/*   Updated: 2025/01/29 16:23:39 by e                ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>
# include <stdbool.h>
# include <limits.h>
# include "print-f/ft_printf.h"

typedef struct s_stack_node
{
	int					number;
	int					index_nbr;
	int					push_cost;
	bool				median;
	bool				cheapest;
	struct s_stack_node	*target_node;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
}	t_Node;

/*
** sort.c
*/
void	sort_stack(t_Node **a, t_Node **b);
int		stack_is_sorted(t_Node *stack);
void	sort_stacks_three(t_Node **stack);
void	sort_three(t_Node **a);

/*
** opti.c
*/
int		stack_len(t_Node *stack);
t_Node	*find_last(t_Node *stack);
bool	stack_sorted(t_Node *stack);
t_Node	*find_min(t_Node *stack);
t_Node	*find_max(t_Node *stack);

/*
** r_ops.c
*/
void	ra(t_Node **a, bool print);
void	rb(t_Node **b, bool print);
void	rr(t_Node **a, t_Node **b, bool print);
void	rra(t_Node **a, bool print);
void	rrb(t_Node **b, bool print);
void	rrr(t_Node **a, t_Node **b, bool print);

/*
** s_and_p.c
*/
void	sa(t_Node **a, bool print);
void	sb(t_Node **b, bool print);
void	ss(t_Node **a, t_Node **b, bool print);
void	pa(t_Node **a, t_Node **b, bool print);
void	pb(t_Node **a, t_Node **b, bool print);

/*
** create.c
*/
void	init_nodes_b(t_Node *a, t_Node *b);
void	current_index(t_Node *stack);
void	init_nodes_a(t_Node *a, t_Node *b);
void	set_cheapest(t_Node *stack);

/*
** cost.c
*/
void	init_stack_a(t_Node **a, char **argv);
t_Node	*get_cheapest(t_Node *stack);
void	prep_push(t_Node **stack, t_Node *top_node, char stack_name);
void	cost_analysis_a(t_Node *a, t_Node *b);
void	set_target_a(t_Node *a, t_Node *b);

/*
** so.c
*/
void	rotate_both(t_Node **a, t_Node **b, t_Node *cheapest_node);
void	rev_rotate_both(t_Node **a, t_Node **b, t_Node *cheapest_node);
void	move_ab(t_Node **a, t_Node **b);
void	move_ba(t_Node **a, t_Node **b);
void	min_on_top(t_Node **a);

/*
** errors.c
*/
int		error_sig(char *str_n);
int		error_duplicate(t_Node *a, int n);
void	free_errors(t_Node **stack);
void	free_stack(t_Node **stack);

/*
** libfun.c
*/
char	**ft_split(char *s, char c);
long	ft_atol(const char *c);
void	print_stack(t_Node *stack, const char *name);

#endif