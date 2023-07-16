/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwong <fwong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 21:35:00 by fwong             #+#    #+#             */
/*   Updated: 2023/07/12 21:35:00 by fwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource {
	
	public:
		MateriaSource();
		MateriaSource(const MateriaSource &copy);
		~MateriaSource();

		MateriaSource &operator=(const MateriaSource &copy);

		void 		learnMateria(AMateria*);
		AMateria* 	createMateria(std::string const & type);

	private:
		AMateria *_materia[4];
};

#endif