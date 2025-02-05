/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkermain.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: e <e@student.42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 14:15:50 by e                 #+#    #+#             */
/*   Updated: 2025/01/29 16:04:50 by e                ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	main(int argc, char **argv)
{
	t_Node	*a;
	t_Node	*b;
	char	*line;

	a = NULL;
	b = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);
	else if (argc == 2)
		argv = ft_split(argv[1], ' ');
	init_stack_a(&a, argv + 1);
	line = get_next_line(0);
	while (line)
	{
		clean_line(line);
		line = check_input(&a, &b, line);
	}
	if (!stack_sorted(a) || stack_len(b) != 0)
		ft_printf("KO\n");
	else
		ft_printf("OK\n");
	free_stack(&a);
	free_stack(&b);
	return (0);
}
