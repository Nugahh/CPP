/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwong <fwong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 14:03:43 by fwong             #+#    #+#             */
/*   Updated: 2023/12/19 03:02:22 by fwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int argc, char **argv) {
	PmergeMe p;

	p.parseInput(argc, argv);
	std::cout << "Before: ";
	p.printVec(p.getVec());
	p.printTime_vec();
	p.printTime_deq();
	std::cout << "Time to process a range of "
				<< argc - 1 
				<< " elements with std::vector: "
				<< p.getVecTime()
				<< " ms"
				<< std::endl;
	std::cout << "Time to process a range of "
				<< argc - 1 << " elements with std::deque: " 
				<< p.getDeqTime()
				<< " ms"
				<< std::endl;
}