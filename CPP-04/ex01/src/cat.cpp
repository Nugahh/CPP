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
	this->_brain = new Brain();
	this->_type = "Cat";
}

Cat::Cat(Cat const &copy)
	: Animal(copy) {
	std::cout << "Cat copy constructor called" << std::endl;
	*this = copy;
}

Cat::~Cat() {
	delete this->_brain;
	std::cout << "Cat destructor called" << std::endl;
}

Cat &Cat::operator=(Cat const &rhs) {
	this->_type = rhs._type;
	this->_brain = new Brain;
	*this->_brain = *rhs._brain;
	return (*this);
}


void Cat::makeSound() const {
	std::cout << "Meow Meow" << std::endl;
}

std::string Cat::getIdea(int i) const {
	return this->_brain->getIdea(i);
}

std::string Cat::setIdea(std::string idea, int i) {
	return this->_brain->setIdea(idea, i);
}

