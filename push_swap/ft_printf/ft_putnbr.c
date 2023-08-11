/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-avel <mde-avel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 17:21:28 by mde-avel          #+#    #+#             */
/*   Updated: 2023/08/07 18:53:21 by mde-avel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/**
 * Write the integer n & returns the number of digits printed.
 */

int	ft_putnbr(int n)
{
	int	cont;

	cont = 0;
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		cont = 11;
	}
	else
	{
		if (n < 0)
		{
			ft_putchar('-');
			n *= -1;
			cont++;
		}
		if (n >= 10)
		{
			cont += ft_putnbr(n / 10);
		}
		cont += ft_putchar(n % 10 + 48);
	}
	return (cont);
}
