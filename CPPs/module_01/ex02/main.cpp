/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-avel <mde-avel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 02:02:54 by mde-avel          #+#    #+#             */
/*   Updated: 2024/05/01 17:08:43 by mde-avel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

# define RESET "\033[0m"
# define BLUE "\033[0;34m"
# define CYAN "\033[0;36m"

int	main(void)
{
	std::string variable = "HI THIS IS BRAIN";
	std::string *stringPTR = &variable;
	std::string &stringREF = variable;

	std::cout << CYAN << "The memory address of the string variable: " << RESET << &variable << std::endl;
	std::cout << CYAN << "The memory address held by stringPTR:      " << RESET << stringPTR << std::endl;
	std::cout << CYAN << "The memory address held by stringREF:      " << RESET << &stringREF << std::endl;
	std::cout << std::endl;
	std::cout << BLUE << "The value of the string variable:  " << RESET << variable << std::endl;
	std::cout << BLUE << "The value pointed to by stringPTR: " << RESET << *stringPTR << std::endl;
	std::cout << BLUE << "The value pointed to by stringREF: " << RESET << stringREF << std::endl;
	return (0);
}