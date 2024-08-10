/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-avel <mde-avel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 18:07:19 by mde-avel          #+#    #+#             */
/*   Updated: 2022/11/24 14:58:02 by mde-avel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Checks if the passed character is an ASCII character
 * 
 * @param c The character to be checked.
 * 
 * @return 1 if the character is ascii, 0 if not.
 */

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
	{
		return (1);
	}
	else
		return (0);
}

/*int	main(void)
{
	int	aci = 128;

	printf("minha f: %d\n", ft_isascii(aci));
	printf("isascii: %d\n", isascii(aci));
}*/
