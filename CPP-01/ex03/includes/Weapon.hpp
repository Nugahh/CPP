/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwong <fwong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 18:31:41 by fwong             #+#    #+#             */
/*   Updated: 2023/06/28 02:25:42 by fwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
#define WEAPON_HPP

#include "Colors.hpp"
// #include "HumanA.hpp"
// #include "HumanB.hpp"e
#include <iostream>
#include <string>
#include <cstring>
#include <cctype>


class Weapon {

	public:
		Weapon();
		Weapon(std::string type);
		~Weapon();

		std::string &getType();
		void setType(std::string type);
		
	private:
		std::string _type;
};

#endif