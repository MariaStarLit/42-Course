/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-avel <mde-avel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 18:16:19 by mde-avel          #+#    #+#             */
/*   Updated: 2022/11/24 14:58:10 by mde-avel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Checks the character is a printable character.
 * 
 * @param c The character to be checked.
 * 
 * @return 1 if the character is printable, 0 if not.
 */

int	ft_isprint(int c)
{
	if (c >= ' ' && c <= '~')
	{
		return (1);
	}
	else
		return (0);
}

/*int	main(void)
{
	int	prin = 127;

	printf("minha f: %d\n", ft_isprint(prin));
	printf("isprint: %d\n", isprint(prin));
}*/
