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
#include "../includes/animal.hpp"

int main() {

	int i = 0;
	Animal *animal[10];

	while (i < 10)
	{
		if (i < 5)
			animal[i] = new Dog();
		else
			animal[i] = new Cat();
		i++;
	}
	i = 0;
	while (i < 10)
	{
		delete animal[i];
		i++;
	}
	return 0;
}