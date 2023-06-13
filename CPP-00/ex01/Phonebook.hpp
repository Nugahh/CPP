/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwong <fwong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 20:46:35 by fwong             #+#    #+#             */
/*   Updated: 2023/06/13 21:02:26 by fwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _PHONEBOOK_HPP_
#define _PHONEBOOK_HPP_

#include <iostream>
#include <string>
#include "Contact.hpp"

class Phonebook {
	
	public:
	
		Phonebook();
		~Phonebook();
		void search(int);
		void add();
		void exit();
		
	private:
		Contact contact[8];
};

#endif
