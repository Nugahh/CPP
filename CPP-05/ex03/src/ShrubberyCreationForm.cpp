/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwong <fwong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 17:25:44 by fwong             #+#    #+#             */
/*   Updated: 2023/10/15 19:20:55 by fwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), _target("Default") {
	std::cout << "Default constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137), _target(target) {
	std::cout << "Parametric constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& copy) : AForm(copy), _target(copy._target) {
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

void	ShrubberyCreationForm::execute(Bureaucrat const & executor) const {
	if (executor.getGrade() > getGradeToExecute())
		throw AForm::GradeTooLowException();
	if (isSigned() == false)
		throw AForm::NotSignedException();
	std::string fileName = _target + "_shrubbery";
	std::ofstream outputFile;

	outputFile.open(fileName.c_str());
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
}