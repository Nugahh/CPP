/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwong <fwong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 20:57:42 by fwong             #+#    #+#             */
/*   Updated: 2023/06/19 16:09:54 by fwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _PHONEBOOK_HPP_
#define _PHONEBOOK_HPP_

#include <iostream>
#include <string>

class Contact {
	
	public:
		Contact();
		~Contact();
		
		std::string getFirstName();
		std::string getLastName();
		std::string getNickName();
		std::string getPhoneNumber();
		std::string getDarkestSecret();
		
		void setContact(std::string firstName, std::string lastName, std::string nickName, std::string phoneNumber, std::string darkestSecret);

	private:
		std::string firstName;
		std::string lastName;
		std::string nickName;
		std::string phoneNumber;
		std::string darkestSecret;
};

#endif