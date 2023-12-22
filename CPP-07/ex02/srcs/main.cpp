/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwong <fwong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 16:33:00 by fwong             #+#    #+#             */
/*   Updated: 2023/12/22 17:14:54 by fwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "array.hpp"

int main() {
	std::cout << "Enter array size : ";
	unsigned int n;
	std::cin >> n;
	if (std::cin.fail())
		return (std::cout << "invalid input" << std::endl, 1);
	Array<int> arrayOfInt(n);
	std::cout << std::endl;
	std::cout << "Creating an array of size " << n << " ..." << std::endl;
	
	for (unsigned int i = 0; i < n; i++)
	{
		try
		{	std::cout << "array[" << i << "] = " << arrayOfInt[i] << std::endl;}
		catch(const std::exception &e)
		{	std::cerr << e.what() << std::endl;}
	}
	std::cout << std::endl;
	std::cout << "Fill array...." << std::endl;
	for (unsigned int i = 0; i < n; i++)
	{
		unsigned int a;
		std::cout << "Enter array[" << i << "] = ";
		std::cin >> a;
		if (std::cin.fail())
			return (std::cout << "invalid input" << std::endl, 1);
		arrayOfInt[i] = a;
	}
	std::cout << std::endl;
	std::cout << "Filled array" << std::endl;
	for (unsigned int i = 0; i <= n; i++)
	{
		try {
			std::cout << "array[" << i << "] = " << arrayOfInt[i] << std::endl;
		} catch (const Array<int>::Outofbounds &e) {
			std::cout << e.what() << std::endl;
		}
	}
	std::cout << std::endl;
	std::cout << "Array size = " << arrayOfInt.size() << std::endl;

    std::cout << "Enter array size: ";
    n = 0;
    std::cin >> n;
    if (std::cin.fail()) {
        std::cout << "Invalid input" << std::endl;
        return 1;
    }
    
    Array<std::string> arrayOfString(n); // Use std::string for array type

    std::cout << std::endl;
    std::cout << "Creating an array of size " << n << " ..." << std::endl;

    for (unsigned int i = 0; i < n; i++) {
        try {
            std::cout << "array[" << i << "] = " << arrayOfString[i] << std::endl;
        } catch (const Array<std::string>::Outofbounds &e) {
            std::cout << e.what() << std::endl;
        }
    }

    std::cout << std::endl;
    std::cout << "Fill array...." << std::endl;
    
    for (unsigned int i = 0; i < n; i++) {
        std::string str;
        std::cout << "Enter array[" << i << "] = ";
        std::cin >> str;
        if (std::cin.fail()) {
            std::cout << "Invalid input" << std::endl;
            return 1;
        }
        arrayOfString[i] = str;
    }

    std::cout << std::endl;
    std::cout << "Filled array" << std::endl;

    for (unsigned int i = 0; i < n; i++) {
        try {
            std::cout << "array[" << i << "] = " << arrayOfString[i] << std::endl;
        } catch (const Array<std::string>::Outofbounds &e) {
            std::cout << e.what() << std::endl;
        }
    }

    std::cout << std::endl;
    std::cout << "Array size = " << arrayOfString.size() << std::endl;

    return 0;
}
