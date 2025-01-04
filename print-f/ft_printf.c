/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlibucha <mlibucha@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 02:23:59 by mlibucha          #+#    #+#             */
/*   Updated: 2024/12/21 18:00:14 by mlibucha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printvoid(unsigned long ptr)
{
	int		len;
	int		i;
	char	buffer[17];
	char	*hex;

	len = 0;
	i = 16;
	hex = "0123456789abcdef";
	if (ptr == 0)
	{
		len += write(1, "(nil)", 5);
		return (len);
	}
	len += write(1, "0x", 2);
	buffer[16] = '\0';
	while (ptr)
	{
		buffer[--i] = hex[ptr % 16];
		ptr /= 16;
	}
	len += write(1, &buffer[i], 16 - i);
	return (len);
}

int	ft_printhexupper(int c)
{
	char			*base;
	char			hex[16];
	unsigned int	uc;
	int				i;
	int				count;

	i = 0;
	count = 0;
	base = "0123456789ABCDEF";
	uc = (unsigned int)c;
	if (uc == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	while (uc > 0)
	{
		hex[i++] = base[uc % 16];
		uc /= 16;
	}
	while (--i >= 0)
		count += write(1, &hex[i], 1);
	return (count);
}

int	ft_printhexlower(int c)
{
	char			*base;
	char			hex[16];
	unsigned int	uc;
	int				i;
	int				count;

	i = 0;
	count = 0;
	base = "0123456789abcdef";
	uc = (unsigned int)c;
	if (uc == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	while (uc > 0)
	{
		hex[i++] = base[uc % 16];
		uc /= 16;
	}
	while (--i >= 0)
		count += write (1, &hex[i], 1);
	return (count);
}

int	ft_checkparams(va_list args, const char *parameters, int a)
{
	if (parameters[a] == 'c')
		return (ft_printc(va_arg(args, int)));
	if (parameters[a] == 's')
		return (ft_printstr(va_arg(args, char *)));
	if (parameters[a] == 'p')
		return (ft_printvoid((unsigned long)va_arg(args, void *)));
	if (parameters[a] == 'd')
		return (ft_printdec(va_arg(args, int)));
	if (parameters[a] == 'i')
		return (ft_printint(va_arg(args, int)));
	if (parameters[a] == 'u')
		return (ft_printundec(va_arg(args, unsigned int)));
	if (parameters[a] == 'x')
		return (ft_printhexlower(va_arg(args, int)));
	if (parameters[a] == 'X')
		return (ft_printhexupper(va_arg(args, int)));
	if (parameters[a] == '%')
		return (write(1, "%%", 1));
	return (0);
}

int	ft_printf(const char *parameters, ...)
{
	va_list	args;
	int		a;
	int		count;

	va_start(args, parameters);
	a = 0;
	count = 0;
	while (parameters[a])
	{
		if (parameters[a] == '%')
		{
			a++;
			count += ft_checkparams(args, parameters, a);
		}
		else
		{
			write(1, &parameters[a], 1);
			count++;
		}
		a++;
	}
	va_end(args);
	return (count);
}
