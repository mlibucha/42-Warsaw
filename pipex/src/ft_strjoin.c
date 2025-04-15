/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: e <e@student.42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 21:08:56 by e                 #+#    #+#             */
/*   Updated: 2025/04/14 23:51:15 by e                ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t			a;
	size_t			b;
	char			*c;
	size_t			d;
	char			*start;

	a = ft_strlen(s1);
	b = ft_strlen(s2);
	d = a + b;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	c = (char *)malloc(d + 1);
	if (c == NULL)
		return (NULL);
	start = c;
	while (*s1)
		*c++ = *s1++;
	while (*s2)
		*c++ = *s2++;
	*c = '\0';
	return (start);
}
