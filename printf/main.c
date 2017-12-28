#include "ft_printf.h"

int main(void)
{
	int a = 123456;
	int b;
	int *p = &a;
	//printf("%s", ft_itoa(00000));
	ft_printf("|tst\n.%10c. test|\n\n", 'c');
	b = ft_printf(".%10.2s.", "string");
	printf(" <-- %d\n", b);
	b = printf(".%10.2s.", "string");
	printf(" <-- %d\n", b);
	return (0);
}
