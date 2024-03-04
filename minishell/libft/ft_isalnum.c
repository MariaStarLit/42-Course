/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimarque <dimarque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 15:24:58 by dimarque          #+#    #+#             */
/*   Updated: 2022/11/16 17:40:50 by dimarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int arg)
{
	int	x;

	x = 0;
	if ((arg >= 65 && arg <= 90) || (arg >= 97 && arg <= 122))
	{
		x = 1;
		return (x);
	}
	else if (arg >= 48 && arg <= 57)
	{
		x = 1;
		return (x);
	}
	return (x);
}

/* int main()
{
	char c;
	int result, res;

	c = '5';
	result = isalnum(c);
	res = ft_isalnum(c);
	printf("When %c is passed, return value is %d\n", c, result);
	printf("When %c is passed, return value is %d\n", c, res);

	c = 'Q';
	result = isalnum(c);
	res = ft_isalnum(c);
	printf("When %c is passed, return value is %d\n", c, result);
	printf("When %c is passed, return value is %d\n", c, res);

	c = 'l';
	result = isalnum(c);
	res = ft_isalnum(c);
	printf("When %c is passed, return value is %d\n", c, result);
	printf("When %c is passed, return value is %d\n", c, res);

	c = '+';
	result = isalnum(c);
	res = ft_isalnum(c);
	printf("When %c is passed, return value is %d\n", c, result);
	printf("When %c is passed, return value is %d\n", c, res);
	return 0;
} */