/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwong <fwong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 14:03:43 by fwong             #+#    #+#             */
/*   Updated: 2023/12/04 15:50:56 by fwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int argc, char *argv[]) {
	
	if (argc != 2) {
		std::cout << "Usage: ./btc [testFile]" << std::endl;
		return 1;
	}
	BitcoinExchange btc;
	btc.parseFile("data.csv");
	btc.parseFile(argv[1]);
	return 0;
}