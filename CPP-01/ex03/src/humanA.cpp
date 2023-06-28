/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   humanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwong <fwong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 17:29:55 by fwong             #+#    #+#             */
/*   Updated: 2023/06/28 17:29:57 by fwong            ###   ########.fr       */
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
