/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimarque <dimarque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 14:43:57 by dimarque          #+#    #+#             */
/*   Updated: 2022/11/25 14:22:01 by dimarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_numblen(int n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len++;
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	int			len;
	long int	numb;
	char		*res;

	numb = n;
	len = ft_numblen(n);
	res = (char *)malloc(len + 1);
	if (!res)
		return (NULL);
	res[len] = '\0';
	while (len > 0)
	{
		if (numb < 0)
			numb *= -1;
		res[--len] = numb % 10 + 48;
		numb /= 10;
	}
	if (res[0] == '0')
		res[0] = '-';
	if (n == 0)
		res[0] = '0';
	return (res);
}

/* #include <stdio.h>
int	main(void)
{
	printf("%s\n", ft_itoa(-2147483648));
	return (0);
} */
