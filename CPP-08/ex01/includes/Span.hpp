/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwong <fwong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 16:33:36 by fwong             #+#    #+#             */
/*   Updated: 2023/11/22 19:48:51 by fwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include "colors.hpp"

class	Span {
	public:
		Span();
		Span(unsigned int N);
		Span(const Span &copy);
		~Span();

		Span &operator=(const Span &rhs);

		void	addNumber(int nb);
		void	addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end);
		int		shortestSpan();
		int		longestSpan();

		class	MaxN : public std::exception {
			public:
				virtual const char* what() const throw() {
					return "Max number of elements reached";
				}
		};
		class	NoSpan : public std::exception {
			public:
				virtual const char* what() const throw() {
					return "Not enough elements to find a span";
				}
		};

	private:
		unsigned int		_N;
		std::vector<int>	array;
};

#endif