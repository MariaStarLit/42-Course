/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-avel <mde-avel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 17:15:40 by mde-avel          #+#    #+#             */
/*   Updated: 2024/05/01 20:06:23 by mde-avel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(const std::string &nB) : nameB(nB) 
{
	this->WeaponB = NULL;
}

HumanB::~HumanB() {}

void	HumanB::attack()
{
	std::cout << this->nameB << " attacks with their "; 
	if (this->WeaponB)
		std::cout << this->WeaponB->getType() << std::endl;
	else
		std::cout << "fists" << std::endl;
}

void	HumanB::setWeapon(Weapon &typeB) 
{
	this->WeaponB = &typeB;
}