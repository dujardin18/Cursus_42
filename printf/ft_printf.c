#include "ft_printf.h"

int ft_printf(const char *format, ... )
{
	va_list ap;
	int ret;

	va_start(ap, format);
	ret = ft_reading_format((char *)format, ap);
	va_end(ap);
	return (ret);
}
