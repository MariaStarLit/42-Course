/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-avel <mde-avel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 17:23:10 by mde-avel          #+#    #+#             */
/*   Updated: 2023/08/05 17:25:11 by mde-avel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/**
 * Writes the string s, returns the length of the writen string s.
 */

int	ft_putstr(char *s)
{
	int	i;

	i = 0;
	if (!s)
	{
		return (ft_putstr("(null)"));
	}
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
	return (i);
}
