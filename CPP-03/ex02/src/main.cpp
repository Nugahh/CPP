/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwong <fwong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 18:33:33 by fwong             #+#    #+#             */
/*   Updated: 2023/07/12 15:05:57 by fwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/FragTrap.hpp"

int main(void)
{
    FragTrap John("John");
    FragTrap Tom("Tom");
	
    John.attack("Tom");
    Tom.takeDamage(John.getAttackDamage());

    John.beRepaired(2);    
    
    Tom.attack("John");
    John.takeDamage(Tom.getAttackDamage());

    John.beRepaired(5);
	
	John.highFivesGuys();
	Tom.highFivesGuys();
    return 0;
}