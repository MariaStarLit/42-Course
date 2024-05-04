/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-avel <mde-avel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 17:15:50 by mde-avel          #+#    #+#             */
/*   Updated: 2024/05/03 18:40:10 by mde-avel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(const std::string &new_weapon)
{
	this->type = new_weapon;
}

Weapon::~Weapon() {}

const std::string	&Weapon::getType()
{
	return	(this->type);
}

void		Weapon::setType(const std::string &weapon_type) 
{
	this->type = weapon_type;
}