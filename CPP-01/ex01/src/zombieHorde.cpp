/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwong <fwong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 21:10:31 by fwong             #+#    #+#             */
/*   Updated: 2023/06/27 17:37:26 by fwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Zombie.hpp"

Zombie* zombieHorde(int N, std::string name) {
	
	Zombie* horde = new Zombie[N];
	
	for (int i = 0; i < N; i++) {
		horde[i].setName(name);
		horde[i].announce();
	}
	return horde;
}
