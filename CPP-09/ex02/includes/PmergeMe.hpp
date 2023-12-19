/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwong <fwong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 21:48:32 by fwong             #+#    #+#             */
/*   Updated: 2023/12/19 03:07:55 by fwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <fstream>
# include <string>
# include <sstream>
# include <deque>
# include <vector>
# include <ctime>
# include <algorithm>

class	PmergeMe {
	public:
		PmergeMe();
		PmergeMe(const PmergeMe &rhs);
		~PmergeMe();

		PmergeMe	&operator=(const PmergeMe &rhs);
		
		std::vector<int>	getVec() const;
		std::deque<int>		getDeq() const;
		float				getVecTime() const;
		float				getDeqTime() const;
		void	parseInput(int argc, char **argv);
		template <typename T>
		void	printContainer(T container) {
			for (size_t i = 0; i < container.size(); i++)
				std::cout << container[i] << " ";
			std::cout << std::endl;
			return ;
		}
		void	fordJohnson_v(std::vector<int> vec);
		void	fordJohnson_d(std::deque<int> deq);
		void	mergeSort_v(int low, int high);
		void	mergeSort_d(int low, int high);
		void	printTime_vec();
		void	printTime_deq();

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