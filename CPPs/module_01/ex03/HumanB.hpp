/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-avel <mde-avel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 17:15:44 by mde-avel          #+#    #+#             */
/*   Updated: 2024/05/01 20:02:02 by mde-avel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"

class HumanB
{
	private:
		std::string nameB;
		Weapon		*WeaponB;

	public:
		HumanB(const std::string &nB);		//Constructor
		~HumanB(void);				//Destructor
		
		//Methoed
		void	attack(void);
		void	setWeapon(Weapon &typeB);
};

#endif