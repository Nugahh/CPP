/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwong <fwong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 15:33:51 by fwong             #+#    #+#             */
/*   Updated: 2023/07/12 15:33:51 by fwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/dog.hpp"

Dog::Dog()
	: Animal() {
	std::cout << "Dog default constructor called" << std::endl;
	this->_type = "Dog";
}

Dog::Dog(Dog const &copy)
	: Animal(copy) {
	std::cout << "Dog copy constructor called" << std::endl;
	*this = copy;
}

Dog::~Dog() {
	std::cout << "Dog destructor called" << std::endl;
}

Dog &Dog::operator=(Dog const &rhs) {
	this->_type = rhs._type;
	return (*this);
}

void Dog::makeSound() const {
	std::cout << "Woof Woof" << std::endl;
}
