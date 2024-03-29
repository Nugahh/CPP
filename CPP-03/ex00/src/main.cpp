/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwong <fwong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 18:33:33 by fwong             #+#    #+#             */
/*   Updated: 2023/07/05 15:59:40 by fwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ClapTrap.hpp"

int main() {

	ClapTrap nour("Nour");
	ClapTrap kelly("Kelly");
	nour.setAttackDamage(2);
	kelly.setAttackDamage(10);
	
	std::cout << std::endl;
	
	nour.attack("Kelly");
	kelly.takeDamage(2);
	kelly.beRepaired(2);

	kelly.attack("Nour");
	nour.takeDamage(10);
	nour.beRepaired(10);
	
	std::cout << std::endl;
	
	return 0;
}