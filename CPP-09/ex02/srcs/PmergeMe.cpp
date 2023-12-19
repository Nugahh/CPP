/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwong <fwong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 17:46:17 by fwong             #+#    #+#             */
/*   Updated: 2023/12/19 03:08:19 by fwong            ###   ########.fr       */
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

std::vector<int>	PmergeMe::getVec() const { return (_vec); }

std::deque<int>		PmergeMe::getDeq() const { return (_deq); }

float				PmergeMe::getVecTime() const { return (_vecTime); }

float				PmergeMe::getDeqTime() const { return (_deqTime); }

template <typename T>
static void	printContainerPairs(T container) { 
	for (size_t i = 0; i < container.size(); i++)
		std::cout << "[" << container[i].first << " " << container[i].second << "]" << std::endl;
	return ;
}

void	PmergeMe::parseInput(int argc, char **argv) {
	if (argc < 2)
		return ;
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
	return ;
}

void	PmergeMe::mergeSort_v(int low, int high) {
	// check if low is smaller than high, if not the they container is sorted
	if (low < high) {
		// get the index of the element which is in the middle
		int mid = (low + high) / 2;
		// sort the left side of the container
		mergeSort_v(low, mid);
		// sort the right side of the container
		mergeSort_v(mid + 1, high);
		// combine them both
		std::vector<std::pair<int, int> > vecTemp;
		int i = low;
		int j = mid + 1;
		// copy the smallest values from either the left or the right side back
		// to the original container
		while (i <= mid && j <= high) {
			if (_vecPairs[i].second <= _vecPairs[j].second) 
				vecTemp.push_back(_vecPairs[i++]);
			else
				vecTemp.push_back(_vecPairs[j++]);
		}
		while (i <= mid)
			vecTemp.push_back(_vecPairs[i++]);
		while (j <= high)
			vecTemp.push_back(_vecPairs[j++]);
		// copy the values from the temporary container back to the original container
		for (int i = low; i <= high; i++)
			_vecPairs[i] = vecTemp[i - low];
	}
	return ;	
}

void	PmergeMe::fordJohnson_v(std::vector<int> vec) {
	bool isOdd = false;
	if (vec.size() < 2)
		return ;
	if (vec.size() % 2 != 0) {
		isOdd = true;
		_odd = vec[vec.size() - 1];
		for (size_t i = 0; i < vec.size() - 1; i += 2) {
			_vecPairs.push_back(std::make_pair(vec[i], vec[i + 1]));
		}
	} else {
		for (size_t i = 0; i < vec.size(); i += 2) {
			_vecPairs.push_back(std::make_pair(vec[i], vec[i + 1]));
		}
	}
	_vec.clear();
	// sort pairs
	for (size_t i = 0; i < _vecPairs.size(); i++)
		if (_vecPairs[i].first > _vecPairs[i].second)
			std::swap(_vecPairs[i].first, _vecPairs[i].second);
	mergeSort_v(0, _vecPairs.size() - 1);
	for (size_t i = 0; i < _vecPairs.size(); i++) {
		_vecLow.push_back(_vecPairs[i].first);
		_vec.push_back(_vecPairs[i].second);
	}
	if (isOdd)
		_vecLow.push_back(_odd);
	// binary search in _vecHigh and insert _vecLow[i] in _vec
	for (unsigned long i = 0; i < _vecLow.size(); i++) {
		int low = 0;
		int high = _vec.size() - 1;
		int mid = 0;
		while (low <= high) {
			mid = (low + high) / 2;
			if (_vecLow[i] > _vec[mid])
				low = mid + 1;
			else if (_vecLow[i] < _vec[mid])
				high = mid - 1;
			else
				break ;
		}
		 int insertionIndex = (low > high) ? low : mid;
		_vec.insert(_vec.begin() + insertionIndex, _vecLow[i]);
	}
	return ;
}

void	PmergeMe::mergeSort_d(int low, int high) {
	// check if low is smaller than high, if not the they container is sorted
	if (low < high) {
		// get the index of the element which is in the middle
		int mid = (low + high) / 2;
		// sort the left side of the container
		mergeSort_d(low, mid);
		// sort the right side of the container
		mergeSort_d(mid + 1, high);
		// combine them both
		std::deque<std::pair<int, int> > deqTemp;
		int i = low;
		int j = mid + 1;
		// copy the smallest values from either the left or the right side back
		// to the original container
		while (i <= mid && j <= high) {
			if (_deqPairs[i].second <= _deqPairs[j].second) 
				deqTemp.push_back(_deqPairs[i++]);
			else
				deqTemp.push_back(_deqPairs[j++]);
		}
		while (i <= mid)
			deqTemp.push_back(_deqPairs[i++]);
		while (j <= high)
			deqTemp.push_back(_deqPairs[j++]);
		// copy the values from the temporary container back to the original container
		for (int i = low; i <= high; i++)
			_deqPairs[i] = deqTemp[i - low];
	}
	return ;	
}

void	PmergeMe::fordJohnson_d(std::deque<int> deq) {
	bool isOdd = false;
	if (deq.size() < 2)
		return ;
	if (deq.size() % 2 != 0) {
		isOdd = true;
		_odd = deq[deq.size() - 1];
		for (size_t i = 0; i < deq.size() - 1; i += 2) {
			_deqPairs.push_back(std::make_pair(deq[i], deq[i + 1]));
		}
	} else {
		for (size_t i = 0; i < deq.size(); i += 2) {
			_deqPairs.push_back(std::make_pair(deq[i], deq[i + 1]));
		}
	}
	_deq.clear();
	// sort pairs
	for (size_t i = 0; i < _deqPairs.size(); i++)
		if (_deqPairs[i].first > _deqPairs[i].second)
			std::swap(_deqPairs[i].first, _deqPairs[i].second);
	mergeSort_d(0, _deqPairs.size() - 1);
	for (size_t i = 0; i < _deqPairs.size(); i++) {
		_deqLow.push_back(_deqPairs[i].first);
		_deq.push_back(_deqPairs[i].second);
	}
	if (isOdd)
		_deqLow.push_back(_odd);
	// binary search in _deqHigh and insert _deqLow[i] in _deq
	for (unsigned long i = 0; i < _deqLow.size(); i++) {
		int low = 0;
		int high = _deq.size() - 1;
		int mid = 0;
		while (low <= high) {
			mid = (low + high) / 2;
			if (_deqLow[i] > _deq[mid])
				low = mid + 1;
			else if (_deqLow[i] < _deq[mid])
				high = mid - 1;
			else
				break ;
		}
		 int insertionIndex = (low > high) ? low : mid;
		_deq.insert(_deq.begin() + insertionIndex, _deqLow[i]);
	}
	return ;
}

void	PmergeMe::printTime_vec() {
	clock_t start = clock();
	fordJohnson_v(_vec);
	clock_t end = clock();
	std::cout << "After - Vector: ";
	printContainer(_vec);
	_vecTime = static_cast<float>(end - start) / CLOCKS_PER_SEC * 1000;
}

void	PmergeMe::printTime_deq() {
	clock_t start = clock();
	fordJohnson_d(_deq);
	clock_t end = clock();
	std::cout << "After - Deque: ";
	printContainer(_deq);
	_deqTime = static_cast<float>(end - start) / CLOCKS_PER_SEC * 1000;
}