/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: e <e@student.42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 15:13:30 by e                 #+#    #+#             */
/*   Updated: 2025/04/25 23:07:10 by e                ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *stack, int c)
{
	if (c == 0)
		return ((char *)stack + ft_strlen(stack));
	while (*stack)
	{
		if (*stack == (char)c)
			return ((char *)stack);
		stack++;
	}
	return (0);
}
