/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwong <fwong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 18:32:51 by fwong             #+#    #+#             */
/*   Updated: 2023/07/05 02:29:01 by fwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include "Colors.hpp"
#include <iostream>
#include <fstream>
#include <string>

class ClapTrap {
	
	public:
		ClapTrap();
		ClapTrap(std::string _name);
		ClapTrap(const ClapTrap &copy);
		~ClapTrap();

		ClapTrap &operator=(const ClapTrap &copy);
		
		void attack(const std::string &target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);

	private:
		std::string	_name;
		unsigned int 		_hitPoints;
		unsigned int 		_energy;
		unsigned int		_attackDamage;
		
};

#endif