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

#pragma once

#include <iostream>
#include <string>

class AAnimal {
	
	public:
		AAnimal();
		AAnimal(const AAnimal &copy);
		virtual ~AAnimal();

		AAnimal &operator=(const AAnimal &copy);

		std::string		getType() const;
		virtual void	makeSound() const = 0;

	protected:
		std::string	_type;
};
