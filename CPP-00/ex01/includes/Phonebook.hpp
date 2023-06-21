/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwong <fwong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 20:46:35 by fwong             #+#    #+#             */
/*   Updated: 2023/06/21 16:53:40 by fwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include <string>
#include <cstring>
#include <iomanip>
#include <cctype>
#include <stdio.h>
#include <stdlib.h>
#include <sstream>
#include "Contact.hpp"
#include "Colors.hpp"

class Phonebook {
	
	public:
	
		Phonebook();
		~Phonebook();
		void add();
		void search();
		void exit();
		
	private:
		int _index;
		Contact book[8];
};

#endif
