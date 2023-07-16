/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwong <fwong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 17:36:48 by fwong             #+#    #+#             */
/*   Updated: 2023/07/12 17:36:48 by fwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>
#include <string>

class WrongAnimal {
	
	public:
		WrongAnimal();
		WrongAnimal(const WrongAnimal &copy);
		virtual ~WrongAnimal();

		WrongAnimal &operator=(const WrongAnimal &copy);

		std::string		getType() const;
		void			makeSound() const;

	protected:
		std::string	_type;
};

#endif