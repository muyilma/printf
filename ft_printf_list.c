#include "ft_printf.h"

int	ft_numlen(int n)
{
	int	i;

	i = 0;
	if (n <= 0)
	{
		n = n * -1;
		i++;
	}
	while (n)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

int	ft_numlenU(unsigned int n)
{
	int	i;

	i = 0;
	if (n <= 0)
	{
		n = n * -1;
		i++;
	}
	while (n)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

int	ft_putnbr(int n)
{
	int	size;

	size = ft_numlen(n);
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
	}
	else if (n < 0)
	{
		ft_putchar('-');
		n = -n;
		ft_putnbr(n);
	}
	else if (n >= 10)
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
	else
	{
		ft_putchar(n + '0');
	}
	return (size);
}

int	ft_putnbru(unsigned int n)
{
	if (n >= 10)
	{
		ft_putnbru(n / 10);
		ft_putnbru(n % 10);
	}
	else
	{
		ft_putchar(n + '0');
	}
	return (ft_numlenU(n));
}



int	ConvertHex(unsigned int n)
{
	int		remainder;
	char	*alp;
	int		size;

	size = 0;
	alp = "0123456789abcdef";
	remainder = 0;
	if (n >= 16)
		size = ConvertHex(n / 16);
	remainder = (n % 16);
	size += ft_putchar(alp[remainder]);
	return (size);
}


int	ConvertHexB(unsigned int n)
{
	int		remainder;
	char	*alp;
	int		size;

	size = 0;
	alp = "0123456789ABCDEF";
	remainder = 0;
	if (n >= 16)
		size = ConvertHexB(n / 16);
	remainder = (n % 16);
	size += ft_putchar(alp[remainder]);
	return (size);
}

int	ConvertPointer(long n)
{
	long        remainder;
    char    *alp;
    int        size;

    size = 0;
    alp = "0123456789abcdef";
    remainder = 0;
    if (n >= 16)
        size = ConvertHex(n / 16);
    remainder = (n % 16);
    size += ft_putchar(alp[remainder]);
    return (size);
}