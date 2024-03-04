/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimarque <dimarque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 15:46:52 by dimarque          #+#    #+#             */
/*   Updated: 2022/11/18 16:21:45 by dimarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *str, void (*f)(unsigned int, char *))
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		f(i, &str[i]);
		i++;
	}
}

/* char	f(unsigned int i, char c)
{
	i++;
	c = 'D';
	return (c);
}

int	main(void)
{
	char *str = "leite-teste-ola";
	ft_striteri(str, f);
	return (0);
} */