/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: musyilma <musyilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 17:43:23 by musyilma          #+#    #+#             */
/*   Updated: 2024/11/21 17:00:44 by musyilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_printf_ex(int n, char c, va_list a)
{
	if (c == 'd' || c == 'i')
		n += ft_putnbr(va_arg(a, int));
	else if (c == 's')
		n += ft_putstr(va_arg(a, char *));
	else if (c == 'c')
		n += ft_putchar(va_arg(a, int));
	else if (c == 'u')
		n += ft_putnbr(va_arg(a, unsigned int));
	else if (c == 'x' || c == 'X')
		n += convert_hex(va_arg(a, unsigned long), c);
	else if (c == '%')
		n += ft_putchar('%');
	else if (c == 'p')
		n += convert_pointer(va_arg(a, unsigned long));
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
			number = ft_printf_ex(number, format[i + 1], arg);
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
