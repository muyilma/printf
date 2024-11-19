/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: musyilma <musyilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 17:43:23 by musyilma          #+#    #+#             */
/*   Updated: 2024/11/19 20:49:20 by musyilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	hola(int n, char c, va_list a)
{
	if (c == 'd' || c == 'i')
		n += ft_putnbr(va_arg(a, unsigned int));
	else if (c == 's')
		n += ft_putstr(va_arg(a, char *));
	else if (c == 'c')
		n += ft_putchar(va_arg(a, int));
	else if (c == 'u')
		n += ft_putnbru(va_arg(a, int));
	else if (c == 'x')
		n += ConvertHex(va_arg(a, int));
	else if (c == 'X')
		n += ConvertHexB(va_arg(a, int));
	else if (c == '%')
		n += ft_putchar('%');
	else if (c == 'p')
		n += ConvertPointer(va_arg(a, long));
	return (n);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	va_list	arg;
	int		number;

	va_start(arg, format);
	i = 0;
	number = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			number = hola(number, format[i + 1], arg);
			i += 2;
		}
		else
		{
			ft_putchar(format[i]);
			i++;
			number++;
		}
	}
	va_end(arg);
	return (number);
}
