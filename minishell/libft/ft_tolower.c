/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimarque <dimarque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 16:47:10 by dimarque          #+#    #+#             */
/*   Updated: 2022/10/24 16:55:07 by dimarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int ch)
{
	if (ch >= 65 && ch <= 90)
	{
		ch = ch + 32;
		return (ch);
	}
	return (ch);
}

/* int main()
{
	char c;

	c = 'm';
	printf("\n%c -> %c", c, tolower(c));
	printf("\n%c -> %c", c, ft_tolower(c));

	c = 'D';
	printf("\n%c -> %c", c, tolower(c));
	printf("\n%c -> %c", c, ft_tolower(c));

	c = '9';
	printf("\n%c -> %c", c, tolower(c));
	printf("\n%c -> %c", c, ft_tolower(c));
	return 0;
} */