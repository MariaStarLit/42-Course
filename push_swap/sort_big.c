/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-avel <mde-avel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 17:08:39 by mde-avel          #+#    #+#             */
/*   Updated: 2023/08/08 17:38:16 by mde-avel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// The function simpler_num assigns a number to each element in a linked 
// list, according to the credent order in which they should appear.
// The smallest value receiving the number 1 and the highet len.
void	simpler_num(t_lista **a, int len)
{
	t_lista	*tmp;
	int		min;
	int		i;

	i = 1;
	while (i <= len)
	{
		tmp = *a;
		min = 2147483647;
		while (tmp)
		{
			if (min > tmp->n && tmp->n_simple == 0)
				min = tmp->n;
			tmp = tmp->next;
		}
		tmp = *a;
		while (tmp && tmp->n != min)
			tmp = tmp->next;
		tmp->n_simple = i;
		i++;
	}
}

/**
 * The radix function sorts a linked list of integers using the radix sort 
 * algorithm.
 * @param a Pointer to a linked list representing the main list of numbers.
 * @param b The parameter "b" is a pointer to a linked list.
 * @param n_bits The parameter `n_bits` represents the number of bits in 
 * the binary representation of the numbers in the list.
 * @param len The parameter "len" represents the length of the list or array 
 * that is being sorted.
 */
void	radix(t_lista **a, t_lista **b, int n_bits, int len)
{
	int		i;
	int		j;
	t_lista	*tmp;

	i = 0;
	tmp = *a;
	while (i < n_bits)
	{
		j = 0;
		while (j++ < len)
		{
			tmp = *a;
			if ((tmp->n_simple >> i & 1) == 1)
				ra(a, 1);
			else
				pb(a, b);
		}
		while (ft_lstsize(*b))
			pa(a, b);
		i++;
	}
}

// The function "sort_big" implements a radix sort algorithm to sort a linked
// list of numbers in ascending order.
void	sort_big(t_lista **a, t_lista **b)
{
	int		len;
	int		n_bits;

	len = ft_lstsize(*a);
	if (check_if_organized(a) == 0)
	{
		simpler_num(a, len);
		n_bits = 0;
		while ((len >> n_bits) != 0)
			n_bits++;
		radix(a, b, n_bits, len);
	}
}
