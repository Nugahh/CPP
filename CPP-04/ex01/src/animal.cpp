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

#include "../includes/animal.hpp"

Animal::Animal() : _type("Animal") {
	std::cout << "Animal Default Constructor called" << std::endl;
}

Animal::Animal(const Animal &copy) {
	std::cout << "Animal Copy Constructor called" << std::endl;
	*this = copy;
}

Animal::~Animal() {
	std::cout << "Animal Destructor called" << std::endl;
}

Animal &Animal::operator=(const Animal &copy) {
	std::cout << "Animal Assignation Operator called" << std::endl;
	this->_type = copy._type;
	return (*this);
}

std::string	Animal::getType() const {
	return (this->_type);
}

void	Animal::makeSound() const {
	std::cout << "Animal makeSound called" << std::endl;
}