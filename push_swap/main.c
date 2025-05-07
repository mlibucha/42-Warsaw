/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: e <e@student.42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 16:36:26 by e                 #+#    #+#             */
/*   Updated: 2025/05/03 13:24:20 by e                ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**parse_args(int argc, char **argv)
{
	if (argc == 2)
		return (ft_split(argv[1], ' '));
	return (argv + 1);
}

int	main(int argc, char **argv)
{
	char	**args;
	t_Node	*a;
	t_Node	*b;

	a = NULL;
	b = NULL;
	if (argc < 2 || (argc == 2 && !argv[1][0]))
		return (write(2, "error\n", 6), 1);
	args = parse_args(argc, argv);
	init_stack_a(&a, args);
	if (argc == 2)
		free_split(args);
	if (!stack_sorted(a))
	{
		if (stack_len(a) == 2)
			sa(&a, true);
		else if (stack_len(a) == 3)
			sort_stacks_three(&a);
		else
			sort_stack(&a, &b);
	}
	print_stack(a, "stack after sorting a");
	free_stack(&a);
	return (0);
}
