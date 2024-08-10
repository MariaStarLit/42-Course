/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-avel <mde-avel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 15:15:13 by mde-avel          #+#    #+#             */
/*   Updated: 2022/11/24 14:57:50 by mde-avel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * It takes a pointer to a string and a size_t, and sets the first n bytes of 
 * the string to 0.
 * 
 * eptys the string. Exept if n = 0, it does nothing.
 */

void	ft_bzero(void *str, size_t n)
{
	size_t	i;
	char	*res;

	res = str;
	i = 0;
	while (i < n)
	{
		res[i] = 0;
		i++;
	}
	str = res;
}

/*int	main(void)
{
	char	s[30] = "Sugar Pie Honny Bunsh!";
	size_t	nb = 10;

	bzero(s, nb);
	printf ("bzero: |%s|\n", s);
}

	ft_bzero(s, nb);
	printf ("minef: |%s|\n", s);
*/