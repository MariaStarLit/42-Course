/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-avel <mde-avel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 20:19:58 by mde-avel          #+#    #+#             */
/*   Updated: 2024/05/03 18:46:07 by mde-avel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Loser.hpp"

void	replace(std::string s1, std::string s2, std::ifstream *in_file, std::ofstream *out_file)
{
	std::string		line;
	size_t			pos = 0;

	while(std::getline(*in_file, line))
	{
		pos = line.find(s1, 0);
		while (pos != std::string::npos)
		{
			*out_file << line.substr(0, pos);
			*out_file << s2;
			line = line.substr(pos + s1.length());
			pos = line.find(s1, 0);
		}
		*out_file << line;
		if (!in_file->eof())
			*out_file << std::endl;
	}
}


int main(int ac, char **av)
{
	if (ac != 4)
	{
		std::cout << RED << "Invalid number of arguments."  << RESET << std::endl;
		return (3);
	}
	std::string		s1 = av[2];
	std::string		s2 = av[3];
	if(s1.empty() || s2.empty())
	{
		std::cout << RED << "Error! Empty arguments."  << RESET << std::endl;
		return (2);
	}
	std::ifstream	in_file(av[1]);
	if(!in_file.is_open())
	{
		std::cout << RED << "Error! Openning file."  << RESET << std::endl;
		return (1);
	}
	std::string		file = av[1] + std::string(".replace");
	std::ofstream	out_file(file.c_str());
	if(!out_file.is_open()){
		std::cout << RED << "Error! Openning file."  << RESET << std::endl;
		return (1);
	}
	
	replace(s1, s2, &in_file, &out_file);

	out_file.close();
	in_file.close();
	return(0);
}