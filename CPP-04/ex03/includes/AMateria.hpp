/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwong <fwong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 20:16:49 by fwong             #+#    #+#             */
/*   Updated: 2023/07/12 20:16:49 by fwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <iostream>
#include <string>
#include "ICharacter.hpp"

class AMateria
{
	public:
		AMateria();
		AMateria(std::string const &type);
		AMateria(const AMateria &copy);
		virtual ~AMateria();

		AMateria &operator=(const AMateria &copy);

		std::string const	&getType() const; //Returns the materia type

		virtual AMateria	*clone() const = 0;
		virtual void 		use(ICharacter& target);

	protected:
		std::string _type;
}

#endif