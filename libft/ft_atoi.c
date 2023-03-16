/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-avel <mde-avel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 15:16:47 by mde-avel          #+#    #+#             */
/*   Updated: 2022/11/24 14:57:46 by mde-avel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * It takes a string, and returns the integer value of that string
 * 
 * @param str This is the string that we are going to convert to an integer.
 * 
 * @return the number of characters in the string.
 */

int	ft_atoi(const char *str)
{
	long	i;
	long	num;
	int		sinal;

	num = 0;
	sinal = 1;
	i = 0;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r' || str[i] == ' ')
		i++;
	if ((str[i] == '-') || (str[i] == '+'))
	{
		if (str[i] == '-')
			sinal = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + (str[i] - 48);
		i++;
	}
	return (num * sinal);
}

/*int	main(void)
{
	const char	a[] = "  \r\t\n\f +2847r24";

	printf("mine: %d\n", ft_atoi(a));
	printf("atoi: %d\n", atoi(a));
}*/
