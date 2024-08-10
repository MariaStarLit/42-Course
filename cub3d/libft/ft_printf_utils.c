/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-avel <mde-avel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 12:40:55 by mde-avel          #+#    #+#             */
/*   Updated: 2024/02/06 18:41:48 by mde-avel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Writes a single character & returns 1.
int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

// Writes the string s, returns the length of the writen string s.
int	ft_putstr(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (ft_putstr("(null)"));
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
	return (i);
}

// It prints a pointer's address in hexadecimal and and return the number
// of digits printed.
int	ft_putvod(t_ull n)
{
	int	cont;

	cont = 0;
	if (!n)
	{
		return (ft_putstr("(nil)"));
	}
	cont += ft_putstr("0x");
	cont += ft_puthex(n, 'x');
	return (cont);
}

// Write the unsigned integer n, and return the number of digits printed.
int	ft_putnbru(unsigned int n)
{
	int	cont;

	cont = 0;
	if (n >= 10)
	{
		cont += ft_putnbr(n / 10);
		cont += ft_putnbr(n % 10);
	}
	if (n < 10)
		cont += ft_putchar(n + 48);
	return (cont);
}

// It prints the hexadecimal representation of a number.
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
