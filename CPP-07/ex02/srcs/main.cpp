/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwong <fwong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 16:33:00 by fwong             #+#    #+#             */
/*   Updated: 2023/11/22 17:10:00 by fwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

template<typename T>
void	print(T const & x) {
	std::cout << x;
}

int main( void ) {
	int intArray[5] = {1, 2, 3, 4, 5};
	char charArray[5] = {'a', 'b', 'c', 'd', 'e'};

	std::cout << "intArray: ";
	iter(intArray, 5, print);
	std::cout << std::endl;
	std::cout << "charArray: ";
	iter(charArray, 5, print);
	std::cout << std::endl;
	return 0;
}