/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwong <fwong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 21:10:38 by fwong             #+#    #+#             */
/*   Updated: 2023/06/27 17:40:53 by fwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include "Colors.hpp"
#include <iostream>
#include <string>
#include <cstring>
#include <cctype>

class Zombie {
	
	public:
		Zombie();
		Zombie(std::string name);
		~Zombie();
		
		void setName(std::string name);
		
		void announce(void);
	
	private:
		std::string _name;
};

Zombie* newZombie(std::string name);
Zombie* zombieHorde(int N, std::string name);
		
#endif