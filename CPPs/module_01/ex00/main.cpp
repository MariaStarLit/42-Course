/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-avel <mde-avel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 15:19:54 by mde-avel          #+#    #+#             */
/*   Updated: 2024/05/02 18:51:45 by mde-avel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
	Zombie one = Zombie("Alvin   ");
	one.announce();
		std::cout << std::endl;
	Zombie *two = newZombie("Brittany");
	two->announce();
		std::cout << std::endl;
	randomChump("Simon   ");
	randomChump("Theodore");
	randomChump("Jeanette");
	randomChump("Eleanor ");
		std::cout << std::endl;
	delete two;
		std::cout << std::endl;
	return (0);
}