/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwong <fwong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 21:48:32 by fwong             #+#    #+#             */
/*   Updated: 2023/12/06 18:34:21 by fwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <string>
# include <iomanip>
# include <sstream>
# include <ctime>
# include <cstdlib>
# include <cctype>
# include <cmath>
# include <exception>
# include <cstddef>
# include <map>
# include <fstream>
# include <list>
# include <stack>

class	RPN {
	public:
		RPN();
		RPN(const RPN &rhs);
		~RPN();

		RPN		&operator=(const RPN &rhs);

		bool		isNumber(const std::string& s);
		void		readInput(const std::string &input);
		void 		reversePolishNotation();
		
		private:
			std::stack<float>	_stack;
};

#endif