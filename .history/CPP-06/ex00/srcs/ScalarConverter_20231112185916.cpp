/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwong <fwong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 16:54:07 by fwong             #+#    #+#             */
/*   Updated: 2023/11/12 18:59:16 by fwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter& copy) { *this = copy; }

ScalarConverter::~ScalarConverter() {}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& rhs) {
	if (this != &rhs) {
		*this = rhs;
  	}
	return (*this);
}

bool	ScalarConverter::checkInput(std::string str) {
	
	const std::string exceptions[8] = {"nan", "nanf", "-inf", "+inf", "-inff", "+inff", "inf", "inff"};
	
    for (size_t i = 0; i < 8; i++) {
		if (exceptions[i] == str)
			return (true);
	}
	if ()
	size_t	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	int count = 0;
	for (; i < str.length() && (isdigit(str[i]) || str[i] == '.' ); i++) {
		if (!isdigit(str[i]) && str[i] == '.')
			count++;
		if (count > 1)
			return (false);
	}
	if (i != 0 && str[i] == 'f' && i != str.length() - 1)
		return (false);
	return (true);
}

bool	ScalarConverter::isOnlyDigits(std::string str) {
	size_t	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	for (; i < str.length(); i++) {
		if (!isdigit(str[i]))
			return (false);
	}
	return (true);
}

void	ScalarConverter::castToChar(double literal) {
	if (!std::isfinite(literal) || (literal < MIN_CHAR || literal > MAX_CHAR) || std::isnan(literal))
		std::cout << "char: impossible" << std::endl;
	else if (literal < MIN_DISPLAYABLE || literal > MAX_DISPLAYABLE)
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << static_cast<char>(literal) << "'" << std::endl;
}

void	ScalarConverter::castToInt(double literal) {
	if (!std::isfinite(literal) || (literal < MIN_INT || literal > MAX_INT) || std::isnan(literal))
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(literal) << std::endl;
}

void	ScalarConverter::castToFloat(double literal) {
	if (!std::isfinite(literal) || std::isnan(literal))
		std::cout << "float: " << literal << "f" << std::endl;
	else
		std::cout << "float: " << static_cast<float>(literal) << "f" << std::endl;
}

void	ScalarConverter::castToDouble(double literal) {
	if (!std::isfinite(literal) || std::isnan(literal))
		std::cout << "double: " << literal << std::endl;
	else
		std::cout << "double: " << static_cast<double>(literal) << std::endl;
}

void	ScalarConverter::convert(std::string str) {
	if (checkInput(str) == false) {
		std::cout << "Error: Invalid input" << std::endl;
		return ;
	}
	std::cout << std::fixed << std::setprecision(1);
	double literal = std::atof(str.c_str());
	if (str.length() == 1 && !isdigit(str[0]))
		castToChar(literal);
	else if (str.length() == 3 && str[0] == '\'' && str[2] == '\'')
		castToChar(literal);
	else if (isOnlyDigits(str) == true)
		castToInt(literal);
	else if (str[str.length() - 1] == 'f')
		castToFloat(literal);
	else
		castToDouble(literal);
}