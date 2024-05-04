/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-avel <mde-avel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 22:49:46 by mde-avel          #+#    #+#             */
/*   Updated: 2024/05/04 16:02:23 by mde-avel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl() {}

Harl::~Harl() 
{
	std::cout << std::endl << GREEN << "Harl is Gone!" << RESET << std::endl;
}

void	Harl::debug()
{
	std::cout << RED << "[DEBUG]" << RESET << std::endl;
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger.\nI really do!" << std::endl << std::endl;
}

void	Harl::info()
{
	std::cout << CYAN << "[INFO]" << RESET << std::endl;
	std::cout << "I cannot believe adding extra bacon costs more money.\nYou didn't put enough bacon in my burger!\nIf you did, I wouldn't be asking for more!" << std::endl << std::endl;
}

void	Harl::warning()
{
	std::cout << YELLOW << "[WARNING]" << RESET << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free.\nI've been coming for years whereas you started working here since last month." << std::endl << std::endl;
}

void	Harl::error()
{
	std::cout << RED << "[ERROR]" << RESET << std::endl;
	std::cout << "This is unacceptable!\nI want to speak to the manager now." << std::endl << std::endl;
}

void	Harl::complain( std::string level )
{
	int start = 4;
	std::string complains[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	for (int i = 0; i < 4; i++)
	{
		if (complains[i] == level)
			start = i;
	}
	switch (start)
	{
		case 0:
			debug();
			//fall through
		case 1:
			info();
			//fall through
		case 2:
			warning();
			//fall through
		case 3:
			error();
			break ;
		default:
			std::cout << CYAN << "[ Probably complaining about insignificant problems ]" << RESET << std::endl;
	}
}