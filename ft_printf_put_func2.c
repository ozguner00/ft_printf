/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_put_func2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oguner <oguner@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 15:39:02 by oguner            #+#    #+#             */
/*   Updated: 2024/11/25 15:40:58 by oguner           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

int	ft_put_nbr(int n)
{
	int	len;

	len = 0;
	if (n < 0)
	{
		if (n == -2147483648)
		{
			return (ft_put_str("-2147483648"));
		}
		len += ft_put_char('-');
		n = -n;
	}
	if (n / 10)
	{
		len += ft_put_nbr(n / 10);
		len += ft_put_nbr(n % 10);
	}
	else
		len += ft_put_char('0' + n);
	return (len);
}

int	ft_put_unsigned_nbr(unsigned int nbr)
{
	int	len;

	len = 0;
	if (nbr / 10)
	{
		len += ft_put_unsigned_nbr(nbr / 10);
	}
	len += ft_put_char('0' + (nbr % 10));
	return (len);
}

int	ft_put_hexadecimal(unsigned long int n)
{
	char	*hexa_case;
	int		len;

	len = 0;
	hexa_case = "0123456789abcdef";
	if (n > 15)
	{
		len += ft_put_hexadecimal((n / 16));
	}
	len += (ft_put_char(hexa_case[(n % 16)]));
	return (len);
}

int	ft_put_hexadecimal_up(unsigned long int n)
{
	char	*hexa_case_up;
	int		len;

	len = 0;
	hexa_case_up = "0123456789ABCDEF";
	if (n > 15)
	{
		len += ft_put_hexadecimal_up((n / 16));
	}
	len += (ft_put_char(hexa_case_up[(n % 16)]));
	return (len);
}
