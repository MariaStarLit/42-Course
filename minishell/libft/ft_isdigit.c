/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimarque <dimarque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 15:14:52 by dimarque          #+#    #+#             */
/*   Updated: 2022/10/31 17:15:32 by dimarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <ctype.h>

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
	{
		return (1);
	}
	return (0);
}

/* int main()
{

	char c;
	c = '9';
	printf("\nResult when numeric character is passed: %d", isdigit(c));
	printf("\nResult when numeric character is passed: %d", ft_isdigit(c));
	c = '+';
	printf("\nResult when non-numeric character is passed: %d", isdigit(c));
	printf("\nResult when non-numeric character is passed: %d", ft_isdigit(c));

	return 0;
} */