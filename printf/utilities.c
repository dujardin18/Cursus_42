#include "ft_printf.h"

int ft_put_n_chars(int n, char c)
{
	int i;

	i = 0;
	while (i < n)
	{
		ft_putchar(c);
		i++;
	}
	return (n);
}
