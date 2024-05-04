/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-avel <mde-avel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 19:23:05 by mde-avel          #+#    #+#             */
/*   Updated: 2024/04/30 13:18:23 by mde-avel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>

// Colors

# define RESET "\033[0m"
# define RED "\033[0;31m"
# define GREEN "\033[0;32m"
# define YELLOW "\033[0;33m"
# define BLUE "\033[0;34m"
# define PURPLE "\033[0;35m"
# define CYAN "\033[0;36m"

class Contact
{
	private:
		std::string		_first_name;
		std::string		_last_name;
		std::string		_nickname;
		std::string		_phone_number;
		std::string		_darkest_secret;
	public:
		Contact(void); //Constructor
		~Contact(void); //Destructor
		
		//Methods
		void		Set_first_name(std::string first_n);
		void		Set_last_name(std::string last_n);
		void		Set_nickname(std::string nick_n);
		void		Set_phone_nbr(std::string phone_n);
		void		Set_dark_secret(std::string d_secret);
		
		std::string	Get_first_name(void) const;
		std::string	Get_last_name(void) const;
		std::string	Get_nickname(void) const;
		std::string	Get_phone_nbr(void) const;
		std::string	Get_dark_secret(void) const;

		void		print_contact(void);
};

#endif