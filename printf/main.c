#include "ft_printf.h"

int main(void)
{
	int a = -42;
	int b;
	int *p = &a;
	//printf("%s", ft_itoa(00000));
	ft_printf("|tst\n.%10c. test|\n\n", 'c');
	b = printf(".% d.", 42);
	printf(" <-- %d\n", b);
	b = ft_printf(".% d.", 42);
	printf(" <-- %d\n", b);
	return (0);
}
