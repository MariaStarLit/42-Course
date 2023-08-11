/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-avel <mde-avel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 18:10:30 by mde-avel          #+#    #+#             */
/*   Updated: 2023/08/10 17:43:20 by mde-avel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>

typedef unsigned long long	t_ull;

int	ft_printf(const char *s, ...);
int	ft_putnbr(int n);
int	ft_putchar(char c);
int	ft_putstr(char *s);
int	ft_putnbru(unsigned int n);
int	ft_puthex(unsigned long n, char ch);
int	ft_putvod(t_ull n);

#endif