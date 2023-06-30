/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwong <fwong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 17:40:03 by fwong             #+#    #+#             */
/*   Updated: 2023/06/30 18:09:04 by fwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Harl.hpp"

Harl::Harl() {}

Harl::~Harl() {}

void Harl::debug() {
	std::cout << "DEBUG: This is a debug message." << std::endl;
}

void Harl::info() {
	std::cout << "INFO: This is an info message." << std::endl;
}

void Harl::warning() {
	std::cout << "WARNING: This is a warning message." << std::endl;
}

void Harl::error() {
	std::cout << "ERROR: This is an error message." << std::endl;
}

void Harl::complain(std::string level) {
	
	const std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int i = 0;

	while (i < 4 && levels[i].compare(level))
		i++;
	switch (i)
	{
		case 0:
			debug();
		case 1:
			info();
		case 2:
			warning();
		case 3:
			error();
			break;
		default:
			std::cout << "Probably complaining about insignificant problems." << std::endl;
	}
}