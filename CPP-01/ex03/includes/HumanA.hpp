/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwong <fwong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 19:08:59 by fwong             #+#    #+#             */
/*   Updated: 2023/06/28 02:32:04 by fwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
#define HUMANA_HPP

#include "Weapon.hpp"
#include <iostream>

class HumanA {

	public:
		HumanA(std::string name, Weapon& weapon);
		~HumanA();
		
		void attack();
		
	private:
		Weapon 		_weapon;
		std::string _name;
};

#endif