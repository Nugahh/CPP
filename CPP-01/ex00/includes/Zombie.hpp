/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwong <fwong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 19:54:23 by fwong             #+#    #+#             */
/*   Updated: 2023/06/26 20:59:29 by fwong            ###   ########.fr       */
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
		Zombie(std::string name);
		~Zombie();
		
		void announce(void);
	
	private:
		std::string _name;
};

Zombie* newZombie(std::string name);
void randomChump(std::string name);
		
#endif