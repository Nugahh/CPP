/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwong <fwong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 19:43:52 by fwong             #+#    #+#             */
/*   Updated: 2023/10/15 20:24:31 by fwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern() { std::cout << "Default constructor called" << std::endl; }

Intern::Intern(const Intern& copy) { std::cout << "Copy constructor called" << std::endl; *this = copy; }

Intern::~Intern() { std::cout << "Destructor called" << std::endl; }

Intern& Intern::operator=(const Intern& copy) {
	std::cout << "Assignation operator called" << std::endl;
	if (this != &copy)
		*this = copy;
	return (*this);
}

AForm* Intern::makeForm(std::string formName, std::string target) {
	const std::string formNames[3] = {"PresidentialPardonForm", "RobotomyRequestForm", "ShrubberyCreationForm"};

	int i = 0;
	while (formNames[i].compare(formName)) {
		if (i == 3)
			break ;
		i++;
	}
	switch (i) {
		case 0:
			return (new PresidentialPardonForm(target));
		case 1:
			return (new RobotomyRequestForm(target));
		case 2:
			return (new ShrubberyCreationForm(target));
		default:
			std::cout << "Form name not found" << std::endl;
			return (NULL);
	}
}