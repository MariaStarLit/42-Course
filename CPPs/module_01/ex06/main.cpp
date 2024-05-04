/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-avel <mde-avel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 22:49:51 by mde-avel          #+#    #+#             */
/*   Updated: 2024/05/02 02:33:49 by mde-avel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << RED << "Invalid number of Arguments." << RESET << std::endl;
		return (1);
	}
	Harl jerk;
	
	jerk.complain(av[1]);
	return (0);
}