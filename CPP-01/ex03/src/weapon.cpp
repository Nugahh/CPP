/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwong <fwong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 19:08:48 by fwong             #+#    #+#             */
/*   Updated: 2023/06/28 17:41:00 by fwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Weapon.hpp"

Weapon::Weapon(std::string type) : _type(type) {}

Weapon::Weapon() : _type("") {}

Weapon::~Weapon() {}

std::string	&Weapon::getType() { return(_type); }

void	Weapon::setType(std::string type) { _type = type; }