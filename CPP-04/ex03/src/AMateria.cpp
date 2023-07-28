/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwong <fwong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 13:23:19 by fwong             #+#    #+#             */
/*   Updated: 2023/07/24 13:23:19 by fwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/AMateria.hpp"

AMateria::AMateria() {}

AMateria::AMateria(std::string const &type) : _type(type) {}

AMateria::AMateria(AMateria const &copy) {
	*this = copy;
}

AMateria::~AMateria() {}

AMateria &AMateria::operator=(AMateria const &rhs) {
	this->_type = rhs._type;
	return (*this);
}

std::string	const&AMateria::getType() const {
	return this->_type;
}

void AMateria::use(ICharacter &target) {
	(void)target;
}