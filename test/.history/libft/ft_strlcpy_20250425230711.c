/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: e <e@student.42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 16:19:42 by e                 #+#    #+#             */
/*   Updated: 2025/04/25 23:07:10 by e                ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	const char	*stack;
	size_t		n;

	stack = src;
	n = size;
	if (n)
	{
		while (--n)
		{
			*dest = *stack;
			if (*stack == '\0')
				break ;
			dest++;
			stack++;
		}
		if (size > 0)
			*dest = '\0';
	}
	while (*stack)
		stack++;
	return (stack - src);
}
