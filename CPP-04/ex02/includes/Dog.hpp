/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwong <fwong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 15:32:06 by fwong             #+#    #+#             */
/*   Updated: 2023/07/12 15:32:06 by fwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"

class Dog : public AAnimal {
	
	public:
		Dog();
		Dog(const Dog &copy);
		~Dog();

		Dog &operator=(const Dog &copy);

		void	makeSound() const;
	
	private:
		Brain *_brain;
};

#endif