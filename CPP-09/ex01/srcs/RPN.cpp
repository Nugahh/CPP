/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwong <fwong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 17:46:17 by fwong             #+#    #+#             */
/*   Updated: 2023/12/06 20:21:54 by fwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN() {};

RPN::RPN(const RPN &rhs) {
	*this = rhs;
};

RPN::~RPN() {};

RPN		&RPN::operator=(const RPN &rhs) {
	if (this != &rhs) {
		_stack = rhs._stack;
	}
	return (*this);
};

bool 	RPN::isNumber(const std::string& s) {
        std::istringstream iss(s);
        float D;
        iss >> D;
        return (iss && iss.eof());
}

void	RPN::reversePolishNotation(const std::string &input) {
    std::istringstream iss(input);
    std::string s;
    while (iss >> s) {
        if (isNumber(s)) {
			std::istringstream converter(s);
			float num;
			if (converter >> num)
            	_stack.push(num);
        } else {
            char op = s[0]; // Assuming the first character uniquely identifies the operator
            if (_stack.size() < 2) {
                std::cout << "Invalid input" << std::endl;
                return;
            }
            float second = _stack.top();
            _stack.pop();
            float first = _stack.top();
            _stack.pop();

            switch (op) {
                case '+':
                    _stack.push(first + second);
                    break;
                case '-':
                    _stack.push(first - second);
                    break;
                case '*':
                    _stack.push(first * second);
                    break;
                case '/':
                    _stack.push(first / second);
                    break;
                default:
                    std::cout << "Invalid input" << std::endl;
                    return;
            }
        }
    }
	if (_stack.size() != 1) {
		std::cout << "Invalid input" << std::endl;
		return;
	}
	std::cout << _stack.top() << std::endl;
}