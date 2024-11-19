#ifndef FT_PRINTF_H
# define FT_PRINTF_H


# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>

int	ft_putchar(char c);
int	ft_putnbr(int n);
int	ft_putstr(char *str);
int	ft_putnbru(unsigned int n);
int	ConvertHex(unsigned int n);
int	ConvertHexB(unsigned int n);
int	ConvertPointer(long n);
int	ft_printf(const char *format, ...);

#endif