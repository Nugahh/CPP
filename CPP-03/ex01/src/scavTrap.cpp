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

#include "../includes/ScavTrap.hpp"

ScavTrap::ScavTrap()
	: ClapTrap() {
	
	this->_hitPoints = 100;
	this->_energy = 50;
	this->_attackDamage = 20;

	std::cout << "ScavTrap default constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string name)
	: ClapTrap(name) {

	this->_hitPoints = 100;
	this->_energy = 50;
	this->_attackDamage = 20;

	std::cout 	<< "ScavTrap " 
				<< this->_name
				<< " constructor called"
				<< std::endl;
}

ScavTrap::ScavTrap(ScavTrap const &copy)
	: ClapTrap(copy) {

	this->_hitPoints = copy._hitPoints;
	this->_energy = copy._energy;
	this->_attackDamage = copy._attackDamage;

	std::cout << "ScavTrap "
	          << copy._name
			  <<" copy constructor called"
			  << std::endl;
	*this = copy;
}

ScavTrap::~ScavTrap() {
	std::cout	<< "ScavTrap "
				<< this->_name
				<< " destructor called"
				<< std::endl;
}

ScavTrap &ScavTrap::operator=(ScavTrap const &rhs) {
	this->_name = rhs._name;
	this->_hitPoints = rhs._hitPoints;
	this->_energy = rhs._energy;
	this->_attackDamage = rhs._attackDamage;
	return *this;
}

void ScavTrap::guardGate() {
	if (this->_gateKeeper == false) {
		std::cout	<< "ScavTrap "
					<< this->_name
					<< " has enterred Gate keeper mode"
					<< std::endl;
		this->_gateKeeper = true;
	}
	else {
		std::cout	<< "ScavTrap "
					<< this->_name
					<< " has left Gate keeper mode"
					<< std::endl;
		this->_gateKeeper = false;
	}
}

void ScavTrap::attack(const std::string &target) {
	std::cout	<< "ScavTrap "
				<< this->_name
				<< " attacks "
				<< target
				<< ", causing "
				<< this->_attackDamage
				<< " points of damage!"
				<< std::endl;
}
