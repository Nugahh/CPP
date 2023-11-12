/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwong <fwong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 06:45:05 by fwong             #+#    #+#             */
/*   Updated: 2023/10/17 06:45:05 by fwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <iomanip>
#include <algorithm>
#include <cctype>

class ScalarConverter {
	public:
		ScalarConverter();
		ScalarConverter(const ScalarConverter &copy);
		~ScalarConverter();	

		ScalarConverter &operator=(const ScalarConverter &rhs);

		bool	checkInput(std::string str);
		void	castToChar(double literal);
		void	castToInt(double literal);
		void	castToFloat(double literal);
		void	castToDouble(double literal);
		void	convert(std::string str);
	
};

#endif
