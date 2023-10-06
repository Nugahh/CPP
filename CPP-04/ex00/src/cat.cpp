/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwong <fwong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 15:33:52 by fwong             #+#    #+#             */
/*   Updated: 2023/07/12 15:33:52 by fwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat()
	: Animal() {
	std::cout << "Cat default constructor called" << std::endl;
	this->_type = "Cat";
}

Cat::Cat(Cat const &copy)
	: Animal(copy) {
	std::cout << "Cat copy constructor called" << std::endl;
	*this = copy;
}

Cat::~Cat() {
	std::cout << "Cat destructor called" << std::endl;
}

Cat &Cat::operator=(Cat const &rhs) {
	this->_type = rhs._type;
	return (*this);
}

void Cat::makeSound() const {
	std::cout << "Meow Meow" << std::endl;
}


