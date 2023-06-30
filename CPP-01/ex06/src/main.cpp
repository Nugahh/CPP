/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwong <fwong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 14:23:14 by fwong             #+#    #+#             */
/*   Updated: 2023/06/30 18:04:21 by fwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include "../includes/Harl.hpp"

int main(int argc, char *argv[]) {

	Harl harl;
	
	if (argc != 2) {
		std::cout << "Usage: ./harl [filename]" << std::endl;
		return 1;
	} else {
		harl.complain(argv[1]);
	}
	return 0;	
}