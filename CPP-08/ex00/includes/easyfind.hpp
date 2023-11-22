/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwong <fwong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 16:33:36 by fwong             #+#    #+#             */
/*   Updated: 2023/11/22 19:21:46 by fwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include "colors.hpp"

template<typename T>
void easyfind(T& container, int n) {
	typename T::iterator it = std::find(container.begin(), container.end(), n);
	if (it != container.end())
		std::cout << "Found " << GRN << n << RESET << " in container" << std::endl;
	else
		std::cout << "Can´t find " << RED << n << RESET << " in container" << std::endl;
}

#endif