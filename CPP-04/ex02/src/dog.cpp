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

#include "../includes/Dog.hpp"

Dog::Dog()
	: AAnimal() {
	std::cout << "Dog default constructor called" << std::endl;
	this->_brain = new Brain();
	this->_type = "Dog";
}

Dog::Dog(Dog const &copy)
	: AAnimal(copy) {
	std::cout << "Dog copy constructor called" << std::endl;
	*this = copy;
}

Dog::~Dog() {
	delete this->_brain;
	std::cout << "Dog destructor called" << std::endl;
}

Dog &Dog::operator=(Dog const &rhs) {
	this->_type = rhs._type;
	this->_brain = new Brain;
	*this->_brain = *rhs._brain;
	return (*this);
}

void Dog::makeSound() const {
	std::cout << "Woof Woof" << std::endl;
}

std::string Dog::getIdea(int i) const {
	return this->_brain->getIdea(i);
}

std::string Dog::setIdea(std::string idea, int i) {
	return this->_brain->setIdea(idea, i);
}
