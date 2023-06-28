/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   humanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwong <fwong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 19:08:46 by fwong             #+#    #+#             */
/*   Updated: 2023/06/28 02:32:47 by fwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Weapon.hpp"
#include "../includes/HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon)
	: _weapon(weapon)
	, _name(name) {}

HumanA::~HumanA() {}

void    HumanA::attack() {
	std::cout	<< _name << " attacks with their "
				<< _weapon.getType()
				<< std::endl;
}
