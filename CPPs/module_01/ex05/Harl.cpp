/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-avel <mde-avel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 22:49:46 by mde-avel          #+#    #+#             */
/*   Updated: 2024/05/03 00:09:49 by mde-avel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl() 
{
	this->levels[0] = &Harl::debug;
	this->levels[1] = &Harl::info;
	this->levels[2] = &Harl::warning;
	this->levels[3] = &Harl::error;
}

Harl::~Harl() 
{
	std::cout << GREEN << "Harl is Gone!" << RESET << std::endl;
}

void	Harl::debug()
{
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger.\nI really do!\n" << std::endl;
}

void	Harl::info()
{
	std::cout << "I cannot believe adding extra bacon costs more money.\nYou didn't put enough bacon in my burger!\nIf you did, I wouldn't be asking for more!\n" << std::endl;
}

void	Harl::warning()
{
	std::cout << "I think I deserve to have some extra bacon for free.\nI've been coming for years whereas you started working here since last month.\n" << std::endl;
}

void	Harl::error()
{
	std::cout << "This is unacceptable!\nI want to speak to the manager now.\n" << std::endl;
}

void	Harl::complain( std::string level )
{
	int flag = 0;
	std::string complains[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	for (int i = 0; i < 4; i++)
	{
		if (level == complains[i])
		{
			(this->*levels[i])();
			flag = 1;
		}	
	}
	if (!flag)
		std::cout << RED << "Error! Worng level of complain." << RESET << std::endl;
}