/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwong <fwong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 16:33:36 by fwong             #+#    #+#             */
/*   Updated: 2023/11/22 21:38:49 by fwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <iostream>
#include <stack>
#include "colors.hpp"

template<typename T, typename Y = std::deque<T> >

class	MutantStack : public std::stack<T, Y> {
	public:
		MutantStack() : std::stack<T, Y>() {};
		MutantStack(const MutantStack &copy) : std::stack<T, Y>(copy) {};
		virtual	~MutantStack() {};

		typedef typename Y::iterator iterator;
		typedef typename Y::const_iterator const_iterator;
		
		iterator	begin() { return this->c.begin(); }
		iterator	end() { return this->c.end(); }
		const_iterator	begin() const { return this->c.begin(); }
		const_iterator	end() const { return this->c.end(); }

		
	private:
		std::stack<T, Y>	_stack;
};

#endif