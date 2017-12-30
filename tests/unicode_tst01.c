#include <locale.h>
#include <stdio.h>
#include <wchar.h>

int n_oct(wchar_t c)
{
	int t;
	int len = 1;
	t = 8;
	while (c >> t!= 0)
	{
		t += 8;
		len++;
	}
	return (len);
}

int ft_wstrlen(wchar_t *wstr)
{
}

int main(void)
{
	setlocale(LC_ALL, "");
	wchar_t c = L'☾';
	printf("\n%x\n", c);
	printf("%d", lenoct(c));
	return (0);
}
