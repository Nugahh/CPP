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
#include "AMateria.hpp"

class ICharacter;
class AMateria;

class Character : public ICharacter {

	public:
		Character();
		Character(std::string const & name);
		Character(Character const &copy);
		~Character();

		Character &operator=(Character const &copy);
		std::string const &getName() const;

		void equip(AMateria *m);
		void unequip(int idx);
		void use(int idx, ICharacter &target);

		private:
			std::string _name;
			AMateria	*_inventory[4];
			AMateria 	**_trash;
			int			_trashSize;
			int			_inventorySize;
};

#endif