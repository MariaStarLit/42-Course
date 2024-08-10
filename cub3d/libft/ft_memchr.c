/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-avel <mde-avel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 13:01:00 by mde-avel          #+#    #+#             */
/*   Updated: 2022/11/24 14:59:00 by mde-avel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * The function ft_memchr() locates the first occurrence of c in the first
 * n bytes of the string.
 * 
 * @param str This is the pointer to the block of memory where the search 
 * is performed.
 * @param c The character to search for.
 * @param n The number of bytes to be searched.
 * 
 * @return A pointer to the first occurrence of the character c in the first
 * n bytes of the string pointed to, by the parameter str.
 */

void	*ft_memchr(const void *str, int c, size_t n)
{
	size_t		i;
	const char	*s;

	i = 0;
	s = str;
	while (i < n)
	{
		if (s[i] == (char)c)
		{
			return ((void *)(s + i));
		}
		i++;
	}
	return (0);
}

/*int	main(void)
{
	int			l = '.';
	const char	fio[20] = "Porra. tf";
	size_t 	nb = 10;

	printf("minhaf: %p \n", ft_memchr(fio, l, nb));
	printf("memchr: %p \n", memchr(fio, l, nb));
}*/
