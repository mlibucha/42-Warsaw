#include "push_swap.h"
#include "push_swap.h"

/* Helper functions */
int	is_sorted(t_stack *stack)
{
	t_node	*current;

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

void	free_and_exit(t_stacks *stack, char *msg)
{
	if (msg)
		ft_putendl_fd(msg, 2);
	if (stack)
	{
		if (stack->a)
			free_stack(stack->a);
		if (stack->b)
			free_stack(stack->b);
		if (stack->join_args)
			free(stack->join_args);
		free(stack);
	}
	exit(1);
}

int	main(int argc, char **argv)
{
	t_stacks	*stack;
	int			*nums;
	int			count;

	validate_args(argc, argv);
	stack = malloc(sizeof(t_stacks));
	if (!stack)
		exit(1);
	stack->a = malloc(sizeof(t_stack));
	stack->b = malloc(sizeof(t_stack));
	if (!stack->a || !stack->b)
		free_and_exit(stack, "Error");
	stack->a->top = NULL;
	stack->a->size = 0;
	stack->b->top = NULL;
	stack->b->size = 0;
	stack->join_args = NULL;
	parse_args(argc, argv, stack);
	nums = parse_numbers(stack, &count);
	initialize_stack(stack->a, nums, count);
	free(nums);
	create_index(stack->a);
	if (!is_sorted(stack->a))//to dodale aby odrazu sprawdzic czy nie jest posortowany
	{
		if (stack->a->size == 2)//zamiast swap_2 poprostu sa
			sa(stack->a);
		else if (stack->a->size == 3)
			sort_3(stack->a);
		else if (stack->a->size <= 5)
			sort_4_5(stack->a, stack->b);
		else
			radix_sort(stack->a, stack->b);
	}
	free_and_exit(stack, NULL);
	return (0);
}