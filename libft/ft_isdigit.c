/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-avel <mde-avel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 18:30:36 by mde-avel          #+#    #+#             */
/*   Updated: 2022/11/24 14:58:06 by mde-avel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Checks If the character is a digit.
 * 
 * @param c The character to be checked.
 * 
 * @return 1 if the character is a digit, 0 if not.
 */

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
	{
		return (1);
	}
	else
		return (0);
}

/*int	main(void)
{
	int	dig = 59;

	printf("miha fu: %d\n", ft_isdigit(dig));
	printf("isdigit: %d\n", isdigit(dig));
}*/
