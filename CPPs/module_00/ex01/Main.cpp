/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-avel <mde-avel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 16:39:49 by mde-avel          #+#    #+#             */
/*   Updated: 2024/04/30 13:12:10 by mde-avel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

void	intro(void)
{
	std::cout << CYAN << std::endl;
	std::cout << "┌─────────────────────────────────────────────┐" << std::endl;
	std::cout << "|                   PhoneBook                 |" << std::endl;
	std::cout << "├─────────────────────────────────────────────┤" << std::endl;
	std::cout << "|Your options are:                            |" << std::endl;
	std::cout << "|                                             |" << std::endl;
	std::cout << "|   ADD - to add a new contact.               |" << std::endl;
	std::cout << "|   SEARCH - to search your contact list.     |" << std::endl;
	std::cout << "|   EXIT - to exit the phonebook.             |" << std::endl;
	std::cout << "└─────────────────────────────────────────────┘" << std::endl;
	std::cout << RESET << std::endl;
}

int main(void)
{
	PhoneBook pb;
	std::string input;

	intro();
	while (1)
	{
		input.clear();
		std::cout << CYAN << "-> " << RESET;
		std::cin >> input;
		std::cin.clear();
		std::cin.ignore(256,'\n');
		if (std::cin.eof() || std::cin.fail())
			return (error_message("Erro! Please try again later.", RED));
		if (input == "ADD" || input == "add")
			pb.add();
		else if (input == "SEARCH" || input == "search")
			pb.search();	
		else if (input == "EXIT" || input == "exit")	
			break ;
		else
			error_message("Wrong option! Please use ADD, SEARCH or EXIT.", RED);
    }
}