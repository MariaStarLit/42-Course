/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-avel <mde-avel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 15:20:08 by mde-avel          #+#    #+#             */
/*   Updated: 2024/04/30 17:43:44 by mde-avel         ###   ########.fr       */
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
		std::string name;

	public:
		//Constructor
		Zombie(void); 
		Zombie(std::string zombie_name);
		//Destructor
		~Zombie(void);
		
		//Methoed
		void announce( void ); 
};

Zombie* newZombie( std::string name );
void randomChump( std::string name );

#endif