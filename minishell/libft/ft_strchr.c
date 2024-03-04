/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimarque <dimarque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 14:34:42 by dimarque          #+#    #+#             */
/*   Updated: 2023/08/08 15:23:43 by dimarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	while (*str)
	{
		if (*str == (char )c)
		{
			return ((char *)str);
		}
		str++;
	}
	if (*str == (char)c)
		return ((char *)str);
	return (NULL);
}

/* #include <stdio.h>
int main()
{

	char *str;
	str = "https.//mdinis.pt";

	printf("%s", ft_strchr(str, '.'));
	return 0;
} */