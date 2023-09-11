/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-avel <mde-avel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 12:03:05 by mde-avel          #+#    #+#             */
/*   Updated: 2023/09/11 14:32:22 by mde-avel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

t_map	*map(void)
{
	static t_map	map;

	return (&map);
}

t_clone	*clone_m(void)
{
	static t_clone	clone_map;

	return (&clone_map);
}

t_player	*player(void)
{
	static t_player	ash;

	return (&ash);
}
