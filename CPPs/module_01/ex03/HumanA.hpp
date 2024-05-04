/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-avel <mde-avel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 17:15:37 by mde-avel          #+#    #+#             */
/*   Updated: 2024/05/01 20:01:47 by mde-avel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
#define HUMANA_HPP

#include "Weapon.hpp"

class HumanA
{
	private:
		std::string nameA;
		Weapon		&WeaponA;
	public: 		
		HumanA(const std::string &nA, Weapon &typeA); //Constructor
		~HumanA(void);		//Destructor
		
		//Methoed
		void	attack(void);
};

#endif