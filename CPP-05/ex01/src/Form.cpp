/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwong <fwong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 13:33:18 by fwong             #+#    #+#             */
/*   Updated: 2023/10/09 23:09:12 by fwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : _name("default"), _gradeToExecute(150), _gradeToSign(150), _signed(false) {
	std::cout << "Form Default Constructor called" << std::endl;
}

Form::Form(const Form& copy) : _name(copy._name), _gradeToExecute(copy._gradeToExecute), _gradeToSign(copy._gradeToSign), _signed(copy._signed) {
	std::cout << "Form Copy Constructor called" << std::endl;
}

Form::Form(std::string name, int gradeToExecute, int gradeToSign) : _name(name), _gradeToExecute(gradeToExecute), _gradeToSign(gradeToSign), _signed(false) {
	std::cout << "Form Constructor called" << std::endl;
	if (this->_gradeToExecute < 1 || this->_gradeToSign < 1)
		throw Form::GradeTooHighException();
	else if (this->_gradeToExecute > 150 || this->_gradeToSign > 150)
		throw Form::GradeTooLowException();
}

Form::~Form() {
	std::cout << "Form Destructor called" << std::endl;
}

Form &Form::operator=(const Form &copy) {
	std::cout << "Form Assignation Operator called" << std::endl;
	this->_signed = copy._signed;
	return (*this);
}

std::ostream &operator<<(std::ostream& out, Form& form) {
	out << "Form: " << form.getName() << " requires grade " << form.getGradeToSign() << " to sign and grade " << form.getGradeToExecute() << " to execute." << std::endl;
	return (out);
}

std::string Form::getName() const { return (this->_name); }

int Form::getGradeToExecute() const { return (this->_gradeToExecute); }

int Form::getGradeToSign() const { return (this->_gradeToSign); }

bool Form::isSigned() const { return (this->_signed); }

void Form::beSigned(Bureaucrat &br) {
	if (br.getGrade() > this->_gradeToSign)
		throw Form::GradeTooLowException();
	else
		this->_signed = true;
}

const char *Form::GradeTooHighException::what() const throw() {
	return ("Grade is too high");
}

const char *Form::GradeTooLowException::what() const throw() {
	return ("Grade is too low");
}