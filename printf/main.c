#include "ft_printf.h"

int main(void)
{
	int a = -42;
	int b;
	int *p = &a;
	//printf("%s", ft_itoa(00000));
	b = printf(".%15.4o.", 42);
	printf(" <-- %d\n\n", b);
	b = ft_printf(".%15.4o.", 42);
	printf(" <-- %d\n", b);
	return (0);
}
