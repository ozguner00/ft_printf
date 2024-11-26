#include "ft_printf.h"
#include <stdarg.h>

int	ft_printf_arg(va_list list, const char format)
{
	if (format == '%')
		return (ft_put_char('%'));
	else if (format == 'c')
		return (ft_put_char(va_arg(list, int)));
	else if (format == 's')
		return (ft_put_str(va_arg(list, char *)));
	else if (format == 'd' || format == 'i')
		return (ft_put_nbr(va_arg(list, int)));
	else if (format == 'u')
		return (ft_put_unsigned_nbr(va_arg(list, unsigned int)));
	else if (format == 'x')
		return (ft_put_hexadecimal(va_arg(list, unsigned int)));
	else if (format == 'X')
		return (ft_put_hexadecimal_up(va_arg(list, unsigned int)));
	else if (format == 'p')
		return (ft_put_pointer(va_arg(list, unsigned long long)));
	return (0);
}

int check_handle(char const *format)
{
	int	len;

	len = ft_strlen(format);
	if (len == 0)
		return (-1);
	else if (len == 1 && format[0] == '%')
		return (-1);
	else if (len > 2 && format[len - 1] == '%')
		return (-1);
	return (1);
}
int	ft_printf(const char *format, ...)
{
	va_list	list;
	int		i;
	int		len;
	int		check;

	if (check_handle(format) == -1)
		return (-1);
	i = 0;
	len = 0;
	va_start(list, format);
	while (format[i])
	{
		if (format[i++] == '%')
		{
			check = ft_printf_arg(list, format[i++]);
			if (check)
				len += check;
			else
				len += ft_put_char(format[i-2]);
		}
		else
			len += ft_put_char(format[i++]);
	}
	va_end(list);
	return (len);
}
