/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-avel <mde-avel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 18:34:07 by mde-avel          #+#    #+#             */
/*   Updated: 2024/05/02 20:12:38 by mde-avel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>

// Colors

# define RESET "\033[0m"
# define RED "\033[0;31m"
# define GREEN "\033[0;32m"
# define YELLOW "\033[0;33m"
# define BLUE "\033[0;34m"
# define PURPLE "\033[0;35m"
# define CYAN "\033[0;36m"

class Zombie
{
	private:
		std::string _zombie_name;

	public:
		Zombie(void); 
		Zombie(std::string new_name);
		~Zombie(void);

		//Methoed
		void	announce(void);
		void	setName(std::string z_name);
};

Zombie *zombieHorde(int N, std::string name);
int		getIsHorde(void);

#endif