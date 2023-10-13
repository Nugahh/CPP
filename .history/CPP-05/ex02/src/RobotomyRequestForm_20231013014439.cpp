/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwong <fwong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 17:25:32 by fwong             #+#    #+#             */
/*   Updated: 2023/10/13 01:44:39 by fwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45), _target("Default") {
	std::cout << "Default constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45), _target(target) {
	std::cout << "Parametric constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& copy) : AForm(copy), _target(copy._target) {
	std::cout << "Copy constructor called" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm() {
	std::cout << "Destructor called" << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &copy) {
	std::cout << "Assignation operator called" << std::endl;
	if (this != &copy)
	{
		AForm::operator=(copy);
		this->_target = copy._target;
	}
	return (*this);
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const {
	if (this->_signed == false)
		throw AForm::NotSignedException();
	else if (executor.getGrade() > this->_gradeToExecute)
		throw Bureaucrat::GradeTooLowException();
		
	// Seed the random number generator with the current time
    std::srand(static_cast<unsigned int>(std::time(0)));

	// Generate a random integer between 0 and RAND_MAX
	int random_number = std::rand();

	// Check if the random number is even for a 50% chance

	if (random_number % 2 == 0) {
		std::cout << _target << " has been robotomized" << std::endl;
	} else {
		std::cout << "Robotomy failed" << std::endl;
	}
	
}

