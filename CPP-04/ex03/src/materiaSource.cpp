/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   materiaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwong <fwong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 21:37:54 by fwong             #+#    #+#             */
/*   Updated: 2023/07/12 21:37:54 by fwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	for (int i = 0; i < 4; i++)
		this->_materia[i] = NULL;
	this->_materiaSize = 0;
}

MateriaSource::MateriaSource(MateriaSource const &copy) { *this = copy; }

MateriaSource::~MateriaSource() {
	for (int i = 0; i < 4; i++) {
		if (this->_materia[i] != NULL) {
			delete this->_materia[i];
		}
	}
	this->_materiaSize = 0;
}

MateriaSource &MateriaSource::operator=(MateriaSource const &rhs) {
	for (int i = 0; i < 4; i++) {
		if (this->_materia[i] != NULL) {
			delete this->_materia[i];
		}
		this->_materia[i] = rhs._materia[i]->clone();
	}
	this->_materiaSize = rhs._materiaSize;
	return (*this);
}

void MateriaSource::learnMateria(AMateria *materia) {
	for (int i = 0; i < 4; i++) {
		if (this->_materia[i] == NULL) {
			this->_materia[i] = materia;
			this->_materiaSize++;
			return ;
		}
	}
	delete materia;
}

AMateria* MateriaSource::createMateria(std::string const &type) {
	for (int i = 0; i < this->_materiaSize; i++) {
		if (this->_materia[i]->getType() == type && i < 4) {
			return (this->_materia[i]->clone());
		}
	}
	return (NULL);
}