/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimarque <dimarque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 18:03:20 by dimarque          #+#    #+#             */
/*   Updated: 2022/11/04 14:45:41 by dimarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!big && len == 0)
		return (NULL);
	else if (!big[i] && !little[i])
		return ((char *)big);
	while ((big[i]) && (i <= len))
	{
		j = 0;
		while ((little[j]) && (big[i + j] == little[j]) && (i + j < len))
			j++;
		if (!little[j])
			return ((char *)big + i);
		i++;
	}
	return (NULL);
}

/* int main()
{

	char *str; 
	char *str1;
	str = "cutcut HELLO cutcut";
	str1 = "HELLO";

	printf("%s", ft_strnstr(str, str1, 5));
	return 0;
} */
