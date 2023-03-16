/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-avel <mde-avel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 13:12:51 by mde-avel          #+#    #+#             */
/*   Updated: 2022/11/24 14:59:20 by mde-avel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * The function ft_memset() takes a pointer to a memory area, a character to 
 * fill it with, and a size, and fills the memory area with the character.
 * 
 * @param str This is the pointer to the block of memory to fill.
 * @param c the character to fill the memory with
 * @param n the number of bytes to be filled
 * 
 * @return A pointer to the beginning of the string.
 */

void	*ft_memset(void *str, int c, size_t n)
{
	size_t	i;
	char	*res;

	res = str;
	i = 0;
	while (i < n)
	{
		res[i] = (char)c;
		i++;
	}
	return (res);
}

/*int	main(void)
{
	char	s[30] = "Sugar Pie Honny Bunsh!";
	size_t	nb = 9;

	memset(s, '$', nb);
	printf ("memset: %s\n", s);
	ft_memset(s, '&', nb);
	printf ("minhaf: %s\n", s);
}
if (!str)
		return (NULL);
*/