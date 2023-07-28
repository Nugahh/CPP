/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwong <fwong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 21:29:08 by fwong             #+#    #+#             */
/*   Updated: 2023/07/12 21:29:08 by fwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/character.hpp"

Character::Character()
	: _name("character")
	, _trash(NULL)
	, _trashSize(0)
	, _inventorySize(0) {
	for (int i = 0; i < 4; i++) {
		this->_inventory[i] = NULL;
	}
}

Character::Character(std::string const &name)
	: _name(name)
	, _trash(NULL)
	, _trashSize(0)
	, _inventorySize(0) {
	for (int i = 0; i < 4; i++) {
		this->_inventory[i] = NULL;
	}
}

Character::Character(Character const &copy) {
	*this = copy;
}

Character::~Character() {
	for (int i = 0; i < 4; i++)
		if (this->_inventory[i]) 
			delete this->_inventory[i];
	if (this->_trash) {
		for (int i = 0; this->_trash[i]; i++)
			delete this->_trash[i];
		delete[] this->_trash;
	}
}

Character &Character::operator=(Character const &rhs) {
	for (int i = 0; i < 4; i++) {
		if (this->_inventory[i] != NULL) {
			delete this->_inventory[i];
		}
		this->_inventory[i] = rhs._inventory[i]->clone();
	}
	this->_name = rhs._name;
	this->_trashSize = rhs._trashSize;
	this->_inventorySize = rhs._inventorySize;
	return (*this);
}

std::string const &Character::getName() const {
	return this->_name;
}

void Character::equip(AMateria *m) {
	if (!m)
		return ;
	if (this->_inventorySize == 4)
		return ;
	this->_inventory[this->_inventorySize] = m;
	this->_inventorySize++;
}

void Character::unequip(int idx) {
	if (idx < 0 || idx > 3)
		return ;
	if (this->_inventory[idx] == NULL)
		return ;
	this->_trash[this->_trashSize] = this->_inventory[idx];
	this->_trashSize++;
	this->_inventory[idx] = NULL;
}

void	Character::use(int idx, ICharacter &target) {
	if (idx < 0 || idx > 3)
		return ;
	if (this->_inventory[idx] == NULL)
		return ;
	this->_inventory[idx]->use(target);
}