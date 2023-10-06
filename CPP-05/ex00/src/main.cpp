/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwong <fwong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 01:42:15 by fwong             #+#    #+#             */
/*   Updated: 2023/09/23 10:17:25 by fwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
	std::cout << BRED << "============ Test Too Low Grade to construct ============" << RESET << std::endl;
	try {
		Bureaucrat Nour("Nour", 160);
	}
	catch (Bureaucrat::GradeTooLowException e) {
		std::cout << "Nour constructor : ";
		e.error();
	}

	std::cout << BRED << "\n============ Test Too High Grade to construct ============" << RESET << std::endl;
	try {
		Bureaucrat Kelly("Kelly", 0);
	}
	catch (Bureaucrat::GradeTooHighException e) {
		std::cout << "Kelly constructor : ";
		e.error();
	}

	std::cout << BGRN << "\n============ Test constructor OK ============" << RESET << std::endl;
	Bureaucrat Default;
	Bureaucrat Yannis("Yannis", 2);
	Bureaucrat Copy(Yannis);
	Bureaucrat Nugah("Nugah", 149);

	std::cout << BGRN << "\n============ Test Accessors ============" << RESET << std::endl;
	std::cout << "Yannis' name is " << Yannis.getName() << " and his grade is " << Yannis.getGrade() << std::endl;
	std::cout << "Copy's name is " << Copy.getName() << " and his grade is " << Copy.getGrade() << std::endl;

	std::cout << BRED << "\n============ Test Too High Grade to upGrade ============" << RESET << std::endl;
	try {
		Yannis.incrementGrade();
		Yannis.incrementGrade();
	}
	catch (Bureaucrat::GradeTooHighException e) {
		std::cout << "Yannis upgrade: ";
		e.error();
	}

	std::cout << BRED << "\n============ Test Too Low Grade to downGrade ============" << RESET << std::endl;
	try {
		Nugah.decrementGrade();
		Nugah.decrementGrade();
	}
	catch (Bureaucrat::GradeTooLowException e) {
		std::cout << "Nugah downgrade: ";
		e.error();
	}
}
	
