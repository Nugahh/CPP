/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwong <fwong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 23:00:44 by fwong             #+#    #+#             */
/*   Updated: 2023/09/23 02:11:04 by fwong            ###   ########.fr       */
/*   CPPKENNY/CPP05/ex00/inc/colors.hpp
                                                                        */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <exception>
#include <string>
#include "colors.hpp"

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

		class GradeTooHighException : public std::exception {
			public:	
				void error() const throw() {
					std::cout << "Grade is too high" << std::endl;
				}
		};
		class GradeTooLowException : public std::exception {
			public:
				void error() const throw() {
					std::cout << "Grade is too low" << std::endl;
				}
		};

	private:
		const std::string	_name;
		int					_grade;
};

std::ostream& operator<<(std::ostream &out, Bureaucrat& src);

#endif