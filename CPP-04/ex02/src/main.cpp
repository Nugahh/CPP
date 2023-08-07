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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfremond <jfremond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 02:57:23 by jfremond          #+#    #+#             */
/*   Updated: 2022/09/13 03:00:10 by jfremond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"
#include "Brain.hpp"

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
	std::cout << RED << "Test 1 : Create and fill an array of Animal objects." << std::endl;
	std::cout << "Half of them are Dog objects, the other half are Cat objects." << RESET << std::endl << std::endl;
	
	AAnimal	*array[10];
	std::cout << ORANGE << "Construction of the array" << RESET << std::endl;
	for (int i = 0; i < 10; i++)
	{
		std::cout << YELLOW << "ANIMAL " << i + 1 << " : " << RESET << std::endl;
		if (i % 2)
			array[i] = new Cat;
		else
			array[i] = new Dog;
	}

	std::cout << std::endl;
	std::cout << ORANGE << "Calling the makeSound function" << RESET << std::endl;
	for (int i = 0; i < 10; i++)
	{
		std::cout << YELLOW << "ANIMAL " << i + 1 << " : " << RESET;
		std::cout << array[i]->getType() << " goes ";
		array[i]->makeSound();
	}
	
	std::cout << std::endl;
	std::cout << ORANGE << "Destruction of the array" << RESET << std::endl;
	for (int i = 0; i < 10; i++)
	{
		std::cout << YELLOW << "ANIMAL " << i + 1 << " : " << RESET << std::endl;
		delete array[i];
	}
	std::cout << std::endl;
	std::cout << RED << "Test 2 : Test that the copies are deep copies" << RESET << std::endl;
	{
		std::cout << std::endl;
		std::cout << ORANGE << "DOG assignment operator overload" << RESET << std::endl;	
		Dog	dog;
		Dog	cpy = dog;
		std::cout << YELLOW << "Dog Ideas" << RESET << std::endl;
		std::cout << "dog: " << dog.getIdea(0) << std::endl;
		std::cout << "cpy: " << dog.getIdea(0) << std::endl;
		std::cout << GREEN << "Setting the Dog Idea" << RESET << std::endl;
		dog.setIdea("I am a cute little dog 🐶", 0);
		std::cout << YELLOW << "Dog Ideas" << RESET << std::endl;
		std::cout << "dog: " << dog.getIdea(0) << std::endl;
		std::cout << "cpy: " << cpy.getIdea(0) << std::endl << std::endl;
	}
	{
		std::cout << std::endl;
		std::cout << ORANGE << "DOG construction by copy" << RESET << std::endl;	
		Dog	dog;
		Dog	cpy(dog);
		std::cout << YELLOW << "Dog Ideas" << RESET << std::endl;
		std::cout << "dog: " << dog.getIdea(0) << std::endl;
		std::cout << "cpy: " << dog.getIdea(0) << std::endl;
		std::cout << GREEN << "Setting the Dog Idea" << RESET << std::endl;
		dog.setIdea("I am a cute little dog 🐶", 0);
		std::cout << YELLOW << "Dog Ideas" << RESET << std::endl;
		std::cout << "dog: " << dog.getIdea(0) << std::endl;
		std::cout << "cpy: " << cpy.getIdea(0) << std::endl << std::endl;
	}
	{
		std::cout << std::endl;
		std::cout << ORANGE << "CAT assignment operator overload" << RESET << std::endl;	
		Cat	cat;
		Cat	cpy = cat;
		std::cout << YELLOW << "Cat Ideas" << RESET << std::endl;
		std::cout << "cat: " << cat.getIdea(0) << std::endl;
		std::cout << "cpy: " << cpy.getIdea(0) << std::endl;
		std::cout << GREEN << "Setting the Cat Idea" << RESET << std::endl;
		cat.setIdea("I am a cute little cat 🐱", 0);
		std::cout << YELLOW << "Cat Ideas" << RESET << std::endl;
		std::cout << "cat: " << cat.getIdea(0) << std::endl;
		std::cout << "cpy: " << cpy.getIdea(0) << std::endl << std::endl;
	}
	{
		std::cout << std::endl;
		std::cout << ORANGE << "CAT construction by copy" << RESET << std::endl;	
		Cat	cat;
		Cat	cpy(cat);
		std::cout << YELLOW << "Cat Ideas" << RESET << std::endl;
		std::cout << "cat: " << cat.getIdea(0) << std::endl;
		std::cout << "cpy: " << cpy.getIdea(0) << std::endl;
		std::cout << GREEN << "Setting the Cat Idea" << RESET << std::endl;
		cat.setIdea("I am a cute little cat 🐱", 0);
		std::cout << YELLOW << "Cat Ideas" << RESET << std::endl;
		std::cout << "cat: " << cat.getIdea(0) << std::endl;
		std::cout << "cpy: " << cpy.getIdea(0) << std::endl << std::endl;
	}
	return (0);
}