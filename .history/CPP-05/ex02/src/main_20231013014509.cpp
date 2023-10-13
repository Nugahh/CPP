/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwong <fwong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 01:42:15 by fwong             #+#    #+#             */
/*   Updated: 2023/10/13 01:45:09 by fwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
	
	Bureaucrat president("Trump", 1);
	Bureaucrat pleb("Pleb", 150);
	
	ShrubberyCreationForm shrubbery("Shrubbery");
	RobotomyRequestForm robotomy("Robotomy");
	PresidentialPardonForm presidential("Presidential");

	president.signForm()
	std::cout << "OKOKOK" << std::endl;
	president.executeForm(presidential);
	std::cout << "CACACA" << std::endl;
	
}