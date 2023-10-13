/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwong <fwong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 01:42:15 by fwong             #+#    #+#             */
/*   Updated: 2023/10/13 23:53:17 by fwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "colors.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
	
	Bureaucrat president("Trump", 15);
	Bureaucrat middle("Middle", 75);
	Bureaucrat minister("Minister", 44);
	Bureaucrat pleb("Pleb", 150);
	
	ShrubberyCreationForm shrubbery("Shrubbery");
	RobotomyRequestForm robotomy("Robotomy");
	PresidentialPardonForm presidential("Presidential");

	std::cout << std::endl;
	try {
		president.signForm(presidential);
		president.executeForm(presidential);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;

	try {
		minister.signForm(presidential);
		minister.executeForm(presidential);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
}