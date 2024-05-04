/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-avel <mde-avel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 15:20:05 by mde-avel          #+#    #+#             */
/*   Updated: 2024/05/01 01:43:14 by mde-avel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(void) : name("Zombie") {}

Zombie::Zombie(std::string zombie_name) : name(zombie_name) {}

Zombie::~Zombie(void)
{
	std::cout << this->name << ": " << GREEN << "Desitegrated!" << RESET << std::endl;
}

void Zombie::announce( void )
{
	std::cout << this->name << ": " << PURPLE << "BraiiiiiiinnnzzzZ..." << RESET << std::endl;
}