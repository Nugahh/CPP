/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwong <fwong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 18:03:13 by fwong             #+#    #+#             */
/*   Updated: 2023/06/27 18:30:14 by fwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Colors.hpp"
#include <iostream>
#include <string>
#include <cstring>
#include <cctype>

int main() {

	std::string brain = "HI THIS IS BRAIN";
	std::string* stringPTR = &brain;
	std::string& stringREF = brain;

	std::cout << "Address of brain: " << &brain << std::endl;
    std::cout << "Address in stringPTR: " << stringPTR << std::endl;
    std::cout << "Address in stringREF: " << &stringREF << std::endl;
	
	std::cout << "brain: " << brain << std::endl;
    std::cout << "stringPTR: " << *stringPTR << std::endl;
    std::cout << "stringREF: " << stringREF << std::endl;

	return 0;
}