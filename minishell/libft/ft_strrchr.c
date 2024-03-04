/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimarque <dimarque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 14:59:38 by dimarque          #+#    #+#             */
/*   Updated: 2022/11/04 17:26:19 by dimarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = ft_strlen(s) + 1;
	if (!c)
		return ((char *)s + (i - 1));
	while (--i >= 0)
	{
		if (*(s + i) == (char)c)
		{
			return ((char *)s + i);
		}
	}
	return (NULL);
}

/* int main()
{

	char *str;
	str = "https.//mdinis.pt";
	char *str2 = "bounjour";

	printf("%s", ft_strrchr(str, '.'));
	printf("\n");
	printf("%s", ft_strrchr(str2, 'j'));
	return 0;
} */