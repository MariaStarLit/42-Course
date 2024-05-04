/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-avel <mde-avel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 19:12:34 by mde-avel          #+#    #+#             */
/*   Updated: 2024/04/30 14:02:45 by mde-avel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#include <iostream>
#include <iomanip>
#include <string>

class PhoneBook
{
	private:
		Contact _contact[9];
		int		_index;
		int		_flag;
		
	public:
		PhoneBook(void); //Constructor
		~PhoneBook(void); //Destructor
		
		//Methods
		int		add(void);
		int		search(void);
		void	print_table(void);
};

void	put_column(std::string str);
int		isnbr(std::string &str);
int 	check_nContact(std::string &str);
int 	error_message(std::string str, std::string color);

#endif