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

#include "../includes/Character.hpp"

Character::Character()
	: _name("character")
	, _trash(NULL)
	, _inventorySize(0) {
	for (int i = 0; i < 4; i++) {
		this->_inventory[i] = NULL;
	}
}

Character::Character(std::string const &name)
	: _name(name)
	, _trash(NULL)
	, _inventorySize(0) {
	for (int i = 0; i < 4; i++) {
		this->_inventory[i] = NULL;
	}
}

Character::Character(Character const &copy) {
	// *this = copy;
	this->_inventorySize = 0;
	for (int i = 0; i < 4; i++)
		this->_inventory[i] = NULL;
	for (int i = 0; i < 4; i++)
		if (copy._inventory[i])
			this->equip(copy._inventory[i]->clone());
	this->_name = copy._name;
	this->_inventorySize = copy._inventorySize;
	this->_trash = copy._trash;
}

Character::~Character() {
	for (int i = 0; i < 4; i++)
		if (this->_inventory[i]) 
			delete this->_inventory[i];
}

Character &Character::operator=(Character const &rhs) {
	for (int i = 0; i < 4; i++) {
			delete this->_inventory[i];
			this->_inventory[i] = NULL;
			if (rhs._inventory[i])
				this->equip(rhs._inventory[i]->clone());
	}
	this->_name = rhs._name;
	this->_inventorySize = rhs._inventorySize;
	this->_trash = rhs._trash;
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
	this->_trash = this->_inventory[idx];
	this->_inventory[idx] = NULL;
}

void	Character::use(int idx, ICharacter &target) {
	if (idx < 0 || idx > 3)
		return ;
	if (this->_inventory[idx] == NULL)
		return ;
	this->_inventory[idx]->use(target);
}

void	Character::deleteTrash()
{
	if (this->_trash)
	{
		delete this->_trash;
		this->_trash = NULL;
	}
}