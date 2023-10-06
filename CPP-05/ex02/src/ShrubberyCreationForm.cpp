/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwong <fwong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 17:25:44 by fwong             #+#    #+#             */
/*   Updated: 2023/10/06 17:50:49 by fwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137) {
	std::cout << "Default constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137) {
	std::cout << "Parametric constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& copy) : AForm(copy) {
	std::cout << "Copy constructor called" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
	std::cout << "Destructor called" << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm &copy) {
	std::cout << "Assignation operator called" << std::endl;
	if (this != &copy)
		AForm::operator=(copy);
	return (*this);
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const {
	std::string fileName = this->getName() + "_shrubbery";
	std::ofstream outputFile;

	if (executor.getGrade() < this->getGradeToExecute()) {
		outputFile.open(fileName);
		outputFile << "      /\\      " << std::endl;
		outputFile << "     /\\*\\     " << std::endl;
		outputFile << "    /\\O\\*\\    " << std::endl;
		outputFile << "   /*/\\/\\/\\   " << std::endl;
		outputFile << "  /\\O\\/\\*\\/\\  " << std::endl;
		outputFile << " /\\*\\/\\*\\/\\/\\ " << std::endl;
		outputFile << "/\\O\\/\\/*/\\/O/\\" << std::endl;
		outputFile << "      ||      " << std::endl;
		outputFile << "      ||      " << std::endl;
		outputFile << "      ||      " << std::endl;
		outputFile << std::endl;
		outputFile.close();
	} else if (!this->isSigned()) {
		throw AForm::NotSignedException();	
	} else
		throw AForm::GradeTooLowException();
}