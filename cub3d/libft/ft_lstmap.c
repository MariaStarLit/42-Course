/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-avel <mde-avel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 17:43:18 by mde-avel          #+#    #+#             */
/*   Updated: 2022/11/24 14:58:49 by mde-avel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * It takes a list, applies a function to each element of the list, and 
 * returns a new list with the results of the function.
 * 
 * @param lst The list to iterate over.
 * @param f a function that takes a void pointer and returns a void pointer.
 * @param del a function that takes a pointer to a single element of the list
 * and frees the memory of that element.
 * 
 * @return A new linked list with the content of the original list, but each 
 * element has been transformed by a function.
 */

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *),	void (*del)(void *))
{
	t_list	*new;
	t_list	*newlst;

	if (!lst || !f)
		return (NULL);
	newlst = NULL;
	while (lst)
	{
		new = ft_lstnew(f(lst->content));
		if (!new)
		{
			ft_lstdelone(new, del);
			return (NULL);
		}
		lst = lst->next;
		ft_lstadd_back(&newlst, new);
	}
	return (newlst);
}
