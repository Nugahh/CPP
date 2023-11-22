/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwong <fwong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 16:33:36 by fwong             #+#    #+#             */
/*   Updated: 2023/11/22 17:26:33 by fwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <exception>
#include <cstddef> // For size_t

template <typename T>
class Array {
	public:
		// Default constructor
		Array() : _elements(nullptr), _numElements(0) {}

		// Constructor with size
		Array(std::size_t n) : _elements(new T[n]()), _numElements(n) {}

		// Copy constructor
		Array(const Array& other) : _elements(new T[other._numElements]), _numElements(other._numElements) {
			for (std::size_t i = 0; i < _numElements; ++i) {
				_elements[i] = other._elements[i];
			}
		}

		// Copy assignment operator
		Array& operator=(const Array& other) {
			if (this != &other) {
				delete[] _elements;
				_elements = new T[other._numElements];
				_numElements = other._numElements;
				for (std::size_t i = 0; i < _numElements; ++i) {
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
		T& operator[](std::size_t index) {
			if (index >= _numElements) {
				throw std::exception();
			}
			return _elements[index];
		}

		const T& operator[](std::size_t index) const {
			if (index >= _numElements) {
				throw std::exception();
			}
			return _elements[index];
		}

		// Size of the array
		std::size_t size() const noexcept {
			return _numElements;
		}

	private:
		T* _elements;
		std::size_t _numElements;
};

#endif