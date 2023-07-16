/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwong <fwong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 19:52:23 by fwong             #+#    #+#             */
/*   Updated: 2023/07/12 19:52:23 by fwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/brain.hpp"

Brain::Brain() {
	std::cout << "Brain default constructor called" << std::endl;
}

Brain::Brain(Brain const &copy) {
	std::cout << "Brain copy constructor called" << std::endl;
	*this = copy;
}

Brain::~Brain() {
	std::cout << "Brain destructor called" << std::endl;
}




