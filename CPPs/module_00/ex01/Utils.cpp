/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-avel <mde-avel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 14:03:48 by mde-avel          #+#    #+#             */
/*   Updated: 2024/04/27 14:38:03 by mde-avel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int isnbr(std::string &str)
{
    int i = 0;
    
    while(str[i])
    {
        if(!isdigit(str[i]))
            return (0);
        i++;
    }
    return (1);
}

int check_nContact(std::string &str)
{
	if (str == "1")
		return (1);
	else if (str == "2")
		return (2);
	else if (str == "3")
		return (3);
	else if (str == "4")
		return (4);
	else if (str == "5")
		return (5);
	else if (str == "6")
		return (6);
	else if (str == "7")
		return (7);
	else if (str == "8")
		return (8);
	else
		return (0);
}

int error_message(std::string str, std::string color)
{
    std::cout << color << str << RESET << std::endl;
    return (-1);
}