/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-avel <mde-avel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 17:01:33 by mde-avel          #+#    #+#             */
/*   Updated: 2023/08/05 17:04:50 by mde-avel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_lista **a, int flag)
{
	t_lista	*tmp;
	t_lista	*aux;

	if (!*a || !(*a)->next)
		return ;
	aux = (*a)->next->next;
	tmp = *a;
	*a = (*a)->next;
	(*a)->next = tmp;
	(*a)->next->next = aux;
	if (flag == 1)
		ft_printf("sa\n");
}

void	sb(t_lista **b, int flag)
{
	t_lista	*tmp;
	t_lista	*aux;

	if (!*b || !(*b)->next)
		return ;
	aux = (*b)->next->next;
	tmp = *b;
	*b = (*b)->next;
	(*b)->next = tmp;
	(*b)->next->next = aux;
	if (flag == 1)
		ft_printf("sb\n");
}

void	ss(t_lista **a, t_lista **b)
{
	sa(a, 2);
	sb(b, 2);
	ft_printf("ss\n");
}

void	pa(t_lista **a, t_lista **b)
{
	t_lista	*new;

	if (!*b)
		return ;
	new = (*b);
	*b = (*b)->next;
	ft_lstadd_front(a, new);
	ft_printf("pa\n");
}

void	pb(t_lista **a, t_lista **b)
{
	t_lista	*new;

	if (!*a)
		return ;
	new = *a;
	*a = (*a)->next;
	ft_lstadd_front(b, new);
	ft_printf("pb\n");
}
