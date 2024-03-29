/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwong <fwong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 18:33:33 by fwong             #+#    #+#             */
/*   Updated: 2023/07/07 23:07:53 by fwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ScavTrap.hpp"

int main(void)
{
    ScavTrap John("John");
    ScavTrap Tom("Tom");
	
    John.attack("Tom");
    Tom.takeDamage(John.getAttackDamage());

    John.beRepaired(2);    
    
    Tom.attack("John");
    John.takeDamage(Tom.getAttackDamage());

    John.beRepaired(5);
 
    Tom.guardGate();
    Tom.guardGate();
    return 0;
}