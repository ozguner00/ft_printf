/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_put_func.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oguner <oguner@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 15:38:59 by oguner            #+#    #+#             */
/*   Updated: 2024/11/25 15:40:22 by oguner           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

int	ft_put_char(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_put_str(char *str)
{
	int	len;

	if (!str)
	{
		write(1, "(null)", 6);
		return (6);
	}
	len = ft_strlen(str);
	write(1, str, len);
	return (len);
}

int	ft_put_pointer(unsigned long long ptr)
{
	int	len;

	if (ptr == 0)
	{
		len = write(1, "(nil)", 5);
		return (len);
	}
	len = write(1, "0x", 2);
	len += ft_put_pointer_hexa(ptr);
	return (len);
}

int	ft_put_pointer_hexa(unsigned long int n)
{
	char	*hexa_case;
	int		len;

	len = 0;
	hexa_case = "0123456789abcdef";
	if (n > 15)
	{
		len += ft_put_pointer_hexa((n / 16));
	}
	len += (ft_put_char(hexa_case[(n % 16)]));
	return (len);
}
