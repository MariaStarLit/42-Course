/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-avel <mde-avel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 16:20:33 by mde-avel          #+#    #+#             */
/*   Updated: 2022/11/24 14:59:45 by mde-avel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Locates the first occurrence of (char)c in the string pointed to by str.
 * 
 * @param str This is the string to be searched.
 * @param c The character to search for.
 * 
 * @return the string after the first occurrence of the character c in str.
 */

char	*ft_strchr(const char *str, int c)
{
	while (*str)
	{
		if (*str == (char)c)
		{
			return ((char *)str);
		}
		str++;
	}
	if ((char)c == '\0')
	{
		return ((char *)str);
	}
	return (0);
}

/*int	main(void)
{
	int	l = 'r';
	const char	fio[20] = "Porra";

	printf("minhaf: |%s|\n", ft_strchr(fio, l));
	printf("strchr: |%s| \n", strchr(fio, l));
}
if (!str)
		return (NULL);
*/