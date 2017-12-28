#include <stdio.h>

int main(void)
{
	int i = 32;
	char str[] = "bonjour";

	printf("%15.25s\n", str);
	printf("%.25d\n", i);
	printf("%15.25i", i);
	return(0);
}
