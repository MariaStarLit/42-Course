/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimarque <dimarque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 14:11:29 by dimarque          #+#    #+#             */
/*   Updated: 2022/11/16 17:40:47 by dimarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
	{
		return (1);
	}
	return (0);
}

/* int main()
{

	char c;
	c = 'F';
	printf("\nResult when uppercase alphabet is passed: %d", isalpha(c));
	printf("\nResult when uppercase alphabet is passed: %d", ft_isalpha(c));

	c = 'q';
	printf("\nResult when lowercase alphabet is passed: %d", isalpha(c));
	printf("\nResult when lowercase alphabet is passed: %d", ft_isalpha(c));

	c = '+';
	printf("\nResult when non-alphabetic character is passed: %d", isalpha(c));
	printf("\nResult when non-alphabetic character is passed: %d", ft_isalpha(c));

	return 0;
} */