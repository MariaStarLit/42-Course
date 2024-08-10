/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-avel <mde-avel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 16:44:54 by mde-avel          #+#    #+#             */
/*   Updated: 2022/11/24 14:58:34 by mde-avel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Iterate through a linked list and apply a function to each element
 * 
 * @param lst A pointer to the first element of a linked list.
 * @param f a function that takes a void pointer and returns nothing.
 * 
 * @return A new list with the content of each element of the list passed 
 * as parameter, but with the function f applied to each element.
 */

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*temp;

	if (!lst)
		return ;
	while (lst)
	{
		temp = lst->next;
		f(lst->content);
		lst = temp;
	}
}
