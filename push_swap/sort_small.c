/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-avel <mde-avel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 17:27:50 by mde-avel          #+#    #+#             */
/*   Updated: 2023/08/10 13:48:21 by mde-avel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// The function "sort_small" is used to sort small lists of numbers 
// (2, 3, 4 or 5 integers) using various sorting algorithms.
void	sort_small(t_lista **a, t_lista **b, int len)
{
	if (len == 2)
		if ((*a)->n > (*a)->next->n)
			sa(a, 1);
	if (len == 3)
	{
		while ((check_if_organized(a) == 0))
		{
			if ((*a)->next->next->n < (*a)->n)
				rra(a, 1);
			if ((*a)->n > (*a)->next->n)
				sa(a, 1);
			if ((*a)->next->next->n < (*a)->next->n)
				rra(a, 1);
		}
	}
	if (len == 4)
		sort_four(a, b);
	if (len == 5)
		sort_five(a, b);
}

void	sort_four(t_lista **a, t_lista **b)
{
	t_lista	*last;

	if (check_if_organized(a) == 0)
	{
		last = ft_lstlast(*a);
		if ((*a)->next->n < (*a)->n && (*a)->next->n < (*a)->next->next->n
			&& (*a)->next->n < last->n)
			sa(a, 1);
		if ((*a)->next->next->n < (*a)->n && (*a)->next->next->n < last->n
			&& (*a)->next->next->n < (*a)->next->n)
		{
			rra(a, 1);
			rra(a, 1);
		}
		if (last->n < (*a)->n && last->n < (*a)->next->n
			&& last->n < (*a)->next->next->n)
			rra(a, 1);
		pb(a, b);
		sort_small(a, b, 3);
		pa(a, b);
	}
}

void	find_min_nbr(t_lista **a, t_lista *last)
{
	if ((*a)->next->n < (*a)->n && (*a)->next->n < (*a)->next->next->n
		&& (*a)->next->n < (*a)->next->next->next->n
		&& (*a)->next->n < last->n)
		sa(a, 1);
	else if ((*a)->next->next->n < (*a)->n && (*a)->next->next->n < last->n
		&& (*a)->next->next->n < (*a)->next->n
		&& (*a)->next->next->n < (*a)->next->next->next->n)
	{
		ra(a, 1);
		ra(a, 1);
	}
	else if ((*a)->next->next->next->n < (*a)->n && (*a)->next->next->next->n
		< last->n && (*a)->next->next->next->n < (*a)->next->n
		&& (*a)->next->next->next->n < (*a)->next->next->n)
	{
		rra(a, 1);
		rra(a, 1);
	}
	else if (last->n < (*a)->n && last->n < (*a)->next->n && last->n
		< (*a)->next->next->n && last->n < (*a)->next->next->next->n)
		rra(a, 1);
	else
		return ;
}

void	sort_five(t_lista **a, t_lista **b)
{
	t_lista	*last;

	if (check_if_organized(a) == 0)
	{
		last = ft_lstlast(*a);
		find_min_nbr(a, last);
		pb(a, b);
		sort_four(a, b);
		pa(a, b);
	}
}
