/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-avel <mde-avel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 19:22:53 by mde-avel          #+#    #+#             */
/*   Updated: 2024/04/30 13:34:33 by mde-avel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(void)
{
    return ;
}

Contact::~Contact(void)
{
    return ;
}

void	Contact::Set_first_name(std::string first_n)   {this->_first_name = first_n;}
void	Contact::Set_last_name(std::string last_n)     {this->_last_name = last_n;}
void	Contact::Set_nickname(std::string nick_n)      {this->_nickname = nick_n;}
void	Contact::Set_phone_nbr(std::string phone_n)    {this->_phone_number = phone_n;}
void	Contact::Set_dark_secret(std::string d_secret) {this->_darkest_secret = d_secret;}

std::string	Contact::Get_first_name(void) const  {return this->_first_name;}
std::string	Contact::Get_last_name(void) const   {return this->_last_name;}
std::string	Contact::Get_nickname(void) const    {return this->_nickname;}
std::string	Contact::Get_phone_nbr(void) const   {return this->_phone_number;}
std::string	Contact::Get_dark_secret(void) const {return this->_darkest_secret;}

void	Contact::print_contact()
{
	std::cout << GREEN << "First name: " << RESET << Get_first_name() << std::endl;
	std::cout << GREEN << "Last name: " << RESET << Get_last_name() << std::endl;
	std::cout << GREEN << "Nickname: " << RESET << Get_nickname() << std::endl;
	std::cout << GREEN << "Phone number: " << RESET << Get_phone_nbr() << std::endl;
	std::cout << GREEN << "Darkest secret: " << RESET << Get_dark_secret() << std::endl;
}