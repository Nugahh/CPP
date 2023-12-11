/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwong <fwong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 17:46:17 by fwong             #+#    #+#             */
/*   Updated: 2023/12/11 18:58:02 by fwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe() : _odd(0), _vecTime(0), _deqTime(0) {}

PmergeMe::PmergeMe(const PmergeMe &rhs) {
	*this = rhs;
}

PmergeMe::~PmergeMe() {}

PmergeMe	&PmergeMe::operator=(const PmergeMe &rhs) {
	if (this != &rhs) {
		this->_vec = rhs._vec;
		this->_deq = rhs._deq;
		this->_odd = rhs._odd;
		this->_vecTime = rhs._vecTime;
		this->_deqTime = rhs._deqTime;
	}
	return (*this);
}

// For the Ford-Johnson/Merge-insert sort algorithm, we need to:
// [1] Make pairs of elements in the container
// If the container has an odd number of elements, the last element is ignored
// If the container has less than 2 elements, the container is returned unchanged
// If the container is empty, an empty container is returned
// [2] Sort the pairs
// [3] Sort the highest element of each pair
// [4] Put in 2 different containers the highest and lowest elements of each pair
// If it was odd, the last element is put in the lowest container (or the one not sorted)
// [5] Binary search in order to insert


bool compareBySecond(const std::pair<int, int>& a, const std::pair<int, int>& b) {
    return a.second < b.second;
}

static void printVec(std::vector<std::pair<int, int> > vec) {
	for (size_t i = 0; i < vec.size(); i++)
		std::cout << "[" << vec[i].first << " " << vec[i].second << "]" << std::endl;
	return ;
}

static void printVecLow(std::vector<int> vec) {
	for (size_t i = 0; i < vec.size(); i++)
		std::cout << "[" << vec[i] << "]" << std::endl;
	return ;
}

void	PmergeMe::parseInput(int argc, char **argv) {
	// if (argc == 1)
	// 	return (T());
	for (int i = 1; i < argc; i++) {
		std::stringstream ss(argv[i]);
		int n;
		if (!(ss >> n))
			return ;
		if (ss.peek() != EOF)
			return ;
		_vec.push_back(n);
		_deq.push_back(n);
	}
	makePairsAndSort_v(_vec);
	return ;
}

void	PmergeMe::makePairsAndSort_v(std::vector<int> vec) {
	if (vec.size() < 2)
		return ;
	if (vec.size() % 2 != 0)
		_odd = vec[vec.size() - 1];
	for (size_t i = 0; i < vec.size(); i += 2) {
		_vecPairs.push_back(std::make_pair(vec[i], vec[i + 1]));
	}
	_vec.clear();
	// sort pairs
	for (size_t i = 0; i < _vecPairs.size(); i++)
		if (_vecPairs[i].first > _vecPairs[i].second)
			std::swap(_vecPairs[i].first, _vecPairs[i].second);
	std::sort(_vecPairs.begin(), _vecPairs.end(), compareBySecond);
	printVec(_vecPairs);
	for (size_t i = 0; i < _vecPairs.size(); i++) {
		_vec.push_back(_vecPairs[i].first);
		_vecLow.push_back(_vecPairs[i].second);
	}
	printVecLow(_vec);
	std::cout << "-------------------------" << std::endl;
	printVecLow(_vecLow);
	return ;
}
