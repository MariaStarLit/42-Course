/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-avel <mde-avel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 13:42:07 by mde-avel          #+#    #+#             */
/*   Updated: 2022/12/06 19:11:01 by mde-avel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
