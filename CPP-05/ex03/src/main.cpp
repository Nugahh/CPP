/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwong <fwong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 01:42:15 by fwong             #+#    #+#             */
/*   Updated: 2023/10/15 20:15:14 by fwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "colors.hpp"
#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
	
	Bureaucrat president("Trump", 1);
	Bureaucrat middle("Middle", 75);
	Bureaucrat minister("Minister", 44);
	Bureaucrat pleb("Pleb", 150);

	Intern intern;
	
	// ShrubberyCreationForm shrubbery("Shrubbery");
	// RobotomyRequestForm robotomy("Robotomy");
	// PresidentialPardonForm presidential("Presidential");

	AForm* shrubbery = intern.makeForm("ShrubberyCreationForm", "Shrubbery");
	AForm* robotomy = intern.makeForm("RobotomyRequestForm", "Robotomy");
	AForm* presidential = intern.makeForm("PresidentialPardonForm", "Presidential");
	
	std::cout << std::endl;
	std::cout << BGRN << "Bureaucrat can sign and execute forms" << RESET << std::endl;
	try {
		president.signForm(*presidential);
		president.executeForm(*presidential);
		president.signForm(*robotomy);
		president.executeForm(*robotomy);
		president.signForm(*shrubbery);
		president.executeForm(*shrubbery);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;

	std::cout << BGRN << "Bureaucrat can sign and execute forms but not PresidentialPardonForm" << RESET << std::endl;
	try {
		minister.signForm(*shrubbery);
		minister.executeForm(*shrubbery);
		minister.signForm(*robotomy);
		minister.executeForm(*robotomy);
		minister.signForm(*presidential);
		minister.executeForm(*presidential);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
	std::cout << BGRN << "Bureaucrat can only sign and execute ShrubberyCreationForm" << RESET << std::endl;
	try {
		middle.signForm(*shrubbery);
		middle.executeForm(*shrubbery);
		middle.signForm(*robotomy);
		middle.executeForm(*robotomy);
		middle.signForm(*presidential);
		middle.executeForm(*presidential);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
	std::cout << BGRN << "Bureaucrat cannot sign any forms" << RESET << std::endl;
	try {
		pleb.signForm(*shrubbery);
		pleb.executeForm(*shrubbery);
		pleb.signForm(*robotomy);
		pleb.executeForm(*robotomy);
		pleb.signForm(*presidential);
		pleb.executeForm(*presidential);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	delete shrubbery;
	delete robotomy;
	delete presidential;
	std::cout << std::endl;
	std::cout << "----------------------------------------" << std::endl;
	std::cout << std::endl;
}