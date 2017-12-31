#include "ft_printf.h"

void	ft_print_nc(int n, char c)
{
	int i;

	i = 0;
	while (i < n)
	{
		ft_putchar(c);
		i++;
	}
}
