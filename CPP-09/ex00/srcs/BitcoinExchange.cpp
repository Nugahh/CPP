/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwong <fwong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 22:36:11 by fwong             #+#    #+#             */
/*   Updated: 2023/11/22 23:16:30 by fwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &cpy) {
	*this = cpy;
}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &rhs) {
	if (this != &rhs) {
		*this = rhs;
	}
	return *this;
}

void	BitcoinExchange::calculatePrice(std::string date, int quantity) {
	float	currentPriceByQuantity = 0;
	float	currentPriceByDate = atof(_bitcoinValueByDate[date]);
	currentPriceByQuantity = currentPriceByDate * quantity;
}

