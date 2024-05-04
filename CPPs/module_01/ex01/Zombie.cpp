/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-avel <mde-avel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 18:34:16 by mde-avel          #+#    #+#             */
/*   Updated: 2024/05/02 20:09:52 by mde-avel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(void) : _zombie_name("Nothing") {}

Zombie::Zombie(std::string new_name) : _zombie_name(new_name) {}

Zombie::~Zombie(void)
{
	std::cout << this->_zombie_name << ": " << GREEN << "Desitegrated!" << RESET << std::endl;
}

void	Zombie::announce( void )
{
	if (getIsHorde() == 1)
		std::cout << this->_zombie_name << ": " << PURPLE << "BraiiiiiiinnnzzzZ..." << RESET << std::endl;
}
void	Zombie::setName(std::string z_name)
{
	this->_zombie_name = z_name;
}
