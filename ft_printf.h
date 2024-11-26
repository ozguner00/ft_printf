/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oguner <oguner@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 15:39:09 by oguner            #+#    #+#             */
/*   Updated: 2024/11/25 17:06:52 by oguner           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

int	ft_printf(const char *format, ...);
int	ft_strlen(char const *str);
int	ft_put_char(char c);
int	ft_put_str(char *str);
int	ft_put_nbr(int nbr);
int	ft_put_unsigned_nbr(unsigned int nbr);
int	ft_put_hexadecimal(unsigned long int n);
int	ft_put_hexadecimal_up(unsigned long int n);
int	ft_put_pointer(unsigned long long ptr);
int	ft_put_pointer_hexa(unsigned long int n);
int	check_handle(char const *format);

#endif