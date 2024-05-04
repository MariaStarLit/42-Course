/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-avel <mde-avel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 17:15:34 by mde-avel          #+#    #+#             */
/*   Updated: 2024/05/01 20:01:42 by mde-avel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(const std::string &nA, Weapon &typeA) : nameA(nA), WeaponA(typeA) {}

HumanA::~HumanA() {}

void	HumanA::attack()
{
	std::cout << this->nameA << " attacks with their " << this->WeaponA.getType() << std::endl;
}