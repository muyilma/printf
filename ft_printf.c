/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: musyilma <musyilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 17:43:23 by musyilma          #+#    #+#             */
/*   Updated: 2024/11/17 17:45:28 by musyilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	hola(int n, char c, va_list a)
{
	if (c == 'd')
		n += ft_putnbr(va_arg(a, int));
	else if (c == 's' || c == 'i')
		n += ft_putstr(va_arg(a, char *));
	else if (c == 'c')
		n += ft_putchar(va_arg(a, int));
	else if (c == 'u')
		n += ft_putnbru(va_arg(a, int));
	printf("\n-------");
	printf("\nn=%d\n", n);
	printf("-------\n");
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
