/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-avel <mde-avel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 22:49:51 by mde-avel          #+#    #+#             */
/*   Updated: 2024/05/02 01:20:59 by mde-avel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(void)
{
	Harl jerk;

	jerk.complain("DEBUG");
	jerk.complain("INFO");
	jerk.complain("WARNING");
	jerk.complain("ERROR");
	jerk.complain("FATAL");
	std::cout << std::endl;

	return (0);
}