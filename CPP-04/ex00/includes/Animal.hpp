/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwong <fwong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 15:25:45 by fwong             #+#    #+#             */
/*   Updated: 2023/07/12 15:25:45 by fwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include <string>

class Animal {
	
	public:
		Animal();
		Animal(const Animal &copy);
		virtual ~Animal();

		Animal &operator=(const Animal &copy);

		std::string		getType() const;
		virtual void	makeSound() const;

	protected:
		std::string	_type;
};

#endif