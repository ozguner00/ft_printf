/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oguner <oguner@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 15:38:05 by oguner            #+#    #+#             */
/*   Updated: 2024/11/25 15:58:01 by oguner           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

int	ft_printf(const char *s, ...)
{
	va_list	list;
	int		i;
	int		len;
	int		check;

	if (!s || (s[0] == '%' && ft_strlen(s) == 1) || s[ft_strlen(s) - 1] == '%')
		return (-1);
	i = 0;
	len = 0;
	va_start(list, s);
	while (s[i])
	{
		if (s[i] == '%')
		{
			check = ft_printf_arg(list, s[i + 1]);
			if (check)
				len += check;
			else
				len += ft_put_char(s[i]);
			i += 2;
		}
		len += ft_put_char(s[i++]);
	}
	va_end(list);
	return (len);
}
