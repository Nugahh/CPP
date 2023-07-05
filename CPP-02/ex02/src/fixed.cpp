/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwong <fwong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 18:33:39 by fwong             #+#    #+#             */
/*   Updated: 2023/07/05 00:03:50 by fwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Fixed.hpp"

/* ------------------- Constructors ------------------- */

Fixed::Fixed() : _fixedPointValue(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(int const value) {
	std::cout << "Int constructor called" << std::endl;
	this->_fixedPointValue = value << _fractionalBits;
}

Fixed::Fixed(float const fl) {
	std::cout << "Float constructor called" << std::endl;
	this->_fixedPointValue = roundf(fl * (1 << _fractionalBits));
}

/* ------------------- Copy Constructors ------------------- */

Fixed::Fixed(const Fixed &copy) {
	std::cout << "Copy constructor called" << std::endl;
	*this = copy;
}

/* ------------------- Destructors ------------------- */

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

/* ------------------- Getters/Setters ------------------- */

int Fixed::getRawBits() const {
	std::cout << "getRawBits member function called" << std::endl;
	return this->_fixedPointValue;
}

void Fixed::setRawBits(int const raw) {
	this->_fixedPointValue = raw;
}

/* ------------------- Convertors ------------------- */

int Fixed::toInt() const {
	return (this->_fixedPointValue >> _fractionalBits);
}

float Fixed::toFloat() const {
	return ((float)this->_fixedPointValue / (float)(1 << _fractionalBits));
}

/* ------------------- Affection Operators ------------------- */

Fixed &Fixed::operator=(const Fixed &fixed) {
	std::cout << "Copy assignment operator called" << std::endl;
	this->_fixedPointValue = fixed.getRawBits();
	return *this;
}

/* ------------------- De/Incremenation Operators ------------------- */

Fixed &Fixed::operator++() {
	this->_fixedPointValue++;
	return *this;
}

Fixed &Fixed::operator--() {
	this->_fixedPointValue--;
	return *this;
}

Fixed Fixed::operator++(int) {
	Fixed tmp = *this;
	++(*this);
	return tmp;
}

Fixed Fixed::operator--(int) {
	Fixed tmp = *this;
	--(*this);
	return tmp;
}

/* ------------------- Arithmetic Operators ------------------- */

Fixed Fixed::operator+(Fixed const &src) const {
	return this->toFloat() + src.toFloat();
}

Fixed Fixed::operator-(Fixed const &src) const {
	return this->toFloat() - src.toFloat();
}

Fixed Fixed::operator*(Fixed const &src) const {
	return this->toFloat() * src.toFloat();
}

Fixed Fixed::operator/(Fixed const &src) const {
	return this->toFloat() / src.toFloat();
}

/* ------------------- Comparison Operators ------------------- */

bool Fixed::operator>(Fixed const &src) const {
	return this->toFloat() > src.toFloat();
}

bool Fixed::operator<(Fixed const &src) const {
	return this->toFloat() < src.toFloat();
}

bool Fixed::operator>=(Fixed const &src) const {
	return this->toFloat() >= src.toFloat();
}

bool Fixed::operator<=(Fixed const &src) const {
	return this->toFloat() <= src.toFloat();
}

bool Fixed::operator==(Fixed const &src) const {
	return this->toFloat() == src.toFloat();
}

bool Fixed::operator!=(Fixed const &src) const {
	return this->toFloat() != src.toFloat();
}

Fixed Fixed::min(Fixed &a, Fixed &b) {
	return (a < b) ? a : b;
}

Fixed Fixed::min(Fixed const &a, Fixed const &b) {
	return (a < b) ? a : b;
}

Fixed Fixed::max(Fixed &a, Fixed &b) {
	return (a > b) ? a : b;
}

Fixed Fixed::max(Fixed const &a, Fixed const &b) {
	return (a > b) ? a : b;
}

std::ostream& operator<<(std::ostream &flux, Fixed const &src) {
	flux << src.toFloat();
	return flux;
}