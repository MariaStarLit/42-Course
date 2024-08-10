/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-avel <mde-avel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 11:57:20 by mde-avel          #+#    #+#             */
/*   Updated: 2022/11/24 14:58:53 by mde-avel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*void	printlist(t_list *head)
{
	t_list	*temp;

	temp = head;
	while (temp != NULL)
	{
		printf("%p -", temp->content);
		temp = temp->next;
	}
	printf("\n");
}*/

/**
 * Create a new list node with the given content and return it.
 * 
 * @param content the content of the new element
 * 
 * @return A pointer to a new list element.
 */

t_list	*ft_lstnew(void *content)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
}

/*int	main(void)
{
	t_list	*head;
	t_list	*aux;

	aux = ft_lstnew((void *)4);
	head = aux;
	aux = ft_lstnew((void *)2);
	aux->next = head;
	head = aux;
	aux = ft_lstnew((void *)5);
	aux->next = head;
	head = aux;

	printlist(head);
}*/
