#include "push_swap.h"

void	validate_args(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		if (!argv[i][0])
			free_and_exit(NULL, "Error");
		while (argv[i][j])
		{
			if (!ft_isdigit(argv[i][j]) && argv[i][j] != '-' && argv[i][j] != '+')
				free_and_exit(NULL, "Error");
			if ((argv[i][j] == '-' || argv[i][j] == '+') && !ft_isdigit(argv[i][j+1]))
				free_and_exit(NULL, "Error");
			j++;
		}
		i++;
	}
}

void	parse_args(int argc, char **argv, t_stacks *stack)
{
	char	*tmp;
	char	*tmp2;
	int		i;

	i = 1;
	tmp2 = ft_strdup("");
	while (i < argc)
	{
		tmp = ft_strjoin(tmp2, argv[i]);
		free(tmp2);
		if (i != argc - 1)
		{
			tmp2 = ft_strjoin(tmp, " ");
			free(tmp);
			tmp = tmp2;
		}
		i++;
	}
	stack->join_args = tmp;
}

int	*parse_numbers(t_stacks *stack, int *count)
{
	char	**split;
	int		*nums;
	int		i;

	split = ft_split(stack->join_args, ' ');
	*count = 0;
	while (split[*count])
		(*count)++;
	nums = malloc(*count * sizeof(int));
	if (!nums)
		free_and_exit(stack, "Error");
	i = 0;
	while (i < *count)
	{
		nums[i] = ft_atoi(split[i]);
		free(split[i]);
		i++;
	}
	free(split);
	return (nums);
}

void fill_stack(t_stack *stack, int *tablica, int count)
{
	int		i;
	t_node	*new;

	i = count - 1;
	while (i >= 0)
	{
		new = malloc(sizeof(t_node));
		if (!new)
			exit(1);
		new->value = tablica[i];
		new->index = 0;
		new->next = stack->top;
		stack->top = new;
		stack->size++;
		i--;
	}
}