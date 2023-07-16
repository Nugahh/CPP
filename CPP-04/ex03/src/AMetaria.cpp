/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   metaria.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwong <fwong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 20:28:30 by fwong             #+#    #+#             */
/*   Updated: 2023/07/12 20:28:30 by fwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/metaria.hpp"

AMetaria::AMetaria() {}

AMetaria::AMetaria(std::string const &type) : _type(type) {}

AMetaria::AMetaria(AMetaria const &copy) {
	*this = copy;
}

AMetaria::~AMetaria() {}

AMetaria &AMetaria::operator=(AMetaria const &rhs) {
	this->_type = rhs._type;
	return (*this);
}

std::string	&AMetaria::getType() const {
	return this->_type;
}

AMetaria *AMetaria::clone() const {
	return (new AMetaria(*this));
}

void AMetaria::use(ICharacter &target) {
	(void)target;
}