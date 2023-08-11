/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbru.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-avel <mde-avel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 17:22:23 by mde-avel          #+#    #+#             */
/*   Updated: 2023/08/05 17:22:33 by mde-avel         ###   ########.fr       */
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
