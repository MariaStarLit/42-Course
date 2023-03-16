/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-avel <mde-avel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 19:43:21 by mde-avel          #+#    #+#             */
/*   Updated: 2022/11/24 15:00:30 by mde-avel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Compares the first n characters of the strings s1 and s2.
 * 
 * @param s1 The first string to be compared.
 * @param s2 The string to compare to.
 * @param n The maximum number of characters to compare.
 * 
 * @return The difference between the first two characters that differ in 
 * the strings s1 and s2.
 */

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while ((s1[i] || s2[i]) && i < n)
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}	
	return (0);
}

/*int	main(void)
{
	char	a[] = "BANANA!";
	char	b[] = "BANa! xp";
	size_t	num = 6;

	ft_strncmp(a, b, num);
	printf ("minha f: %d\n", ft_strncmp(a, b, num));
	printf ("strncmp: %d\n", strncmp(a, b, num));
}*/
