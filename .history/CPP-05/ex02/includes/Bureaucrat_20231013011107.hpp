/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwong <fwong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 17:37:14 by fwong             #+#    #+#             */
/*   Updated: 2023/10/13 01:11:07 by fwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <exception>
#include <string>
#include <ctime>
#include <fstream>
#include <stdlib.h>
#include "AForm.hpp"
#include "colors.hpp"

class AForm;
class Bureaucrat {
	
	public:
		Bureaucrat();
		Bureaucrat(const Bureaucrat &copy);
		Bureaucrat(std::string name, int grade);
		virtual ~Bureaucrat();

		Bureaucrat& operator=(const Bureaucrat &copy);
		
		std::string		getName() const;
		int				getGrade() const;
		void			incrementGrade();
		void			decrementGrade();

		void			signForm(Bureaucrat &br);
		bool			executeForm(AForm const & form) const;

		class GradeTooHighException : public std::exception {
			const char *what() const throw();
		};

		class GradeTooLowException : public std::exception {
			const char *what() const throw();
		};

		class NotSignedException : public std::exception {
			const char *what() const throw();
		};

	private:
		const std::string	_name;
		int					_grade;
};

std::ostream& operator<<(std::ostream &out, Bureaucrat& src);

#endif