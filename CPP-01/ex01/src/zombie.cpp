/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwong <fwong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 21:10:30 by fwong             #+#    #+#             */
/*   Updated: 2023/06/26 21:38:06 by fwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Zombie.hpp"

Zombie::Zombie(); {}

Zombie::Zombie(std::string name) : _name(name) {}

Zombie::~Zombie() {
	
	std::cout << RED << "Zombie " << _name << " has been destroyed." << RESET << std::endl;
}

Zombie* newZombie(std::string name){

	return new Zombie(name);
}

void Zombie::announce() {
	
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}