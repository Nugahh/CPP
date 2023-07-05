/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwong <fwong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 18:32:51 by fwong             #+#    #+#             */
/*   Updated: 2023/07/04 23:46:59 by fwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <cmath>

class Fixed {
	
	public:
		Fixed();
		Fixed(Fixed const &fixedd);
		Fixed(int const value);
		Fixed(float const fl);
		~Fixed();
		
		Fixed &operator=(Fixed const &src);

		Fixed &operator++();
		Fixed &operator--();
		Fixed operator++(int);
		Fixed operator--(int);

		Fixed operator+(Fixed const &src) const;
		Fixed operator-(Fixed const &src) const;
		Fixed operator*(Fixed const &src) const;
		Fixed operator/(Fixed const &src) const;

		bool operator>(Fixed const &src) const;
		bool operator<(Fixed const &src) const;
		bool operator>=(Fixed const &src) const;
		bool operator<=(Fixed const &src) const;
		bool operator==(Fixed const &src) const;
		bool operator!=(Fixed const &src) const;
		
		int 	getRawBits() const;
		void 	setRawBits(int const raw);
		int 	toInt() const;
		float 	toFloat() const;

		static Fixed min(Fixed &a, Fixed &b);
		static Fixed min(Fixed const &a, Fixed const &b);
		static Fixed max(Fixed &a, Fixed &b);
		static Fixed max(Fixed const &a, Fixed const &b);
		
	private:
		int 				_fixedPointValue;
		static const int 	_fractionalBits = 8;
};

std::ostream& operator<<(std::ostream &flux, Fixed const& src);

#endif