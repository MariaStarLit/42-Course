/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-avel <mde-avel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 17:40:46 by mde-avel          #+#    #+#             */
/*   Updated: 2022/11/29 14:26:09 by mde-avel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "lib/libft.h"
# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>

typedef unsigned long long	t_ull;

int	ft_printf(const char *s, ...);
int	ft_putnbru(unsigned int n);
int	ft_puthex(unsigned long n, char ch);
int	ft_putvod(t_ull n);

#endif