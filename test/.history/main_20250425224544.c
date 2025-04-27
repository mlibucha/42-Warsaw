#include "push_swap.h"

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
	if (!is_sorted(stack->a))
	{
		if (stack->a->size == 2)
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