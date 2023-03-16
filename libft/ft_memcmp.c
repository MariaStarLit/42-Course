/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-avel <mde-avel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 13:51:40 by mde-avel          #+#    #+#             */
/*   Updated: 2022/11/24 14:59:05 by mde-avel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * The function ft_memcmp() compares the first n bytes of the memory area 
 * str1 to the first n bytes of the memory area str2.
 * 
 * @param str1 This is the first string to be compared.
 * @param str2 The string to be compared.
 * @param n The number of bytes to compare.
 * 
 * @return The difference between the two strings.
 */

int	ft_memcmp(const void *str1, const void *str2, size_t n)
{
	size_t				i;
	const unsigned char	*s1;
	const unsigned char	*s2;

	i = 0;
	s1 = str1;
	s2 = str2;
	while (i < n)
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}	
	return (0);
}

/*int	main(void)
{
	const char	a[] = "BANANA!";
	const char	b[] = "BANANA! xp";
	size_t		num = 6;

	printf ("minhaf: %d\n", ft_memcmp(a, b, num));
	printf ("memcmp: %d\n", memcmp(a, b, num));
}*/
