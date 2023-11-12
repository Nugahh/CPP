/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwong <fwong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 16:54:07 by fwong             #+#    #+#             */
/*   Updated: 2023/11/12 16:45:00 by fwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter& copy) { *this = copy; }

ScalarConverter::~ScalarConverter() {}

ScalarConverter ScalarConverter::operator=(const ScalarConverter& rhs) {
	if (this != &rhs) {
		*this = rhs;
  	}
	return (*this);
}

bool	ScalarConverter::checkInput(std::string str) {
	
	const std::string exceptions[8] = {"nan", "nanf", "-inf", "+inf", "-inff", "+inff", "inf", "inff"};
    const std::string* end = exceptions + 8; // Pointer to the end of the array
    const std::string* result = std::find(exceptions, end, str);
	
    if (result == end) // If result is not the end, we found a match
		return (false);
	int i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	int count = 0;
	for (; i < str.length() && (isdigit(str[i]) || str[i] == '.' ); i++) {
		if (!isdigit(str[i]) && str[i] == '.')
			count++;
		if (count > 1)
			return (false);
	}
	if (str[i] == 'f' && i == str.length() - 1)
		return (true);
	return (false);
}

void	ScalarConverter::castToChar(double literal) {
	std::cout << "char: ";
	if (literal < 0 || literal > 127 || std::isnan(literal))
		std::cout << "impossible" << std::endl;
	else if (literal < 32 || literal > 126)
		std::cout << "Non displayable" << std::endl;
	else
		std::cout << "'" << static_cast<char>(literal) << "'" << std::endl;
}
void	ScalarConverter::convert(std::string str) {
	
	double
	if (str.length() == 1 && !isdigit(str[0]))
		castToChar(str[0]);
	else if (str.length() == 3 && str[0] == '\'' && str[2] == '\'')
		castToChar(str[1]);
	else if (str == "-inff" || str == "+inff" || str == "nanf")
		castToFloat(str);
	else if (str == "-inf" || str == "+inf" || str == "nan")
		castToDouble(str);
	else
		castToDouble(str);
}