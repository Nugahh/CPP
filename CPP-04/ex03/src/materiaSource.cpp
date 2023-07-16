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

#include "../includes/materiaSource.hpp"

MateriaSource::MateriaSource() {}

MateriaSource::MateriaSource(MateriaSource const &copy) { *this = copy; }

MateriaSource::~MateriaSource() {}

MateriaSource &MateriaSource::operator=(MateriaSource const &rhs) {
	this->_materia = rhs._materia;
	return (*this);
}

void MateriaSource::learnMateria(AMateria *materia) {
	for (int i = 0; i < 4; i++) {
		if (this->_materia[i] == NULL) {
			this->_materia[i] = materia;
			return ;
		}
	}
	delete materia;
}

AMateria *MateriaSource::createMateria(std::string const &type) {
	for (int i = 0; i < 4; i++) {
		if (this->_materia[i] != NULL && this->_materia[i]->getType() == type) {
			return (this->_materia[i]->clone());
		}
	}
	return (NULL);
}