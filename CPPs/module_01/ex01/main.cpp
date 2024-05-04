/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-avel <mde-avel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 18:31:40 by mde-avel          #+#    #+#             */
/*   Updated: 2024/05/02 20:13:43 by mde-avel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
	std::cout << YELLOW << "Run!!!" << RESET << std::endl;
	Zombie *horde = zombieHorde(5, "Brian");
	for (int i = 0; i < 5; i++)
		horde[i].announce();
	std::cout << YELLOW << "A Horde of 5 Zombies it comming at you!!!" << RESET << std::endl;
	delete [] horde;

	std::cout << std::endl << std::endl << YELLOW << "Run!!!" << RESET << std::endl;
	horde = zombieHorde(10, "Crasy");
	for (int i = 0; i < 10; i++)
		horde[i].announce();
	std::cout << YELLOW << "A Horde of 10 Zombies it comming at you!!!" << RESET << std::endl;
	delete [] horde;

	std::cout << std::endl << std::endl << YELLOW << "Run!!!" << RESET << std::endl;
	horde = zombieHorde(0, "Hungry");
	horde[0].announce();
	std::cout << YELLOW << "Oh wait... No need. You're safe!" << RESET << std::endl;
	delete [] horde;
}