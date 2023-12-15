/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwong <fwong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 21:48:32 by fwong             #+#    #+#             */
/*   Updated: 2023/12/13 15:41:56 by fwong            ###   ########.fr       */
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
# include <algorithm>

class	PmergeMe {
	public:
		PmergeMe();
		PmergeMe(const PmergeMe &rhs);
		~PmergeMe();

		PmergeMe	&operator=(const PmergeMe &rhs);
		
		void	parseInput(int argc, char **argv);
		void	makePairsAndSort_v(std::vector<int> vec);
		void	makePairsAndSort_d(std::deque<int> deq);
		void	mergeSort_v(int low, int high);
		void	mergeSort_d(int low, int high);
		

	private:
		std::vector<int>						_vec;
		std::vector<int>						_vecLow;
		std::vector<std::pair<int, int> >		_vecPairs;
		std::deque<int>							_deq;
		std::deque<int>							_deqLow;
		std::deque<std::pair<int, int> >		_deqPairs;
		int										_odd;
		float									_vecTime;
		float									_deqTime;
};

#endif