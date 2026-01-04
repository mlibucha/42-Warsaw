/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlibucha <mlibucha@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 15:12:41 by mlibucha          #+#    #+#             */
/*   Updated: 2026/01/03 15:17:56 by mlibucha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "PmergeMe.hpp"



PmergeMe::PmergeMe() {}

PmergeMe::~PmergeMe() {}

bool PmergeMe::parseInput(int argc, char** argv)
{
	for (int i = 1; i < argc; ++i)
	{
		std::string arg = argv[i];
		for (size_t j = 0; j < arg.length(); ++j)
		{
			if (!std::isdigit(arg[j]))
				return false;
		}
		int num = std::atoi(arg.c_str());
		if (num < 0)
			return false;
		vec.push_back(num);
		deq.push_back(num);
	}
	return true;
}



void PmergeMe::printVector() const
{
	for (size_t i = 0; i < vec.size(); ++i)
	{
		std::cout << vec[i];
		if (i != vec.size() - 1)
			std::cout << " ";
	}
	std::cout << std::endl;
}

void PmergeMe::printDeque() const
{
	for(size_t i = 0; i < deq.size(); ++i)
	{
		std::cout << deq[i];
		if (i != deq.size() - 1)
			std::cout << " ";
	}
	std::cout << std::endl;
}