/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwong <fwong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 18:33:39 by fwong             #+#    #+#             */
/*   Updated: 2023/07/05 15:59:11 by fwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/FragTrap.hpp"

FragTrap::FragTrap()
	: ClapTrap() {
	
	this->_hitPoints = 100;
	this->_energy = 100;
	this->_attackDamage = 30;

	std::cout << "FragTrap default constructor called" << std::endl;
}

FragTrap::FragTrap(std::string name)
	: ClapTrap(name) {

	this->_hitPoints = 100;
	this->_energy = 100;
	this->_attackDamage = 30;

	std::cout 	<< "FragTrap " 
				<< this->_name
				<< " constructor called"
				<< std::endl;
}

FragTrap::FragTrap(FragTrap const &copy)
	: ClapTrap(copy) {

	this->_hitPoints = copy._hitPoints;
	this->_energy = copy._energy;
	this->_attackDamage = copy._attackDamage;

	std::cout << "FragTrap "
	          << copy._name
			  <<" copy constructor called"
			  << std::endl;
	*this = copy;
}

FragTrap::~FragTrap() {
	std::cout	<< "FragTrap "
				<< this->_name
				<< " destructor called"
				<< std::endl;
}

FragTrap &FragTrap::operator=(FragTrap const &rhs) {
	this->_name = rhs._name;
	this->_hitPoints = rhs._hitPoints;
	this->_energy = rhs._energy;
	this->_attackDamage = rhs._attackDamage;
	return *this;
}

void FragTrap::highFivesGuys() {
	std::cout	<< "FragTrap "
				<< this->_name
				<< " wants to high five"
				<< std::endl;
}
void FragTrap::attack(const std::string &target) {
	std::cout	<< "FragTrap "
				<< this->_name
				<< " attacks "
				<< target
				<< ", causing "
				<< this->_attackDamage
				<< " points of damage!"
				<< std::endl;
}
