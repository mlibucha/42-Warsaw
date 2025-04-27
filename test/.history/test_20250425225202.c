#include "push_swap.h"

#include "push_swap.h"

/* Basic stack operations (already shown previously) */
void	swap(t_stack *stack) { /* ... */ }
void	push(t_stack *src, t_stack *dest) { /* ... */ }
void	rotate(t_stack *stack) { /* ... */ }
void	reverse_rotate(t_stack *stack) { /* ... */ }

/* Command operations with write */
void	sa(t_stack *a)
{
	if (a->size > 1)
	{
		swap(a);
		write(1, "sa\n", 3);
	}
}

void	sb(t_stack *b)
{
	if (b->size > 1)
	{
		swap(b);
		write(1, "sb\n", 3);
	}
}

void	ss(t_stack *a, t_stack *b)
{
	if (a->size > 1 && b->size > 1)
	{
		swap(a);
		swap(b);
		write(1, "ss\n", 3);
	}
}

void	pa(t_stack *a, t_stack *b)
{
	if (b->size > 0)
	{
		push(b, a);
		write(1, "pa\n", 3);
	}
}

void	pb(t_stack *a, t_stack *b)
{
	if (a->size > 0)
	{
		push(a, b);
		write(1, "pb\n", 3);
	}
}

void	ra(t_stack *a)
{
	if (a->size > 1)
	{
		rotate(a);
		write(1, "ra\n", 3);
	}
}

void	rb(t_stack *b)
{
	if (b->size > 1)
	{
		rotate(b);
		write(1, "rb\n", 3);
	}
}

void	rr(t_stack *a, t_stack *b)
{
	if (a->size > 1 && b->size > 1)
	{
		rotate(a);
		rotate(b);
		write(1, "rr\n", 3);
	}
}

void	rra(t_stack *a)
{
	if (a->size > 1)
	{
		reverse_rotate(a);
		write(1, "rra\n", 4);
	}
}

void	rrb(t_stack *b)
{
	if (b->size > 1)
	{
		reverse_rotate(b);
		write(1, "rrb\n", 4);
	}
}

void	rrr(t_stack *a, t_stack *b)
{
	if (a->size > 1 && b->size > 1)
	{
		reverse_rotate(a);
		reverse_rotate(b);
		write(1, "rrr\n", 4);
	}
}

/* Helper functions */
int	is_sorted(t_stack *stack)
{
	t_node	*current;

	if (!stack->top)
		return (1);
	current = stack->top;
	while (current->next)
	{
		if (current->value > current->next->value)
			return (0);
		current = current->next;
	}
	return (1);
}

int	get_min(t_stack *stack)
{
	t_node	*current;
	int		min;

	if (!stack->top)
		return (0);
	current = stack->top;
	min = current->value;
	while (current)
	{
		if (current->value < min)
			min = current->value;
		current = current->next;
	}
	return (min);
}

int	get_max(t_stack *stack)
{
	t_node	*current;
	int		max;

	if (!stack->top)
		return (0);
	current = stack->top;
	max = current->value;
	while (current)
	{
		if (current->value > max)
			max = current->value;
		current = current->next;
	}
	return (max);
}

#include "push_swap.h"

void	create_index(t_stack *stack)
{
	t_node	*current;
	t_node	*compare;
	int		index;

	current = stack->top;
	while (current)
	{
		index = 0;
		compare = stack->top;
		while (compare)
		{
			if (current->value > compare->value)
				index++;
			compare = compare->next;
		}
		current->index = index;
		current = current->next;
	}
}

int	get_target_pos(t_stack *a, int b_val)
{
	t_node	*current;
	int		target_pos;
	int		min_diff;
	int		diff;

	target_pos = 0;
	min_diff = INT_MAX;
	current = a->top;
	while (current)
	{
		diff = current->value - b_val;
		if (diff > 0 && diff < min_diff)
		{
			min_diff = diff;
			target_pos = find_position(a, current->value);
		}
		current = current->next;
	}
	if (min_diff == INT_MAX)
		target_pos = find_position(a, get_min(a));
	return (target_pos);
}

void	move_to_top(t_stack *stack, int pos, char stack_name)
{
	int	size;
	int	moves;

	size = stack->size;
	moves = 0;
	if (pos <= size / 2)
	{
		moves = pos;
		while (moves-- > 0)
		{
			if (stack_name == 'a')
				ra(stack);
			else
				rb(stack);
		}
	}
	else
	{
		moves = size - pos;
		while (moves-- > 0)
		{
			if (stack_name == 'a')
				rra(stack);
			else
				rrb(stack);
		}
	}
}

int	find_position(t_stack *stack, int val)
{
	t_node	*current;
	int		pos;

	current = stack->top;
	pos = 0;
	while (current)
	{
		if (current->value == val)
			return (pos);
		pos++;
		current = current->next;
	}
	return (-1);
}
void swap(t_stack *stack) {
    if (!stack->top || !stack->top->next) return;
    t_node *first = stack->top;
    t_node *second = stack->top->next;
    first->next = second->next;
    second->next = first;
    stack->top = second;
}

void push(t_stack *src, t_stack *dest) {
    if (!src->top) return;
    t_node *temp = src->top;
    src->top = src->top->next;
    temp->next = dest->top;
    dest->top = temp;
    dest->size++;
    src->size--;
}

void rotate(t_stack *stack) {
    if (!stack->top || !stack->top->next) return;
    t_node *temp = stack->top;
    stack->top = stack->top->next;
    temp->next = NULL;
    t_node *current = stack->top;
    while (current->next) current = current->next;
    current->next = temp;
}

void reverse_rotate(t_stack *stack) {
    if (!stack->top || !stack->top->next) return;
    t_node *current = stack->top;
    while (current->next->next) current = current->next;
    t_node *temp = current->next;
    current->next = NULL;
    temp->next = stack->top;
    stack->top = temp;
}

/* Command operations */
void sa(t_stack *a) { if (a->size >= 2) { swap(a); write(1, "sa\n", 3); } }
void sb(t_stack *b) { if (b->size >= 2) { swap(b); write(1, "sb\n", 3); } }
void ss(t_stack *a, t_stack *b) { if (a->size >= 2 && b->size >= 2) { swap(a); swap(b); write(1, "ss\n", 3); } }
void pa(t_stack *a, t_stack *b) { if (b->size > 0) { push(b, a); write(1, "pa\n", 3); } }
void pb(t_stack *a, t_stack *b) { if (a->size > 0) { push(a, b); write(1, "pb\n", 3); } }
void ra(t_stack *a) { if (a->size >= 2) { rotate(a); write(1, "ra\n", 3); } }
void rb(t_stack *b) { if (b->size >= 2) { rotate(b); write(1, "rb\n", 3); } }
void rr(t_stack *a, t_stack *b) { if (a->size >= 2 && b->size >= 2) { rotate(a); rotate(b); write(1, "rr\n", 3); } }
void rra(t_stack *a) { if (a->size >= 2) { reverse_rotate(a); write(1, "rra\n", 4); } }
void rrb(t_stack *b) { if (b->size >= 2) { reverse_rotate(b); write(1, "rrb\n", 4); } }
void rrr(t_stack *a, t_stack *b) { if (a->size >= 2 && b->size >= 2) { reverse_rotate(a); reverse_rotate(b); write(1, "rrr\n", 4); } }

void	sort_3(t_stack *a)
{
	int	first;
	int	second;
	int	third;

	first = a->top->value;
	second = a->top->next->value;
	third = a->top->next->next->value;
	if (first > second && second < third && first < third)
		sa(a);
	else if (first > second && second > third)
	{
		sa(a);
		rra(a);
	}
	else if (first > second && second < third && first > third)
		ra(a);
	else if (first < second && second > third && first < third)
	{
		sa(a);
		ra(a);
	}
	else if (first < second && second > third && first > third)
		rra(a);
}

void	sort_4_5(t_stack *a, t_stack *b)
{
	int	min;
	int	i;
	int	size;

	size = a->size;
	i = 0;
	while (i++ < size - 3)
	{
		min = get_min(a);
		while (a->top->value != min)
		{
			if (find_position(a, min) <= a->size / 2)
				ra(a);
			else
				rra(a);
		}
		pb(a, b);
	}
	sort_3(a);
	while (b->size > 0)
		pa(a, b);
}

void	radix_sort(t_stack *a, t_stack *b)
{
	int	max_num;
	int	max_bits;
	int	i;
	int	j;
	int	size;

	max_num = a->size - 1;
	max_bits = 0;
	while ((max_num >> max_bits) != 0)
		max_bits++;
	i = -1;
	while (++i < max_bits)
	{
		j = -1;
		size = a->size;
		while (++j < size)
		{
			if (((a->top->index >> i) & 1) == 1)
				ra(a);
			else
				pb(a, b);
		}
		while (b->size > 0)
			pa(a, b);
	}
}