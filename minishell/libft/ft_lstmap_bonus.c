/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimarque <dimarque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 15:37:15 by dimarque          #+#    #+#             */
/*   Updated: 2022/11/21 16:04:27 by dimarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*node;

	node = NULL;
	while (lst)
	{
		ft_lstadd_back(&node, ft_lstnew(f(lst->content)));
		lst = lst->next;
	}
	if (node == NULL)
		ft_lstclear(&lst, del);
	return (node);
}
