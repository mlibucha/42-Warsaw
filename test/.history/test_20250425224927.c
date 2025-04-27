#include "push_swap.h"
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