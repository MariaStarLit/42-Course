/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-avel <mde-avel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 16:01:07 by mde-avel          #+#    #+#             */
/*   Updated: 2022/11/24 15:00:10 by mde-avel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * It copies the string src to the end of dest, but only if there's enough 
 * space in dest.
 * 
 * @param dest This is the destination string.
 * @param src The string to be appended.
 * @param size the size of the destination buffer.
 * 
 * @return The length of the string that was copied.
 */

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	len_d;

	i = 0;
	if (!size)
		return (ft_strlen(src));
	len_d = ft_strlen(dest);
	if (size < len_d)
		return (ft_strlen(src) + size);
	while (src[i] && (len_d + i + 1) < size)
	{
		dest[len_d + i] = src[i];
		i++;
	}
	dest[len_d + i] = '\0';
	return (len_d + ft_strlen(src));
}

/*int	main(void)
{
	char src[] = "_Merda";
	char dst[20] = "Olha";
	//char b[0xF] = "nyan !";

	printf("return: %ld \n", ft_strlcat(dst, src, 8));
	printf("cat: %s \n", dst);
}*/
