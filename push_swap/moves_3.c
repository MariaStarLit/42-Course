/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-avel <mde-avel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 17:06:14 by mde-avel          #+#    #+#             */
/*   Updated: 2023/08/05 17:06:20 by mde-avel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_lista **a, int flag)
{
	t_lista	*last;
	t_lista	*tmp;

	if (!*a || !(*a)->next)
		return ;
	tmp = *a;
	while (tmp->next->next != NULL)
	{
		tmp = tmp->next;
	}
	last = tmp->next;
	tmp->next = NULL;
	ft_lstadd_front(a, last);
	if (flag == 1)
		ft_printf("rra\n");
}

void	rrb(t_lista **b, int flag)
{
	t_lista	*last;
	t_lista	*tmp;

	if (!*b || !(*b)->next)
		return ;
	tmp = *b;
	while (tmp->next->next != NULL)
	{
		tmp = tmp->next;
	}
	last = tmp->next;
	tmp->next = NULL;
	ft_lstadd_front(b, last);
	if (flag == 1)
		ft_printf("rrb\n");
}

void	rrr(t_lista **a, t_lista **b)
{
	rra(a, 2);
	rrb(b, 2);
	ft_printf("rrr\n");
}
