/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_options.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimarque <dimarque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 15:36:56 by dimarque          #+#    #+#             */
/*   Updated: 2023/08/08 15:23:44 by dimarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_options(va_list ap, const char type)
{
	char	*tipo;

	tipo = "0123456789abcdef";
	if (type == 'c')
		return (ft_printchar(va_arg(ap, int)));
	else if (type == 's')
		return (ft_printstr(va_arg(ap, char *)));
	else if (type == 'p')
		return (ft_print_ptr(va_arg(ap, unsigned long long), tipo));
	else if (type == 'u')
		return (ft_base(va_arg(ap, unsigned int), "0123456789"));
	else if (type == 'd' || type == 'i')
		return (ft_printnbr(va_arg(ap, int)));
	else if (type == 'x')
		return (ft_base(va_arg(ap, unsigned int), "0123456789abcdef"));
	else if (type == 'X')
		return (ft_base(va_arg(ap, unsigned int), "0123456789ABCDEF"));
	else
		return (ft_printstr("%"));
}
