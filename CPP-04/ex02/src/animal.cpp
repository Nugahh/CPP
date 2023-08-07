/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwong <fwong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 15:33:48 by fwong             #+#    #+#             */
/*   Updated: 2023/07/12 15:33:48 by fwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/AAnimal.hpp"

AAnimal::AAnimal() : _type("Animal") {
	std::cout << "Animal Default Constructor called" << std::endl;
}

AAnimal::AAnimal(const AAnimal &copy) {
	std::cout << "Animal Copy Constructor called" << std::endl;
	*this = copy;
}

AAnimal::~AAnimal() {
	std::cout << "Animal Destructor called" << std::endl;
}

AAnimal &AAnimal::operator=(const AAnimal &copy) {
	std::cout << "Animal Assignation Operator called" << std::endl;
	this->_type = copy._type;
	return (*this);
}

std::string	AAnimal::getType() const {
	return (this->_type);
}

void	AAnimal::makeSound() const {
	std::cout << "Animal makeSound called" << std::endl;
}