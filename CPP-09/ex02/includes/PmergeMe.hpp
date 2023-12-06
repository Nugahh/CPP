/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwong <fwong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 21:48:32 by fwong             #+#    #+#             */
/*   Updated: 2023/12/06 20:32:43 by fwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <string>
# include <iomanip>
# include <sstream>
# include <ctime>
# include <cstdlib>
# include <cctype>
# include <cmath>
# include <exception>
# include <cstddef>
# include <map>
# include <fstream>
# include <list>
# include <stack>

class	PmergeMe {
	public:
		PmergeMe();
		PmergeMe(const PmergeMe &rhs);
		~PmergeMe();

		PmergeMe	&operator=(const PmergeMe &rhs);
		

};

#endif