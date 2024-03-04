/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimarque <dimarque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 17:09:15 by dimarque          #+#    #+#             */
/*   Updated: 2022/11/21 17:22:29 by dimarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int arg)
{
	int	x;

	x = 0;
	if (arg >= 32 && arg <= 126)
	{
		x = 1;
		return (x);
	}
	return (x);
}

/* int main()
{

	char c;

	c = 'Q';
	printf("\nResult when a printable character %c is passed 
	to isprint(): %d", c, isprint(c));
	printf("\nResult when a printable character %c is passed 
	to isprint(): %d", c, ft_isprint(c));

	c = '\n';
	printf("\nResult when a control character %c is passed to 
	isprint(): %d", c, isprint(c));
	printf("\nResult when a control character %c is passed to 
	isprint(): %d", c, ft_isprint(c));

	return 0;
} */