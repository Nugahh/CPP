/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwong <fwong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 18:32:51 by fwong             #+#    #+#             */
/*   Updated: 2023/07/12 15:09:24 by fwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "Colors.hpp"
#include "ClapTrap.hpp"
#include <iostream>
#include <fstream>
#include <string>

class FragTrap : public ClapTrap {

	public:
		FragTrap();
		FragTrap(std::string _name);
		FragTrap(const FragTrap &copy);
		virtual ~FragTrap();

		FragTrap &operator=(const FragTrap &copy);

		virtual void	attack(const std::string &target);
		void			highFivesGuys();	
};

#endif