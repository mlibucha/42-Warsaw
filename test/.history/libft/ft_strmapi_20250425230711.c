/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: e <e@student.42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 16:30:24 by e                 #+#    #+#             */
/*   Updated: 2025/04/25 23:07:10 by e                ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *stack, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*str;

	i = 0;
	str = (char *)malloc(sizeof(char) * (ft_strlen(stack)) + 1);
	if (str == NULL)
		return (NULL);
	while (stack[i] != '\0')
	{
		str[i] = f(i, stack[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}
