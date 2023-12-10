/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwong <fwong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 21:48:32 by fwong             #+#    #+#             */
/*   Updated: 2023/12/10 17:56:04 by fwong            ###   ########.fr       */
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
# include <deque>
# include <vector>

class	PmergeMe {
	public:
		PmergeMe();
		PmergeMe(const PmergeMe &rhs);
		~PmergeMe();

		PmergeMe	&operator=(const PmergeMe &rhs);
		
		template<typename T>
		T		makePairs(T& container);
		

	private:
		std::vector<int>		_vec;
		std::deque<int>			_deq;
		size_t					_size;
		int						_odd;
		float					_vecTime;
		float					_deqTime;
};

#endif