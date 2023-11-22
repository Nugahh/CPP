/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwong <fwong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 19:46:31 by fwong             #+#    #+#             */
/*   Updated: 2023/11/22 19:56:49 by fwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() : _N(0) {}

Span::Span(unsigned int N) : _N(N) {}

Span::Span(const Span &copy) {
	*this = copy;
}

Span::~Span() {}

Span &Span::operator=(const Span &rhs) {
	if (this != &rhs) {
		this->_N = rhs._N;
		this->array = rhs.array;
	}
	return *this;
}

void	Span::addNumber(int nb) {
	if (this->array.size() < this->_N)
		this->array.push_back(nb);
	else
		throw Span::MaxN();
}

void	Span::addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end) {
	if (this->array.size() + std::distance(begin, end) <= this->_N)
		this->array.insert(this->array.end(), begin, end);
	else
		throw Span::MaxN();
}

int		Span::shortestSpan() {
	if (this->array.size() < 2)
		throw Span::NoSpan();

	std::vector<int>	tmp = this->array;
	std::sort(tmp.begin(), tmp.end());

	int	min = tmp[1] - tmp[0];
	for (unsigned int i = 2; i < tmp.size(); i++) {
		if (tmp[i] - tmp[i - 1] < min)
			min = tmp[i] - tmp[i - 1];
	}
	return min;
}

int		Span::longestSpan() {
	if (this->array.size() < 2)
		throw Span::NoSpan();
	std::vector<int>	tmp = this->array;
	std::sort(tmp.begin(), tmp.end());
	return tmp[tmp.size() - 1] - tmp[0];
}