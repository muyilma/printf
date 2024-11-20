#include "ft_printf.h"
#include <limits.h>
#include <stdio.h>
#include <string.h>

int	main(void)
{
	int	a;

	a = 16;
	ft_printf("%u",-1);
	//printf(" %p %p ", ULONG_MAX, -ULONG_MAX);
	// ft_printf("%d", ft_printf("%p", 0));
	// printf("%d", printf(" %p\n", 0));
	// ft_printf("%u\n", 2147483648);
	// printf("%u\n", 2147483648);
}
