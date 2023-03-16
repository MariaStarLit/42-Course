/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-avel <mde-avel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 19:01:16 by mde-avel          #+#    #+#             */
/*   Updated: 2022/11/22 16:29:14 by mde-avel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * It counts the number of elements in a linked list.
 * 
 * @param lst A pointer to the first element of a linked list.
 * 
 * @return The number of elements in the list.
 */

int	ft_lstsize(t_list *lst)
{
	int		cont;

	cont = 0;
	if (!lst)
		return (0);
	while (lst)
	{
		lst = lst->next;
		cont++;
	}
	return (cont);
}
