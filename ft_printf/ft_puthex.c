/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-avel <mde-avel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 15:13:25 by mde-avel          #+#    #+#             */
/*   Updated: 2023/01/27 17:18:10 by mde-avel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/**
 * It prints the hexadecimal representation of a number
 * 
 * @param n the number to be converted to hexadecimal
 * @param ch the character to print, either 'x' or 'X'
 * 
 * @return The number of characters printed.
 */

int	ft_puthex(unsigned long n, const char ch)
{
	int			cont;
	const char	*hex;
	const char	*hexm;

	cont = 0;
	hex = "0123456789abcdef";
	hexm = "0123456789ABCDEF";
	if (n >= 16)
	{
		cont += ft_puthex(n / 16, ch);
		cont += ft_puthex(n % 16, ch);
	}
	if (n < 16)
	{
		if (ch == 'x')
			cont += ft_putchar(hex[n]);
		else
			cont += ft_putchar(hexm[n]);
	}
	return (cont);
}
