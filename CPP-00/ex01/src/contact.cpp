/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwong <fwong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 20:55:49 by fwong             #+#    #+#             */
/*   Updated: 2023/06/21 16:58:56 by fwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Contact.hpp"

Contact::Contact() {}

Contact::~Contact() {}

std::string Contact::getFirstName() { return this->firstName; }

std::string Contact::getLastName() { return this->lastName; }

std::string Contact::getNickName() { return this->nickName; }

std::string Contact::getPhoneNumber() { return this->phoneNumber; }

std::string Contact::getDarkestSecret() { return this->darkestSecret; }

void Contact::setFirstName(const std::string &firstName) { this->firstName = firstName; }
void Contact::setLastName(const std::string &lastName) { this->lastName = lastName; }
void Contact::setNickName(const std::string &nickName) { this->nickName = nickName; }
void Contact::setPhoneNumber(const std::string &phoneNumber) { this->phoneNumber = phoneNumber; }
void Contact::setDarkestSecret(const std::string &darkestSecret) { this->darkestSecret = darkestSecret; }

void Contact::setContact()
{
	std::string input;
	std::string setPhrase[5] =
		{ "Enter First Name: ", "Enter Last Name: ", "Enter Nickname: ", "Enter Phone number: ", "Enter Darkest Secret: " };
	std::string getters[5] =
		{ firstName, lastName, nickName, phoneNumber, darkestSecret };
		
	for (int i = 0; i < 5; i++)
	{
		std::cout << setPhrase[i] << std::endl;
		getline(std::cin, input);
		if (!input.empty())
		{
			switch (i)
			{
				case 0:
					setFirstName(input);
					break;
				case 1:
					setLastName(input);
					break;
				case 2:
					setNickName(input);
					break;
				case 3:
					setPhoneNumber(input);
					break;
				case 4:
					setDarkestSecret(input);
					break;
			}
		}
	}
}

