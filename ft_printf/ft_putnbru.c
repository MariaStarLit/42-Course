/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbru.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-avel <mde-avel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 12:41:53 by mde-avel          #+#    #+#             */
/*   Updated: 2022/12/06 19:11:34 by mde-avel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/**
 * Write the unsigned integer n, and return the number of digits printed.
 */

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
