/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwong <fwong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 21:48:32 by fwong             #+#    #+#             */
/*   Updated: 2023/11/22 22:45:07 by fwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <string>
# include <iomanip>
# include <sstream>
# include <ctime>
# include <cstdlib>
# include <cctype>
# include <cmath>
# include <exception>
# include <cstddef> // For size_t
# include <map>

class	BitcoinExchange {
	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &copy);
		~BitcoinExchange();
		
		BitcoinExchange &operator=(const BitcoinExchange &rhs);

		void	calculatePrice(std::string date, float price);
		
	private:
		std::map<std::string, float>	_bitcoinValueByDate;
};

#endif