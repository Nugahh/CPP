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

#include "../includes/dog.hpp"
#include "../includes/cat.hpp"
#include "../includes/wrongCat.hpp"

int main() {
		
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();
	
	std::cout << std::endl;

	const WrongAnimal* tata = new WrongAnimal();
	const WrongAnimal* y = new WrongCat();

	std::cout << y->getType() << " " << std::endl;
	y->makeSound(); //will output the wrong cat sound!
	tata->makeSound();

	delete meta, delete j, delete i, delete tata, delete y;
	
	return 0;
}