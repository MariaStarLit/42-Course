/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimarque <dimarque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 16:58:15 by dimarque          #+#    #+#             */
/*   Updated: 2022/11/25 14:15:35 by dimarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	sign;
	int	numb;
	int	i;

	sign = 1;
	numb = 0;
	i = 0;
	while ((str[i] > 8 && str[i] < 14) || (str[i] == 32))
		i++;
	if ((str[i] != '\0') && (str[i] == '+' || str[i] == '-'))
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while ((str[i] >= 48 && str[i] <= 57))
	{
		numb = numb * 10 + str[i] - 48;
		i++;
	}
	return (numb * sign);
}

/* 
int main()
{
	char str[] = "  -11";
	int val = ft_atoi(str);
	printf("%d", val);
	return 0;
} */