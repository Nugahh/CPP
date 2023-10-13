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
#include "../includes/aanimal.hpp"

int main() {

	// AAnimal *animal = new AAnimal();

	// animal->makeSound();

	AAnimal *cat = new Cat();

	cat->makeSound();
	return 0;
}