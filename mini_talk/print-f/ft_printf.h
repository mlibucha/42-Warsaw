/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlibucha <mlibucha@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 01:37:19 by e                 #+#    #+#             */
/*   Updated: 2024/12/21 18:33:17 by mlibucha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <limits.h>

int	ft_printc(char c);
int	ft_printstr(char *str);
int	ft_printdec(int c);
int	ft_printint(int c);
int	ft_printundec(unsigned int c);
int	ft_printvoid(unsigned long ptr);
int	ft_printhexupper(int c);
int	ft_printhexlower(int c);
int	ft_checkparams(va_list args, const char *parameters, int a);
int	ft_printf(const char *parameters, ...);

#endif
