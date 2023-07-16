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

#include "../includes/cat.hpp"

Cat::Cat()
	: AAnimal() {
	std::cout << "Cat default constructor called" << std::endl;
	this->_brain = new Brain();
	this->_type = "Cat";
}

Cat::Cat(Cat const &copy)
	: AAnimal(copy) {
	std::cout << "Cat copy constructor called" << std::endl;
	*this = copy;
}

Cat::~Cat() {
	delete this->_brain;
	std::cout << "Cat destructor called" << std::endl;
}

Cat &Cat::operator=(Cat const &rhs) {
	this->_type = rhs._type;
	return (*this);
}

void Cat::makeSound() const {
	std::cout << "Meow Meow" << std::endl;
}


