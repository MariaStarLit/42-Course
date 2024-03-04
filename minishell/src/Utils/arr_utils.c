/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arr_size.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimarque <dimarque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 11:09:26 by dimarque          #+#    #+#             */
/*   Updated: 2023/11/17 11:09:26 by dimarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

int	arr_size(char **arr)
{
	int	i;
	int	count;

	if (!arr)
		return (0);
	i = 0;
	count = 0;
	while (arr[i])
	{
		if (arr[i][0])
			count++;
		i++;
	}
	return (count);
}

char	**ft_arrdup(t_minishell *ms, char **old)
{
	char	**new;
	int		index;

	index = 0;
	new = malloc(sizeof(char *) * (arr_size(old) + 1));
	if (!new)
		error(ms, 2, NULL, NULL);
	while (old && old[index])
	{
		new[index] = ft_strdup(old[index]);
		index++;
	}
	new[index] = NULL;
	return (new);
}

char	**list_to_array(t_minishell *ms, t_list **list)
{
	int		i;
	int		size;
	t_list	*tmp;
	char	**buf;
	char	*ident;

	i = 0;
	tmp = *list;
	size = ft_lstsize(tmp);
	buf = malloc(sizeof(char *) * (size + 1));
	if (!buf)
		error(ms, 2, NULL, NULL);
	while (tmp && i < size)
	{
		ident = ft_strjoin(tmp->ident, "=");
		buf[i] = ft_strjoin(ident, (char *)tmp->content);
		tmp = tmp->next;
		free(ident);
		i++;
	}
	buf[i] = 0;
	return (buf);
}

void	print_arr(char *str, char **arr)
{
	int	i;
	int	j;

	i = 0;
	if (!arr || arr[i])
		return ;
	j = arr_size(arr);
	printf("	%s:\n", str);
	while (arr[i] && i < j)
		printf("			%s\n", arr[i++]);
}
