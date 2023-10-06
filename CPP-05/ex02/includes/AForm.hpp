/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwong <fwong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 12:46:08 by fwong             #+#    #+#             */
/*   Updated: 2023/10/06 17:48:29 by fwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include "Bureaucrat.hpp"

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
		void			beSigned(Bureaucrat &br);

		virtual void	execute(Bureaucrat const & executor) const = 0;

		class GradeTooHighException : public std::exception {
			public:	
				virtual void error() const throw() {
					std::cout << "Grade is too high" << std::endl;
				}
		};
		
		class GradeTooLowException : public std::exception {
			public:
				virtual void error() const throw() {
					std::cout << "Grade is too low" << std::endl;
				}
		};

		class NotSignedException : public std::exception {
			public:
				virtual void error() const throw() {
					std::cout << "Form is not signed" << std::endl;
				}
		};

	private:
		const std::string	_name;
		const int			_gradeToExecute; // 1 is highest, 150 is lowest
		const int			_gradeToSign;
		bool				_signed;
		
};

std::ostream& operator<<(std::ostream &out, AForm& src);

#endif