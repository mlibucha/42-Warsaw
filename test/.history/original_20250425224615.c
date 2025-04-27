#include "push_swap.h"

void	swap(t_stack *stack)
{
	t_node	*first;
	t_node	*second;

	if (!stack->top || !stack->top->next)
		return ;
	first = stack->top;
	second = stack->top->next;
	first->next = second->next;
	second->next = first;
	stack->top = second;
}

void	push(t_stack *src, t_stack *dest)
{
	t_node	*tmp;

	if (!src->top)
		return ;
	tmp = src->top;
	src->top = src->top->next;
	tmp->next = dest->top;
	dest->top = tmp;
	dest->size++;
	src->size--;
}

void	rotate(t_stack *stack)
{
	t_node	*tmp;
	t_node	*last;

	if (!stack->top || !stack->top->next)
		return ;
	tmp = stack->top;
	stack->top = stack->top->next;
	tmp->next = NULL;
	last = stack->top;
	while (last->next)
		last = last->next;
	last->next = tmp;
}

void	reverse_rotate(t_stack *stack)
{
	t_node	*prev;
	t_node	*curr;

	if (!stack->top || !stack->top->next)
		return ;
	prev = NULL;
	curr = stack->top;
	while (curr->next)
	{
		prev = curr;
		curr = curr->next;
	}
	prev->next = NULL;
	curr->next = stack->top;
	stack->top = curr;
}

void	free_stack(t_stack *stack)
{
	t_node	*current;
	t_node	*next;

	current = stack->top;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
	stack->top = NULL;
	stack->size = 0;
}