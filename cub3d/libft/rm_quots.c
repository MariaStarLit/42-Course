/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rm_quots.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-avel <mde-avel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 18:15:59 by mde-avel          #+#    #+#             */
/*   Updated: 2024/02/23 18:40:07 by mde-avel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*rm_fl_quotes(char *str)
{
	char	*new;
	int		i;
	int		j;
	int		len;

	i = 0;
	j = 1;
	len = (int)ft_strlen(str) - 2;
	if (!str)
		return (NULL);
	new = malloc(sizeof(char) * (len + 1));
	if (!new)
		return (NULL);
	while (j <= len) 
	{
		new[i] = str[j];
		i++;
		j++;
	}
	new[i] = '\0';
	free(str);
	return (new);
}

//printf("cmd: |%s| c: %c\n", aux, aux[len]);
//printf("new: |%s| c: %c \n", aux, aux[len]);
char	*find_quotes(char *cmd_line, char quote, int flag)
{
	char	*new;
	char	*aux;
	int		len;

	aux = ft_strdup(cmd_line);
	len = ft_strlen(aux) - 1;
	while (flag != 3)
	{
		if ((aux[0] == quote && aux[len] == quote)
			&& (flag == 1 || flag == 2))
		{
			aux = rm_fl_quotes(aux);
			len = ft_strlen(aux) - 1;
		}
		else
			flag = 3;
	}
	new = ft_strdup(aux);
	free(aux);
	return (new);
}

char	*quote_marks(char *cmd_line)
{
	char	*new;
	int		len;

	len = ft_strlen(cmd_line) - 1;
	if (cmd_line[0] == '\'' && cmd_line[len] == '\'')
		new = find_quotes(cmd_line, '\'', 1);
	if (cmd_line[0] == '"' && cmd_line[len] == '"')
		new = find_quotes(cmd_line, '"', 2);
	return (new);
}

/*
int	main(void)
{
	char	str[] = "\"\"\"'''Porra'''\"\"\"";
	char	*q;

	q = quote_marks(str);
	printf("quot_marks: |%s|\n", q);
	free (q);
}
*/