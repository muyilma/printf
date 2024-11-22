/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: musyilma <musyilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 16:14:07 by musyilma          #+#    #+#             */
/*   Updated: 2024/11/21 17:05:33 by musyilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
	{
		i = ft_putstr("(null)");
		return (i);
	}
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

int	ft_putnbr(long n)
{
	int	size;

	size = 0;
	if (n < 0)
	{
		size += ft_putchar('-');
		n = -n;
		size += ft_putnbr(n);
	}
	else if (n >= 10)
	{
		size += ft_putnbr(n / 10);
		size += ft_putnbr(n % 10);
	}
	else
		size += ft_putchar(n + '0');
	return (size);
}

int	convert_hex(unsigned int n, char c)
{
	int		remainder;
	char	*alph;
	char	*alph2;
	int		size;

	size = 0;
	alph = "0123456789abcdef";
	alph2 = "0123456789ABCDEF";
	remainder = 0;
	if (n >= 16)
		size = convert_hex(n / 16, c);
	remainder = (n % 16);
	if (c == 'x')
	{
		size += ft_putchar(alph[remainder]);
	}
	else if (c == 'X')
	{
		size += ft_putchar(alph2[remainder]);
	}
	return (size);
}

int	convert_pointer(unsigned long n)
{
	long	remainder;
	char	*alp;
	int		size;

	size = 2;
	alp = "0123456789abcdef";
	remainder = 0;
	if (n == 0)
	{
		size = ft_putstr("(nil)");
		return (size);
	}
	if (n >= 16)
		size = convert_pointer(n / 16);
	if (size == 2)
		ft_putstr("0x");
	remainder = (n % 16);
	size += ft_putchar(alp[remainder]);
	return (size);
}
