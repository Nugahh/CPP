/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwong <fwong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 20:57:42 by fwong             #+#    #+#             */
/*   Updated: 2023/06/20 22:15:30 by fwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <string>

class Contact {
	
	public:
		Contact();
		~Contact();
		
		void setFirstName(const std::string &firstName);
		void setLastName(const std::string &lastName);
		void setNickName(const std::string &nickName);
		void setPhoneNumber(const std::string &phoneNumber);
		void setDarkestSecret(const std::string &darkestSecret);
		
		std::string getFirstName();
		std::string getLastName();
		std::string getNickName();
		std::string getPhoneNumber();
		std::string getDarkestSecret();
		
		void setContact();

	private:
		std::string firstName;
		std::string lastName;
		std::string nickName;
		std::string phoneNumber;
		std::string darkestSecret;
};

#endif