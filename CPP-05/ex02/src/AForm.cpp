/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwong <fwong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 19:47:12 by fwong             #+#    #+#             */
/*   Updated: 2023/10/06 17:43:02 by fwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm() : _name("default"), _gradeToExecute(150), _gradeToSign(150), _signed(false) {
	std::cout << "AForm Default Constructor called" << std::endl;
}

AForm::AForm(const AForm& copy) : _name(copy._name), _gradeToExecute(copy._gradeToExecute), _gradeToSign(copy._gradeToSign), _signed(copy._signed) {
	std::cout << "AForm Copy Constructor called" << std::endl;
}

AForm::AForm(std::string name, int gradeToExecu                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                            te, int gradeToSign) : _name(name), _gradeToExecute(gradeToExecute), _gradeToSign(gradeToSign), _signed(false) {
	std::cout << "AForm Constructor called" << std::endl;
	if (this->_gradeToExecute < 1 || this->_gradeToSign < 1)
		throw AForm::GradeTooHighException();
	else if (this->_gradeToExecute > 150 || this->_gradeToSign > 150)
		throw AForm::GradeTooLowException();
}

AForm::~AForm() {
	std::cout << "AForm Destructor called" << std::endl;
}

AForm &AForm::operator=(const AForm &copy) {
	std::cout << "AForm Assignation Operator called" << std::endl;
	this->_signed = copy._signed;
	return (*this);
}

std::ostream &operator<<(std::ostream& out, AForm& form) {
	out << "AForm: " << form.getName() << " requires grade " << form.getGradeToSign() << " to sign and grade " << form.getGradeToExecute() << " to execute." << std::endl;
	return (out);
}

std::string AForm::getName() const { return (this->_name); }

int AForm::() const { return (this->_gradeToExecute); }

int	AForm::getGradeToSign() const { return (this->_gradeToSign); }

bool AForm::isSigned() const { return (this->_signed); }

void AForm::beSigned(Bureaucrat &br) {
	if (br.getGrade() > this->_gradeToSign)
		AForm::GradeTooLowException();
	else
		this->_signed = true;
}