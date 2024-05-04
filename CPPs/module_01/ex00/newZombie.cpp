/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-avel <mde-avel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 15:19:59 by mde-avel          #+#    #+#             */
/*   Updated: 2024/05/03 19:40:01 by mde-avel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

// Allocation on the heap
Zombie* newZombie( std::string name )
{
	Zombie* new_z = new Zombie(name);
	if (!new_z)
		return (NULL);
	return (new_z);
}