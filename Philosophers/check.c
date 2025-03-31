/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: e <e@student.42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 18:42:48 by e                 #+#    #+#             */
/*   Updated: 2025/03/23 14:48:21 by e                ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(const char *c)
{
	int	a;
	int	j;
	int	res;
	int	si;

	a = 0;
	res = 0;
	j = 0;
	si = 1;
	while (c[a] == ' ' || c[a] == '\t' || c[a] == '\n'
		||c[a] == '\v' || c[a] == '\f' || c[a] == '\r')
		a++;
	while (c[a] == '-' || c[a] == '+')
	{
		if (c[a] == '-')
			si = si * -1;
		a++;
		j++;
	}
	while (c[a] >= '0' && c[a] <= '9')
		res = res * 10 + (c[a++] - '0');
	if (j > 1)
		return (0);
	return (res * si);
}

int is_positive_integer(const char *str)
{
	if (str == NULL || *str == '\0')
		return 1;
	int a = ft_atoi(str);
	if(a <= 0)
		return (1);
	return (0);
}

int check_input(int argc, char **argv)
{
	int i;

	i= 1;
	while (i < argc)
	{
		if (is_positive_integer(argv[i]))
		{
			printf("Error: Argument %d must be a positive integer.\n", i);
			return 1;
		}
		i++;
	}
	return 0;
}
