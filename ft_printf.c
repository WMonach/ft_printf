/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmonacho <wmonacho@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 10:35:20 by wmonacho          #+#    #+#             */
/*   Updated: 2021/11/25 17:15:54 by wmonacho         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int static	ft_procession(char conversion, va_list args)
{
	int		i;

	i = 0;
	if (conversion == 'c')
		i = ft_putchar_fd(va_arg(args, int), 1);
	if (conversion == 's')
		i = ft_putstr_fd(va_arg(args, char *), 1);
	if (conversion == 'p')
		i = ft_put_adr(va_arg(args, unsigned long long), "0123456789abcdef");
	if (conversion == 'd')
		i = ft_putnbr_basediu(va_arg(args, int), "0123456789");
	if (conversion == 'i')
		i = ft_putnbr_basediu(va_arg(args, int), "0123456789");
	if (conversion == 'u')
		i = ft_putnbr_basediu(va_arg(args, unsigned int), "0123456789");
	if (conversion == 'x')
		i = ft_xxconvert_basexx(va_arg(args, int), "0123456789abcdef");
	if (conversion == 'X')
		i = ft_xxconvert_basexx(va_arg(args, int), "0123456789ABCDEF");
	if (conversion == '%')
		i = ft_putchar_fd('%', 1);
	return (i);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		count;
	int		j;

	i = 0;
	count = 0;
	va_start(args, format);
	while (format[i] != '\0')
	{
		while (format[i] != '%' && format[i] != '\0')
		{
			ft_putchar_fd(format[i], 1);
			i++;
			count++;
		}
		if (format[i] == '%' && format[i + 1] != '\0')
		{
			j = ft_procession(format[i + 1], args);
			if (j == 0 && format[i + 1] != '\0')
			{
				ft_putchar_fd(format[i + 1], 1);
				j++;
			}
			count = count + j;
			i++;
		}
	}
	va_end(args);
	return (count);
}
