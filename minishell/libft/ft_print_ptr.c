/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimarque <dimarque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 13:31:06 by dimarque          #+#    #+#             */
/*   Updated: 2023/08/08 15:23:45 by dimarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_print_ptr(unsigned long long nbr, char *type)
{
	int					i;
	unsigned long long	j;

	i = 0;
	j = 0;
	if (nbr == 0)
		return (write(1, "(nil)", 5));
	i += write(1, "0x", 2);
	while (type[j])
		j++;
	if (nbr >= j)
		i += ft_base((nbr / j), type);
	return (i + ft_printchar(type[nbr % j]));
}
