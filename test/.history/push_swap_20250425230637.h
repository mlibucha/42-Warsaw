/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_20250425230637.h                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: e <e@student.42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 23:01:38 by e                 #+#    #+#             */
/*   Updated: 2025/04/26 00:24:10 by e                ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include "../libft/libft.h"

typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*next;
}	t_node;

typedef struct s_stack
{
	t_node	*top;
	int		size;
}	t_stack;

typedef struct s_stacks
{
	t_stack	*a;
	t_stack	*b;
	char	*join_args;
}	t_stacks;

/* Stack operations */
void		swap(t_stack *stack);
void		push(t_stack *src, t_stack *dest);
void		rotate(t_stack *stack);
void		reverse_rotate(t_stack *stack);

/* Command operations */
void		sa(t_stack *a);
void		sb(t_stack *b);
void		ss(t_stack *a, t_stack *b);
void		pa(t_stack *a, t_stack *b);
void		pb(t_stack *a, t_stack *b);
void		ra(t_stack *a);
void		rb(t_stack *b);
void		rr(t_stack *a, t_stack *b);
void		rra(t_stack *a);
void		rrb(t_stack *b);
void		rrr(t_stack *a, t_stack *b);

/* Sorting functions */
void		sort_3(t_stack *a);
void		sort_4_5(t_stack *a, t_stack *b);
void		radix_sort(t_stack *a, t_stack *b);

/* Helper functions */
int			is_sorted(t_stack *stack);
int			get_min(t_stack *stack);
int			get_max(t_stack *stack);
int			find_position(t_stack *stack, int val);
int			get_target_pos(t_stack *a, int b_val);
void		move_to_top(t_stack *stack, int pos, char stack_name);
void		free_stack(t_stack *stack);
void		free_and_exit(t_stacks *stack, char *msg);
void		create_index(t_stack *stack);

/* Parsing and initialization */
void		parse_args(int argc, char **argv, t_stacks *stack);
void		initialize_stack(t_stack *stack, int *nums, int count);
int			*parse_numbers(t_stacks *stack, int *count);
void		validate_args(int argc, char **argv);

#endif