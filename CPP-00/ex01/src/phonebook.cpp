/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwong <fwong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 20:55:51 by fwong             #+#    #+#             */
/*   Updated: 2023/06/21 16:54:03 by fwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Phonebook.hpp"

Phonebook::Phonebook() { _index = 0; }

Phonebook::~Phonebook() {}


void Phonebook::add() {
	if (_index < 8)
	{
		book[_index].setContact();
		_index++;
	}
	else
	{
		_index = 0;
		book[_index].setContact();
		_index++;
	}
}

void Phonebook::search() {

	std::string input;
	int number;

	std::cout << std::setw(10) << "INDEX" << "|";
	std::cout << std::setw(10) << "FIRSTNAME" << "|";
	std::cout << std::setw(10) << "LASTNAME" << "|";
	std::cout << std::setw(10) << "NICKNAME" << std::endl;
	
	for (int i = 0; i < 8; i++)
	{
		std::cout << std::setw(10) << i + 1 << "|";
		if (book[i].getFirstName().length() > 10)
			std::cout << std::setw(9) << book[i].getFirstName().substr(0, 9) << "." << "|";
		else
			std::cout << std::setw(10) << book[i].getFirstName() << "|";
		if (book[i].getLastName().length() > 10)
			std::cout << std::setw(9) << book[i].getLastName().substr(0, 9) << "." << "|";
		else
			std::cout << std::setw(10) << book[i].getLastName() << "|";
		if (book[i].getNickName().length() > 10)
			std::cout << std::setw(9) << book[i].getNickName().substr(0, 9) << "." << "|" << std::endl;
		else
			std::cout << std::setw(10) << book[i].getNickName() << "|" << std::endl;
	}
	std::cout << "Choose Index: " << std::endl;
	getline(std::cin, input);
	std::istringstream iss(input);
	iss >> number;
	if (std::cin.fail()) {
            std::cin.clear();
            return ;
        }
	while (number < 1 || number > 8)
	{
		std::cout << RED << "Wrong Index !" << RESET << std::endl;
		std::cout << RED << "Enter only number from 1 to 8: " << RESET << std::endl;
		getline(std::cin, input);
		std::istringstream iss(input);
		iss >> number;
	}
	std::cout << "First Name: " << book[atoi(input.c_str())].getFirstName() << std::endl;
	std::cout << "Last Name: " << book[atoi(input.c_str())].getLastName() << std::endl;
	std::cout << "Nickname: " << book[atoi(input.c_str())].getNickName() << std::endl;
	std::cout << "Phone Number: " << book[atoi(input.c_str())].getPhoneNumber() << std::endl;
	std::cout << "Darkest secret: " << book[atoi(input.c_str())].getDarkestSecret() << std::endl;
}

