/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-avel <mde-avel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 00:53:18 by mde-avel          #+#    #+#             */
/*   Updated: 2024/05/03 19:41:06 by mde-avel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

static int	_is_horde;

Zombie *zombieHorde(int N, std::string name)
{
	if (N <= 0)
	{
		std::cout << RED 
				  << "Really! There's no zombies arrond. Let alone a Horde! (-_-)" 
				  << RESET << std::endl;
		_is_horde = 0;
		return (NULL);
	}
	
	Zombie *apocalypse = new Zombie[N];
	if (!apocalypse)
		return (NULL);
	for (int i = 0; i < N; i++)
	{
		apocalypse[i].setName(name);
	}
	_is_horde = 1;
	return (apocalypse);
}

int getIsHorde(void)
{
	int flag = _is_horde;
	return (flag);
}