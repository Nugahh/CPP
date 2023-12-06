/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwong <fwong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 22:36:11 by fwong             #+#    #+#             */
/*   Updated: 2023/12/04 18:30:33 by fwong            ###   ########.fr       */
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

bool	BitcoinExchange::isDateValid(const std::string& date) {
 	std::istringstream iss(date);
    std::string yearStr, monthStr, dayStr;
    int year, month, day;

    // Extract year, month, and day as strings
    if (!std::getline(iss, yearStr, '-') ||
        !std::getline(iss, monthStr, '-') ||
        !std::getline(iss, dayStr)) {
        return false;  // Return false if the extraction fails
    }

    // Create separate istringstream objects for conversion
    std::istringstream yearStream(yearStr);
    std::istringstream monthStream(monthStr);
    std::istringstream dayStream(dayStr);
	
	// Convert the strings to integers
    if (!(yearStream >> year) || !(monthStream >> month) || !(dayStream >> day)) {
        return false; // Return false if conversion fails
    }
	
    // Check year range (you can define your own range)
    if (year < 1 || year > 9999) return false;

    // Check month range
    if (month < 1 || month > 12) return false;

    // Days in each month
    int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    // Check for leap year and update February days
    if (month == 2) {
        bool isLeap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
        if (isLeap) daysInMonth[1] = 29;
    }

    // Check day range
    return day > 0 && day <= daysInMonth[month - 1];
}

bool BitcoinExchange::isFloat(const std::string& value) {
	size_t i = 0;
	while (value[0] == ' ')
		i++;
	if (value[0] == '+')
		i++;
	else if (value[0] == '-')
		return false;
	for (; i < value.length(); i++) {
		if (value[i] == '.') {
			if (i == 0 || i == value.length() - 1)
				return false;
			else
				continue;
		}
		if (!isdigit(value[i]))
			return false;
	}
	return true;
}

bool	BitcoinExchange::checkInput(const std::string& line) {
	size_t pipePos = line.find('|');
	if (pipePos == std::string::npos) {
		std::cerr << "Error: '|' not found in line" << std::endl;
		return false; // Skip this line and return false
	}

	std::string dateStr = line.substr(0, pipePos);
	std::string valueStr = line.substr(pipePos + 1);

	dateStr.erase(dateStr.find_last_not_of(" \r\n") + 1);
	valueStr.erase(0, valueStr.find_first_not_of(" \r\n"));
	valueStr.erase(valueStr.find_last_not_of(" \r\n") + 1);

	if (!isDateValid(dateStr)) {
		std::cerr << "Error: invalid date => " << dateStr << std::endl;
		return false; // Skip this line and return false
	}
	if (!isFloat(valueStr)) {
		std::cerr << "Error: invalid value => " << valueStr << std::endl;
		return false; // Skip this line and return false
	}
	return true;
}

void	BitcoinExchange::parseFile(const std::string& rawFile) {
	if (rawFile.compare("data.csv") == 0) {
		std::ifstream file;
		std::string filePath = rawFile;
		file.open(filePath.c_str());
		if (!file.is_open()) {
			std::cout << "Error: file not found" << std::endl;
			return ;
		}
		std::string line;
		std::getline(file, line); // Skip the first line
		while (std::getline(file, line)) {
			std::istringstream iss(line);
			std::string date;
			float value;

			if (std::getline(iss, date, ',') && (iss >> value)) {
				// Insert the data into the map
				_bitcoinValueByDate[date] = value;
			}
		}
	} else {
		std::ifstream file;
		std::string filePath = rawFile;
		file.open(filePath.c_str());
		if (!file.is_open()) {
			std::cout << "Error: file not found" << std::endl;
			return ;
		}
		std::string line;
		std::getline(file, line); // Skip the first line
		while (std::getline(file, line)) {
			if (checkInput(line) == false)
				continue; // Skip this line and continue
			std::istringstream iss(line);
			std::string date;
			double value;
			if (std::getline(iss, date, '|') && (iss >> value)) {
				date.erase(date.find_last_not_of(" \r\n") + 1);
				if (value < 0 || value > 1000) {
					std::cerr << "Error: too large a number." << std::endl;
					continue; // Skip this line and continue
				}
				std::map<std::string, float>::iterator it = _bitcoinValueByDate.lower_bound(date);
            if (it == _bitcoinValueByDate.end() || it->first != date) {
                if (it != _bitcoinValueByDate.begin()) {
                    --it; // Get the nearest earlier date
                } else {
                    std::cerr << "No earlier dates available." << std::endl;
                    continue; // No earlier dates, skip this line
                }
            }
            std::cout << date << " => " << it->second << " = " << it->second * value << std::endl;
			}
		}
	}
}
