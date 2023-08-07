/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwong <fwong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 15:59:26 by fwong             #+#    #+#             */
/*   Updated: 2023/07/12 15:59:26 by fwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

#define RESET   "\033[0m"
#define BLACK   "\033[30m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define ORANGE  "\033[38;2;255;165;0m"

int	main(void)
{
	const Animal *meta = new Animal();
	const Animal *c = new Cat();
	const Animal *d = new Dog();

	std::cout << std::endl;
	std::cout << ORANGE << "TESTING DYNAMIC LINKAGE" << RESET << std::endl;
	std::cout << "I am an " <<  meta->getType() << std::endl;
	std::cout << "I am a " << c->getType() << std::endl;
	std::cout << "I am a " << d->getType() << std::endl;

	std::cout << std::endl;
	meta->makeSound();
	std::cout << "Cat goes "; c->makeSound();
	std::cout << "Dog goes "; d->makeSound();
	
	std::cout << std::endl;
	delete meta;
	delete c;
	delete d;

	std::cout << std::endl;
	const WrongAnimal	*Wmeta = new WrongAnimal();
	const WrongAnimal	*Wcat = new WrongCat();
	const WrongCat		*Rcat = new WrongCat();
	
	std::cout << std::endl;
	std::cout << ORANGE << "TESTING STATIC LINKAGE" << RESET << std::endl;
	std::cout << "I am a " << Wmeta->getType() << std::endl;
	std::cout << "I am a " << Wcat->getType() << std::endl;
	std::cout << "I am a " << Rcat->getType() << std::endl;

	std::cout << std::endl;
	Wmeta->makeSound();
	Wcat->makeSound();
	Rcat->makeSound();
	
	std::cout << std::endl;
	delete Wmeta;
	delete Wcat;
	delete Rcat;
	return (0);
}