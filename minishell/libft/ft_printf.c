/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimarque <dimarque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 17:06:45 by dimarque          #+#    #+#             */
/*   Updated: 2023/08/08 15:23:48 by dimarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printf(const char *str, ...)
{
	int		i;
	int		print;
	va_list	ap;

	i = 0;
	print = 0;
	va_start(ap, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			print += ft_options(ap, str[i + 1]);
			i++;
		}
		else
		{
			write(1, &str[i], 1);
			print++;
		}
		i++;
	}
	va_end(ap);
	return (print);
}

/* int	main(void)
{
	ft_printf("%%c = %c\n%%s = %s\n%%p = %p\n%%u = %u\n%%d = %d\n%%i = %i\n%%x =
			%x\n%%X = %X", 'D', "leite", '1000', 165156446, 10, 100, 1515,
			1515);
	printf("%%c = %c\n%%s = %s\n%%p = %p\n%%u = %u\n%%d = %d\n%%i = %i\n%%x =
			%x\n%%X = %X", 'D', "leite", '1000', 165156446, 10, 100, 1515,
			1515);
	printf("\nprintf(ft_printf())\n");
	printf(ft_printf("%%c = %c\n%%s = %s\n%%p = %p\n%%u = %u\n%%d = %d\n%%i =
				%i\n%%x = %x\n%%X = %X", 'D', "leite", '1000', 165156446, 10,
				100, 1515, 1515));
	printf(printf("%%c = %c\n%%s = %s\n%%p = %p\n%%u = %u\n%%d = %d\n%%i =
				%i\n%%x = %x\n%%X = %X", 'D', "leite", '1000', 165156446, 10,
				100, 1515, 1515));
	return (0);
} */