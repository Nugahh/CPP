/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwong <fwong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 20:55:49 by fwong             #+#    #+#             */
/*   Updated: 2023/06/15 18:39:01 by fwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact() {
	
	std::cout << "lol c bon construit" << std::endl;
}

Contact::~Contact() {
	
	std::cout << "mdr c bon destroyed" << std::endl;
}

void Contact::getFirstName() {

	std::cout << this->firstName << std::endl;
}

void Contact::getLastName() {

	std::cout << this->lastName << std::endl;
}

void Contact::getNickName() {

	std::cout << this->nickName << std::endl;
}

void Contact::getPhoneNumber() {

	std::cout << this->phoneNumber << std::endl;
}

void Contact::getDarkestSecret() {

	std::cout << this->darkestSecret << std::endl;
}

void setContact(std::string firstName, std::string lastName, std::string nickName, std::string phoneNumber, std::string darkestSecret)
{
	std::string contact;
	getline(std::cin, contact);
}