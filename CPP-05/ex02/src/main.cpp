/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwong <fwong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 01:42:15 by fwong             #+#    #+#             */
/*   Updated: 2023/10/04 19:52:23 by fwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

int main()
{
	std::cout << BRED << "============ Test Too Low Grade to construct ============" << RESET << std::endl;
	try {
		Form LowForm("LowForm", 160, 120);
	}
	catch (Form::GradeTooLowException e) {
		std::cout << "LowForm constructor : ";
		e.error();
	}

	std::cout << BRED << "\n============ Test Too High Grade to construct ============" << RESET << std::endl;
	try {
		Form HighForm("HighForm", 10, 0);
	}
	catch (Form::GradeTooHighException e) {
		std::cout << "HighForm constructor : ";
		e.error();
	}

	std::cout << BGRN << "\n============ Test constructor OK ============" << RESET << std::endl;
	Bureaucrat	President("President", 1);
	Bureaucrat	Random("Random", 100);
	Form		Form1("Form1", 50, 50);
	Form		CopyForm1(Form1);

	std::cout << BGRN << "\n============ Test Accessors ============" << RESET << std::endl;
	std::cout	<< "Form1's name is "
				<< Form1.getName()
				<< ", need grade "
				<< Form1.getGradeToSign()
				<< " to be signed and grade "
				<< Form1.getGradeToExecute()
				<< " to be exec, signature status: "
				<< Form1.isSigned()
				<< std::endl;
 
	std::cout << BRED << "\n============ Test Signature of Forms ============" << RESET << std::endl;
	try {
		Form1.beSigned(Random);
	}
	catch (Form::GradeTooLowException e) {
		std::cout << "Random tried to sign the form and: ";
		e.error();
	}
	CopyForm1.beSigned(President);
	
	std::cout << BRED << "\n============ Test surcharge operateur insertion ============" << RESET << std::endl;
	std::cout << Form1 << std::endl;
	std::cout << CopyForm1 << std::endl;

}
	
