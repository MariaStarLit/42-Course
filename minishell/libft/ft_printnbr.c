/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimarque <dimarque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 12:35:15 by dimarque          #+#    #+#             */
/*   Updated: 2023/08/08 15:23:49 by dimarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printnbr(int nbr)
{
	int	i;

	i = 0;
	if (nbr == -2147483648)
		return (write(1, "-2147483648", 11));
	if (nbr < 0)
	{
		ft_printchar('-');
		nbr = -nbr;
		i++;
	}
	if (nbr > 9)
	{
		i += ft_printnbr(nbr / 10);
		i += ft_printchar(nbr % 10 + 48);
	}
	else
	{
		ft_printchar(nbr + 48);
		i++;
	}
	return (i);
}
