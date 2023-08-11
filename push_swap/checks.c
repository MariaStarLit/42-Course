/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-avel <mde-avel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 17:07:31 by mde-avel          #+#    #+#             */
/*   Updated: 2023/08/10 17:55:32 by mde-avel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/** The function "checkers" checks if the input arguments are valid integers and
 * if there are any repeated numbers.
 * 
 * @param av A pointer to an array of strings (arguments)
 * @param len The parameter `len` represents the number of elements in the 
 * array `av`.
 * 
 * @return The function `checkers` returns an integer value.
 */
int	checkers(char **s)
{
	int		i;
	long	n;

	i = 0;
	n = 0;
	while (s[i])
	{
		if (check_if_num(s[i]) == 0)
			return (0);
		n = ft_atoi(s[i]);
		if (n > 2147483647 || n < -2147483648)
			return (0);
		i++;
	}
	if (check_repeat_num(s, n) == 0)
		return (0);
	return (1);
}

int	check_if_num(char *s)
{
	int	i;

	i = 0;
	if (s[i] == '-' || s[i] == '+')
		i++;
	while (s[i])
	{
		if (s[i] >= '0' && s[i] <= '9')
			i++;
		else
			return (0);
	}
	if (s[i] == '\0')
		return (1);
	return (0);
}

int	check_repeat_num(char **s, int n)
{
	int	i;
	int	nbr;
	int	flag;

	i = 0;
	nbr = 0;
	flag = 0;
	while (s[i])
	{
		nbr = ft_atoi(s[i]);
		if (nbr == n)
			flag++;
		if (flag == 2)
			return (0);
		i++;
	}
	return (1);
}

/** The function checks if a linked list is organized in ascending order.
 * 
 * @param a a is a pointer to a pointer to a linked list. The linked list
 * is of type t_lista, which has two members: n (an integer) and next 
 * (a pointer to the next node in the list).
 * 
 * @return an integer value. If the list pointed to by `a` is organized 
 * in ascending order, the function returns 1. Otherwise, it returns 0.
 */
int	check_if_organized(t_lista **a)
{
	t_lista	*tmp;

	tmp = *a;
	if (tmp && tmp->next)
	{
		while (tmp->next)
		{
			if (tmp->n > tmp->next->n)
				return (0);
			tmp = tmp->next;
		}
	}
	return (1);
}
