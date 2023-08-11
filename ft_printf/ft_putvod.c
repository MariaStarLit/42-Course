/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putvod.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-avel <mde-avel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 16:02:04 by mde-avel          #+#    #+#             */
/*   Updated: 2023/08/11 13:14:52 by mde-avel         ###   ########.fr       */
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
