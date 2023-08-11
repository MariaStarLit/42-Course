/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putvod.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-avel <mde-avel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 17:24:07 by mde-avel          #+#    #+#             */
/*   Updated: 2023/08/05 17:24:12 by mde-avel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/**
 * It prints a pointer's address in hexadecimal and and return the number
 * of digits printed.
 */

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
