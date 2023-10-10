/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwong <fwong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 12:46:08 by fwong             #+#    #+#             */
/*   Updated: 2023/10/09 23:07:56 by fwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"

class Form {
	
	public:
		Form();
		Form(const Form& copy);
		Form(std::string name, int gradeToExecute, int gradeToSign);
		virtual ~Form();
		
		Form& operator=(const Form &copy);

		std::string		getName() const;
		int				getGradeToExecute() const;
		int				getGradeToSign() const;
		bool			isSigned() const;
		void			beSigned(Bureaucrat &br);

		class GradeTooHighException : public std::exception {
			const char *what() const throw();
		};
		
		class GradeTooLowException : public std::exception {
			const char *what() const throw();
		};

	private:
		const std::string	_name;
		const int			_gradeToExecute; // 1 is highest, 150 is lowest
		const int			_gradeToSign;
		bool				_signed;
		
};

std::ostream& operator<<(std::ostream &out, Form& src);

#endif