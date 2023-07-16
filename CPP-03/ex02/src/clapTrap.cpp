/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwong <fwong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 18:33:39 by fwong             #+#    #+#             */
/*   Updated: 2023/07/12 15:58:04 by fwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ClapTrap.hpp"

ClapTrap::ClapTrap()
	: _name("ClapTrap")
	, _hitPoints(10)
	, _energy(10)
	, _attackDamage(0) {
	std::cout << "ClapTrap default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name)
	: _name(name)
	, _hitPoints(10)
	, _energy(10)
	, _attackDamage(0) {
	std::cout 	<< "ClapTrap " 
				<< this->_name
				<< " constructor called"
				<< std::endl;
}

ClapTrap::ClapTrap(ClapTrap const &copy) {
	std::cout << "ClapTrap "
	          << copy._name
			  <<" copy constructor called"
			  << std::endl;
	*this = copy;
}

ClapTrap::~ClapTrap() {
	std::cout	<< "ClapTrap "
				<< this->_name
				<< " destructor called"
				<< std::endl;
}

ClapTrap &ClapTrap::operator=(ClapTrap const &rhs) {
	this->_name = rhs._name;
	this->_hitPoints = rhs._hitPoints;
	this->_energy = rhs._energy;
	this->_attackDamage = rhs._attackDamage;
	return (*this);
}

void ClapTrap::setAttackDamage(unsigned int attackDamage) {
	this->_attackDamage = attackDamage;
}

unsigned int ClapTrap::getAttackDamage() const {
	return (this->_attackDamage);
}

void ClapTrap::attack(const std::string &target) {
	
	if (this->_energy <= 0) {
		std::cout	<< "ClapTrap " 
					<< this->_name
					<< YEL
					<< " is out of energy!"
					<< RESET
					<< std::endl;
		return ;
	} else if (this->_hitPoints <= 0) {
		std::cout	<< "ClapTrap " 
					<< this->_name
					<< RED
					<< "is dead and can't attack!"
					<< RESET
					<< std::endl;
		return ;
	} else {
		std::cout	<< this->_name
					<< RED
					<< " attacks "
					<< RESET
					<< target
					<< ", causing "
					<< RED
					<< this->_attackDamage
					<< " points of damage! "
					<< RESET;
		this->_energy--;
		std::cout	<< "ClapTrap " 
					<< this->_name
					<< " has "
					<< YEL
					<< this->_energy
					<< " energy left!"
					<< RESET
					<< std::endl;
	}
}

void ClapTrap::takeDamage(unsigned int amount) {
	if (amount >= this->_hitPoints) {
		std::cout	<< this->_name
					<< " takes "
					<< RED
					<< this->_hitPoints
					<< " points of damage and dies!"
					<< RESET
					<< std::endl;
		this->_hitPoints = 0;
	} else {
		this->_hitPoints -= amount;
		std::cout	<< this->_name
					<< " takes "
					<< amount
					<< RED
					<< " points of damage! "
					<< RESET
					<< GRN
					<< this->_hitPoints
					<< " HP left!"
					<< RESET
					<< std::endl;
	}
}

void ClapTrap::beRepaired(unsigned int amount) {

	if (this->_hitPoints <= 0) {
		std::cout	<< "ClapTrap " 
					<< this->_name
					<< RED
					<< " is dead and can't be repaired!"
					<< RESET
					<< std::endl;
	} else if (this->_energy <= 0) {
		std::cout	<< "ClapTrap " 
					<< this->_name
					<< YEL
					<< " is out of energy and can't be repaired!"
					<< RESET
					<< std::endl;
	} else {
		this->_hitPoints += amount;
		this->_energy--;
		std::cout	<< this->_name
					<< " is "
					<< GRN
					<< "repaired"
					<< RESET
					<< " for "
					<< GRN
					<< amount
					<< " HP! "
					<< RESET
					<< GRN
					<< this->_hitPoints
					<< " HP left! "
					<< RESET
					<< YEL
					<< this->_energy
					<< " energy left!"
					<< RESET
					<< std::endl;
	}
}
