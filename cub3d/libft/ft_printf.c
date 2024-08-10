/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-avel <mde-avel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 17:14:55 by mde-avel          #+#    #+#             */
/*   Updated: 2024/02/22 18:25:49 by mde-avel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Write the integer n & returns the number of digits printed.
int	ft_putnbr(long n)
{
	int	cont;

	cont = 0;
	if (n < 0)
	{
		ft_putchar('-');
		n *= -1;
		cont++;
	}
	if (n >= 10)
		cont += ft_putnbr(n / 10);
	cont += ft_putchar(n % 10 + 48);
	return (cont);
}

/**
 * It's a function that takes a string and a variable number of arguments, 
 * and prints the string with.
 * the arguments inserted in the appropriate places
 * 
 * @param ch The character that will be used to determine what to print.
 * @param var The va_list variable that will hold the values of the arguments.
 * @param len the length of the string
 * 
 * @return The number of characters printed.
 */
static int	writes(const char ch, va_list var, size_t	len)
{
	if (!var)
		return (0);
	if (ch == 'c')
		len = ft_putchar(va_arg(var, int));
	if (ch == 's')
		len = ft_putstr(va_arg(var, char *));
	if (ch == 'd' || ch == 'i')
		len = ft_putnbr(va_arg(var, long));
	if (ch == 'u')
		len = ft_putnbru(va_arg(var, unsigned int));
	if (ch == 'x' || ch == 'X')
		len = ft_puthex(va_arg(var, unsigned int), ch);
	if (ch == 'p')
		len = ft_putvod(va_arg(var, t_ull));
	if (ch == '%')
		len = ft_putchar('%');
	return (len);
}

int	ft_printf(const char *s, ...)
{
	va_list	var;
	size_t	i;
	size_t	cont;

	va_start(var, s);
	i = 0;
	cont = 0;
	while (s[i])
	{
		if (s[i] == '%')
		{
			i++;
			cont += writes(s[i], var, cont);
		}
		else
		{
			cont += ft_putchar(s[i]);
		}
		i++;
	}
	va_end(var);
	return (cont);
}
/*
int	main(void)
{
	char	*p;
	int		ret;
	long	nb;

	nb = -2147483648;
	p = "Minhaf: |%i|";
	ret = ft_printf(p, nb);
	printf(" -> return: %d\n", ret);
	ret = printf("Printf: |%ld|", nb);
	printf(" -> return: %d\n", ret);
}
*/
	//char	l; char			*fio;
	//l = 'l'; fio = NULL;