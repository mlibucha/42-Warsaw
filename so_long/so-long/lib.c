/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: e <e@student.42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 10:56:09 by e                 #+#    #+#             */
/*   Updated: 2025/03/10 10:57:12 by e                ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static unsigned int	ft_number_length(int number)
{
	unsigned int	len;

	len = 0;
	if (number == 0)
		return (1);
	if (number < 0)
		len += 1;
	while (number != 0)
	{
		number /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char			*string;
	unsigned int	number;
	unsigned int	len;

	len = ft_number_length(n);
	string = (char *)malloc(sizeof(char) * (len + 1));
	if (string == NULL)
		return (NULL);
	string[len] = '\0';
	if (n < 0)
	{
		string[0] = '-';
		number = (unsigned int)(-n);
	}
	else
		number = (unsigned int)n;
	if (number == 0)
		string[0] = '0';
	while (number != 0)
	{
		string[len - 1] = (number % 10) + '0';
		number /= 10;
		len--;
	}
	return (string);
}

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
