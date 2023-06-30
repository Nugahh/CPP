/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwong <fwong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 18:32:51 by fwong             #+#    #+#             */
/*   Updated: 2023/06/30 19:39:09 by fwong            ###   ########.fr       */
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

		int 	getRawBits() const;
		void 	setRawBits(int const raw);
		int 	toInt() const;
		float 	toFloat() const;

	private:
		int 				_fixedPointValue;
		static const int 	_fractionalBits = 8;
};

std::ostream& operator<<(std::ostream &flux, Fixed const& src);

#endif