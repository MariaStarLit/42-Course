/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-avel <mde-avel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 19:25:51 by mde-avel          #+#    #+#             */
/*   Updated: 2022/11/24 15:00:14 by mde-avel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Copy the string pointed to by src to the string dest, including the \0.
 * If the return value is greater than or equal to size, truncation occurred.
 * 
 * @param dest This is the pointer to the destination array where the content 
 * is to be copied.
 * @param src This is the string that you want to copy.
 * @param size The maximum number of bytes to copy from src to dest.
 * 
 * @return The length of the string src.
 */

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	tam;

	tam = 0;
	while (src[tam])
		tam++;
	if (size != 0)
	{
		i = 0;
		while (src[i] && i < (size -1))
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	return (tam);
}

/*int	main(void)
{
	char orig[] = "Honney";
	char desti[] = "Sugar Pie Honney Bunsh!";

	printf("return: %ld\n", ft_strlcpy(desti, orig, 7));
	printf("desti: %s\n", desti);
}*/
