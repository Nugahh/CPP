/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwong <fwong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 12:46:08 by fwong             #+#    #+#             */
/*   Updated: 2023/10/13 01:23:35 by fwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include "Bureaucrat.hpp"


class Bureaucrat;

class AForm {
	
	public:
		AForm();
		AForm(const AForm& copy);
		AForm(std::string name, int gradeToExecute, int gradeToSign);
		virtual ~AForm();

		AForm& operator=(const AForm &copy);

		std::string		getName() const;
		int				getGradeToExecute() const;
		int				getGradeToSign() const;
		bool			isSigned() const;

		virtual void	execute(Bureaucrat const & executor) const = 0;

		class GradeTooHighException : public std::exception {
			const char *what() const throw();
		};
		
		class GradeTooLowException : public std::exception {
			const char *what() const throw();
		};

		class NotSignedException : public std::exception {
			const char *what() const throw();
		};

	protected:
		const std::string	_name;
		const int			_gradeToExecute; // 1 is highest, 150 is lowest
		const int			_gradeToSign;
		bool				_signed;
		
};

std::ostream& operator<<(std::ostream &out, AForm& src);

#endif