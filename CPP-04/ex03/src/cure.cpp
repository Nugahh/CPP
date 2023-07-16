/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwong <fwong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 20:28:29 by fwong             #+#    #+#             */
/*   Updated: 2023/07/12 20:28:29 by fwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cure.hpp"

Cure::Cure()
	: AMateria("cure") {
		std::cout << "Cure default constructor called" << std::endl;
}

Cure::~Cure() {
	std::cout << "Cure destructor called" << std::endl;
}

AMateria *Cure::clone() const {
	return (new Cure(*this));
}