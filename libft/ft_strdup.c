/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlibucha <mlibucha@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 15:07:43 by e                 #+#    #+#             */
/*   Updated: 2024/12/14 14:14:15 by mlibucha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	int		a;
	char	*p;

	a = 0;
	p = malloc(ft_strlen(src)+1);
	if (p == NULL)
		return (NULL);
	while (src[a] != '\0')
	{
		p[a] = src[a];
		a++;
	}
	p[a] = '\0';
	return (p);
}
