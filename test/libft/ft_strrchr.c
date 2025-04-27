/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: e <e@student.42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 14:22:20 by e                 #+#    #+#             */
/*   Updated: 2025/04/25 23:07:10 by e                ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *stack, int c)
{
	int			len;
	const char	*end;

	len = ft_strlen(stack);
	end = stack + len - 1;
	if (c == 0)
		return ((char *)stack + ft_strlen(stack));
	while (len--)
	{
		if (*end == (char)c)
			return ((char *)end);
		end--;
	}
	return (0);
}
