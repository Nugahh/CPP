/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwong <fwong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 16:33:36 by fwong             #+#    #+#             */
/*   Updated: 2023/12/22 17:13:48 by fwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cctype>
#include <iostream>
#include <exception>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#ifndef ARRAY_HPP
#define ARRAY_HPP


template <typename T>
class Array {
	public:
		// Default constructor
		Array() : _elements(0), _numElements(0) {}

		// Constructor with size
		Array(unsigned int n) : _elements(new T[n]()), _numElements(n) {}

		// Copy constructor
		Array(const Array& other) : _elements(new T[other._numElements]), _numElements(other._numElements) {
			for (unsigned int i = 0; i < _numElements; ++i) {
				_elements[i] = other._elements[i];
			}
		}

		// Copy assignment operator
		Array& operator=(const Array& other) {
			if (this != &other) {
				delete[] _elements;
				_elements = new T[other._numElements];
				_numElements = other._numElements;
				for (unsigned int i = 0; i < _numElements; ++i) {
					_elements[i] = other._elements[i];
				}
			}
			return *this;
		}

		// Destructor
		~Array() {
			delete[] _elements;
		}

		// Subscript operator
		T& operator[](unsigned int index) {
			if (index >= _numElements) {
				throw Outofbounds();
			}
			return _elements[index];
		}
	
		class Outofbounds : public std::exception {
			public:
				const char *what() const throw() {
					return "Index is out of bounds";
				}
		};

		// Size of the array
		unsigned int size() const {
			return _numElements;
		}

	private:
		T* 				_elements;
		unsigned int 	_numElements;
};

#endif