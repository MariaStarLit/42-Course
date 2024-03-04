/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimarque <dimarque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 15:52:13 by dimarque          #+#    #+#             */
/*   Updated: 2022/11/21 17:21:57 by dimarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nitems, size_t size)
{
	void	*ptr;

	ptr = malloc(size * nitems);
	if (!ptr)
		return (NULL);
	ft_memset(ptr, 0, size * nitems);
	return (ptr);
}

/* int main()
{
	char *str1;

	str1 = ft_calloc(3, 3);

	printf("%s", str1);

	return (0);
} */