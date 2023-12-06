/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwong <fwong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 14:03:43 by fwong             #+#    #+#             */
/*   Updated: 2023/12/06 18:47:09 by fwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int argc, char *argv[]) {
	
	if (argc != 2) {
		std::cout << "Usage: ./RPN \"8 9 * 9 - 9 - 9 - 4 - 1 +\"" << std::endl;
		return 1;
	}
	RPN rpn;
	rpn.readInput(argv[1]);
	// rpn.reversePolishNotation();
	return 0;
}