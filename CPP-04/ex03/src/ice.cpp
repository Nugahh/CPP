/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwong <fwong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 20:28:30 by fwong             #+#    #+#             */
/*   Updated: 2023/07/12 20:28:30 by fwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ice.hpp"

Ice::Ice()
	: AMateria("ice") {
		std::cout << "Ice default constructor called" << std::endl;
}

Ice::~Ice() {
	std::cout << "Ice destructor called" << std::endl;
}

AMateria *Ice::clone() const {
	return (new Ice(*this));
}
