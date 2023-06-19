/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwong <fwong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 20:55:49 by fwong             #+#    #+#             */
/*   Updated: 2023/06/19 16:27:42 by fwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact() {
	
	std::cout << "lol c bon construit" << std::endl;
}

Contact::~Contact() {
	
	std::cout << "mdr c bon destroyed" << std::endl;
}

std::string Contact::getFirstName() { return this->firstName; }

std::string Contact::getLastName() { return this->lastName; }

std::string Contact::getNickName() { return this->nickName; }

std::string Contact::getPhoneNumber() { return this->phoneNumber; }

std::string Contact::getDarkestSecret() { return this->darkestSecret; }

void setContact(std::string firstName, std::string lastName, std::string nickName, std::string phoneNumber, std::string darkestSecret)
{
	std::string contact;
	std::string setPhrase[5] =
		{ "Enter First Name: ", "Enter Last Name: ", "Enter Nickname: ", "Enter Phone number: ", "Enter Darkest Secret: " };
	
	std::cin.ignore();
	for (int i = 0; i < 4; i++)
	{
		std::cout << setPhrase[i] << std::endl;
		getline(std::cin, contact);
		if (contact.empty())
	}
}

