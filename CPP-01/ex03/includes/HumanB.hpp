/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwong <fwong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 19:08:58 by fwong             #+#    #+#             */
/*   Updated: 2023/06/28 18:13:41 by fwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"
#include <iostream>

class HumanB {
	
	public:
		HumanB(std::string name);
		~HumanB();

		void setWeapon(Weapon& weapon);
		void attack();
			
	private:
		Weapon 		*_weapon;
		std::string _name;
};

#endif