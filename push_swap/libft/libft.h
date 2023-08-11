/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-avel <mde-avel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 16:52:42 by mde-avel          #+#    #+#             */
/*   Updated: 2023/08/09 19:33:35 by mde-avel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <string.h>

typedef struct s_lista
{
	long			n;
	int				n_simple;
	struct s_lista	*next;
}	t_lista;

//libft_1.c
t_lista		*new_node(long n, int n_simple);
void		ft_lstadd_front(t_lista **lst, t_lista *new);
void		ft_lstadd_back(t_lista **lst, t_lista *new);
t_lista		*ft_lstlast(t_lista *lst);
int			ft_lstsize(t_lista *lst);

//lifbt_2.c
size_t		ft_strlen(char *str);
char		**ft_split(char *s, char c);

//lifbt_3.c
long		ft_atoi(char *s);
void		ft_bzero(void *str, size_t n);
void		*ft_calloc(size_t nitems, size_t size);
char		*ft_strdup(char *str);

#endif