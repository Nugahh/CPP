/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwong <fwong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 21:25:48 by fwong             #+#    #+#             */
/*   Updated: 2023/07/12 21:25:48 by fwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <iostream>
#include <string>

#include "ICharacter.hpp"
class ICharacter;
#include "AMateria.hpp"
class AMateria;


class Character : public ICharacter {

	public:
		Character();
		Character(std::string const & name);
		Character(Character const &copy);
		~Character();

		Character &operator=(Character const &copy);
		std::string const &getName() const;

		virtual void equip(AMateria *m);
		virtual void unequip(int idx);
		virtual void use(int idx, ICharacter &target);
		void 		 deleteTrash();

		private:
			std::string _name;
			AMateria	*_inventory[4];
			AMateria 	*_trash;
			int			_inventorySize;
};

#endif