/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-avel <mde-avel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 15:26:36 by mde-avel          #+#    #+#             */
/*   Updated: 2022/11/24 14:59:12 by mde-avel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Copy n bytes from memory area str to memory area dest
 * 
 * @param dest This is the destination array where the content is to be 
 * copied, type-casted to a pointer.
 * @param str The string to copy.
 * @param n the number of bytes to copy
 * 
 * @return A pointer to the destination string.
 */

void	*ft_memcpy(void *dest, const void *str, size_t n)
{
	size_t		i;
	char		*res;
	const char	*org;

	i = 0;
	res = dest;
	org = str;
	if (!dest && !str)
		return (0);
	while (i < n)
	{
		res[i] = org[i];
		i++;
	}
	return (res);
}

/*int	main(void)
{
	const char 	s[] = "Cringe";
	char		des[50] = "Sugar Pie Honny Bunsh!";
	size_t		nb = 20;

	/memcpy(des, s, nb);
	printf ("memcpy: %s\n", s);
	ft_memcpy(des, s, nb);
	printf ("minhaf: %s\n", s);
}*/
