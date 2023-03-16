/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-avel <mde-avel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 18:19:46 by mde-avel          #+#    #+#             */
/*   Updated: 2022/11/24 14:59:54 by mde-avel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Iterate through the string s, passing the index and the address of each 
 * character to the function f
 * 
 * @param s The string to iterate through.
 * @param f The function to be applied to each character of the string.
 */

void	ft_striteri(char *s, void (*f)(unsigned int,	char *))
{
	unsigned int	i;

	if (!s || !f)
		return ;
	i = 0;
	while (s[i])
	{
		f(i, s + i);
		i++;
	}
}
