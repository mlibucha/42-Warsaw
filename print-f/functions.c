/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlibucha <mlibucha@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 02:24:33 by mlibucha          #+#    #+#             */
/*   Updated: 2024/12/21 17:58:48 by mlibucha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printc(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_printstr(char *str)
{
	int	len;

	len = 0;
	if (!str)
		return (write(1, "(null)", 6));
	while (str[len])
	{
		write(1, &str[len], 1);
		len++;
	}
	return (len);
}

int	ft_printdec(int c)
{
	char	buffer[12];
	int		len;
	int		i;

	len = 0;
	i = 10;
	if (c == 0)
		return (write(1, "0", 1));
	if (c == INT_MIN)
		return (write(1, "-2147483648", 11));
	if (c < 0)
	{
		write(1, "-", 1);
		c = -c;
		len++;
	}
	buffer[11] = '\0';
	while (c)
	{
		buffer[i--] = (c % 10) + '0';
		c /= 10;
	}
	len += write(1, &buffer[i + 1], 10 - i);
	return (len);
}

int	ft_printint(int c)
{
	int		len;
	char	b;

	len = 0;
	if (c == INT_MIN)
	{
		len += write(1, "-2147483648", 11);
		return (len);
	}
	if (c < 0)
	{
		write(1, "-", 1);
		c = -c;
		len++;
	}
	if (c > 9)
		len += ft_printint(c / 10);
	b = (c % 10) + '0';
	write(1, &b, 1);
	return (len + 1);
}

int	ft_printundec(unsigned int c)
{
	char	buffer[12];
	int		len;
	int		i;

	i = 10;
	len = 0;
	if (c == 0)
		return (write(1, "0", 1));
	buffer[11] = '\0';
	while (c)
	{
		buffer[i--] = (c % 10) + '0';
		c /= 10;
	}
	len += write(1, &buffer[i + 1], 10 - i);
	return (len);
}
