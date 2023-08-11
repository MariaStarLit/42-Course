/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-avel <mde-avel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 17:05:20 by mde-avel          #+#    #+#             */
/*   Updated: 2023/08/05 17:05:26 by mde-avel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_lista **a, int flag)
{
	t_lista	*tmp;

	if (!*a || !(*a)->next)
		return ;
	tmp = *a;
	*a = (*a)->next;
	tmp->next = NULL;
	ft_lstadd_back(a, tmp);
	if (flag == 1)
		ft_printf("ra\n");
}

void	rb(t_lista **b, int flag)
{
	t_lista	*tmp;

	if (!*b || !(*b)->next)
		return ;
	tmp = *b;
	*b = (*b)->next;
	tmp->next = NULL;
	ft_lstadd_back(b, tmp);
	if (flag == 1)
		ft_printf("rb\n");
}

void	rr(t_lista **a, t_lista **b)
{
	ra(a, 2);
	rb(b, 2);
	ft_printf("rr\n");
}
