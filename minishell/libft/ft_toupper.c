/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimarque <dimarque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 16:09:58 by dimarque          #+#    #+#             */
/*   Updated: 2022/10/24 16:56:43 by dimarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int ch)
{
	if (ch >= 97 && ch <= 122)
	{
		ch = ch - 32;
		return (ch);
	}
	return (ch);
}

/* int main()
{
	char c;

	c = 'm';
	printf("\n%c -> %c", c, toupper(c));
	printf("\n%c -> %c", c, ft_toupper(c));

	c = 'D';
	printf("\n%c -> %c", c, toupper(c));
	printf("\n%c -> %c", c, ft_toupper(c));

	c = '9';
	printf("\n%c -> %c", c, toupper(c));
	printf("\n%c -> %c", c, ft_toupper(c));
	return 0;
} */