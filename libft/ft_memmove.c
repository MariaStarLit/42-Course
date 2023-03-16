/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-avel <mde-avel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 16:03:05 by mde-avel          #+#    #+#             */
/*   Updated: 2022/11/24 14:59:17 by mde-avel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * If the destination is before the source, then copy the source to the 
 * destination from the end of the source to the beginning of the source. 
 * If the destination is after the source, then copy the source to the 
 * destination from the beginning of the source to the end of the source.
 * 
 * @param dest This is the pointer to the destination array where the 
 * content is to be copied, type-casted to a pointer of type void*.
 * @param str The string to copy.
 * @param n the number of bytes to copy
 * 
 * @return A pointer to the destination string.
 */

void	*ft_memmove(void *dest, const void *str, size_t n)
{
	char		*d;
	const char	*s;

	d = dest;
	s = str;
	if (dest == str)
		return (dest);
	if (s < d)
	{
		while (n > 0)
		{
			n--;
			d[n] = s[n];
		}
	}
	else
	{
		while (n > 0)
		{
			*d++ = *s++;
			n--;
		}
	}
	return (dest);
}

/*int	main(void)
{
	char 	str[] = "ABCDE";
	//char	*g;

	//g = ft_memmove (str, str + 1, 3);
	//printf("minha f: %s\n", g);
	memmove (str + 1, str + 1, 3);
	printf("memmove: %s\n", str);
}*/