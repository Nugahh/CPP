/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwong <fwong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 16:33:00 by fwong             #+#    #+#             */
/*   Updated: 2023/11/22 21:38:57 by fwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include "MutantStack.hpp"

int main() {
    std::cout << "-------------- MANDATORY MAIN WITH VECTOR-------------- " << std::endl;
    MutantStack<int, std::vector<int> > vectorStack;

    vectorStack.push(5);
    vectorStack.push(17);

    std::cout << "Last added value: " << vectorStack.top() << std::endl;
    vectorStack.pop();

    std::cout << "Size after one pop: " << vectorStack.size() << std::endl;

    vectorStack.push(3);
    vectorStack.push(5);
    vectorStack.push(737);
    vectorStack.push(0);

    std::cout << "Stack numbers (using vector): ";
    for (MutantStack<int, std::vector<int> >::iterator it = vectorStack.begin(); it != vectorStack.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    // Demonstrating copy constructor with vector
    MutantStack<int, std::vector<int> > s(vectorStack);
    std::cout << "\nA copy of vectorStack has been created" << std::endl;
    s.push(1);
    s.push(-14);

    std::cout << "Updated size: " << s.size() << std::endl;
    std::cout << "Last added value: " << s.top() << std::endl;
    std::cout << "\nStack numbers in the copy: ";
    for (MutantStack<int, std::vector<int> >::iterator it = s.begin(); it != s.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    return 0;
}