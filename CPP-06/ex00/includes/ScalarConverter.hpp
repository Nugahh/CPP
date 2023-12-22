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
#include <cmath>
#include <limits>
#include <cstdlib>

class ScalarConverter {
	public:
		static const int MIN_CHAR = 0;
		static const int MAX_CHAR = 127;
		static const int MIN_INT = -2147483648;
		static const int MAX_INT = 2147483647;
		static const int MIN_DISPLAYABLE = 32;
		static const int MAX_DISPLAYABLE = 126;

		// Static member methods
		static bool checkInput(const std::string& str);
		static bool isOnlyDigits(const std::string& str);
		static void printChar(char c);
		static void castToChar(double literal);
		static void castToInt(double literal);
		static void castToFloat(double literal);
		static void castToDouble(double literal);
		static void convert(const std::string& str);

	private:
		// Private constructor and destructor to prevent instantiation
		ScalarConverter();
		~ScalarConverter();
		// Copy constructor and assignment operator also private if copying is not allowed
		ScalarConverter(const ScalarConverter& copy);
		ScalarConverter& operator=(const ScalarConverter& rhs);
};

#endif