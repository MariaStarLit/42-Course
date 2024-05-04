/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-avel <mde-avel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 19:04:13 by mde-avel          #+#    #+#             */
/*   Updated: 2024/04/30 13:34:51 by mde-avel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void)
{
	_index = 1;
	_flag = 0;
}

PhoneBook::~PhoneBook(void)
{
    std::cout << GREEN << "Thank you for choosing our service!" << RESET << std::endl;
}

int    PhoneBook::add()
{
	std::string answer;
	std::string first_n;
	std::string last_n;
	std::string nick_n;
	std::string phone_n;
	std::string d_secret;
	
	if (_index > 8)
	{
		_flag = 1;
		_index = 1;
	}
	if (_flag == 1)
		std::cout << YELLOW << "Your Phonebook is full! The oldest contact will be lost!" << RESET << std::endl;
	if (_index >= 1 && _index <= 8)
	{
		std::cout << CYAN << "First name: " << RESET;
		std::cin >> first_n;
		std::cin.clear();
		std::cin.ignore(256,'\n');
		if (std::cin.eof() || std::cin.fail())
			return (error_message("Erro! Please try again later.", RED));
		if (first_n == "EXIT" || first_n == "exit")
			return (error_message("You left ADD.", YELLOW));

		std::cout << CYAN << "Last name: " << RESET;
		std::cin >> last_n;
		std::cin.clear();
		std::cin.ignore(256,'\n');
		if (std::cin.eof() || std::cin.fail())
			return (error_message("Erro! Please try again later.", RED));

		std::cout << CYAN << "Nickname: " << RESET;
		std::cin >> nick_n;
		std::cin.clear();
		std::cin.ignore(256,'\n');
		if (std::cin.eof() || std::cin.fail())
			return (error_message("Erro! Please try again later.", RED));

		std::cout << CYAN << "Phone number: " << RESET;
		std::cin >> phone_n;
		std::cin.clear();
		std::cin.ignore(256,'\n');
		if (std::cin.eof() || std::cin.fail())
			return (error_message("Erro! Please try again later.", RED));

		std::cout << CYAN << "Darkest secret: " << RESET;
		getline(std::cin >> std::ws, d_secret);
		std::cin.clear();
		std::cin.ignore(256,'\n');
		if (std::cin.eof() || std::cin.fail())
			return (error_message("Erro! Please try again later.", RED));
	}
	this->_contact[_index].Set_first_name(first_n);
	this->_contact[_index].Set_last_name(last_n);	
	this->_contact[_index].Set_nickname(nick_n);
	this->_contact[_index].Set_phone_nbr(phone_n);
	this->_contact[_index].Set_dark_secret(d_secret);
	_index++;
	std::cout << GREEN << "Contact add to PhoneBook!" << RESET << std::endl;
	return (1);
}

void	put_column(std::string str)
{
	std::string to_print = str;
	
	if (str.size() > 10)
		to_print = str.substr(0, 9) + ".";
	std::cout << std::right << std::setw(10) << to_print;
	std::cout << "│";
}

void	PhoneBook::print_table(void)
{
	
	std::cout << CYAN << std::endl;
	std::cout << "┌──────────┬──────────┬──────────┬──────────┐" << std::endl;
	std::cout << "|     Index|First Name| Last Name|  Nickname|" << std::endl;
	std::cout << "├──────────┼──────────┼──────────┼──────────┤" << std::endl;
	for (int n = 1; n <= 8; n++)
	{
		std::cout << "|         " << n << "|";
		put_column(_contact[n].Get_first_name());
		put_column(_contact[n].Get_last_name());
		put_column(_contact[n].Get_nickname());
		std::cout << std::endl;
		if (n < 8)
		{
			if(_contact[n + 1].Get_first_name() == "")
				break;
			std::cout << "├──────────┼──────────┼──────────┼──────────┤" << std::endl;
		}	
	}
	std::cout << "└──────────┴──────────┴──────────┴──────────┘" << std::endl;
	std::cout << RESET << std::endl;
}

int    PhoneBook::search(void)
{
	std::string n_contact;

	print_table();
	std::cout << CYAN << "Sellect a contact: " << RESET;
	while (1)
	{
		std::cin >> n_contact;
		std::cin.clear();
		std::cin.ignore(256,'\n');
		if (std::cin.eof() || std::cin.fail())
			return (error_message("Erro! Please try again later.", RED));
		if (n_contact == "EXIT" || n_contact == "exit")
			return (error_message("You left SEARCH.", YELLOW));
		if (!isnbr(n_contact))
			std::cout << RED << "Please insert a number: " << RESET;
		else
		{
			int n = check_nContact(n_contact);
			if (n == 0)
				return (error_message("There's no such contact in the PhoneBook.", RED));
			else
			{
				if(_contact[n].Get_first_name() == "")
					return (error_message("That Contact is not set yet.", YELLOW));
				else
				{
					_contact[n].print_contact();
					break ;
				}
			}
		}
	}
	return (1);
}