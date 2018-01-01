#include <locale.h>
#include <stdio.h>
#include <wchar.h>
#include <unistd.h>

int n_oct(wchar_t c)
{
	int t;
	int len = 1;
	t = 8;
	char ts;
	while (c >> t!= 0x0)
	{
		t += 8;
		len++;
	}
	return (len);
}

void ft_wputc(wint_t c)
{
	int t;
	int car;
	int len;
	len = n_oct(c);
}

int main(void)
{
	setlocale(LC_ALL, "");
	wchar_t c = L'ሴ';
	printf("\n%x\n", c);
	printf("%d", n_oct(c));
//	ft_wputc(c);
	return (0);
}
