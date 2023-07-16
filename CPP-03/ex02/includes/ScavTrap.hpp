/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwong <fwong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 18:32:51 by fwong             #+#    #+#             */
/*   Updated: 2023/07/12 15:01:59 by fwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"
#include "Colors.hpp"

class ScavTrap : public ClapTrap {

	public:
		ScavTrap();
		ScavTrap(std::string _name);
		ScavTrap(const ScavTrap &copy);
		~ScavTrap();

		ScavTrap &operator=(const ScavTrap &copy);

		void 			guardGate();
		void 			attack(const std::string &targent);
		
	private:
		bool _gateKeeper;
};

#endif