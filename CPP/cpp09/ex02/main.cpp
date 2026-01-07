/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: e <e@student.42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 15:10:54 by mlibucha          #+#    #+#             */
/*   Updated: 2026/01/07 14:20:43 by e                ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <sys/time.h>
#include <iostream>
#include <iomanip>

static double elapsed_us(const timeval &a, const timeval &b)
{
	long sec = b.tv_sec - a.tv_sec;
	long usec = b.tv_usec - a.tv_usec;
	return static_cast<double>(sec) * 1e6 + static_cast<double>(usec);
}

int main(int argc, char **argv)
{
	PmergeMe sorter;
	if (!sorter.parseInput(argc, argv))
	{
		std::cerr << "Error" << std::endl;
		return 1;
	}

	std::cout << "Before: ";
	sorter.printVector();

	// Time vector
	timeval t0v, t1v;
	gettimeofday(&t0v, 0);
	sorter.mergeInsertSortVector();
	gettimeofday(&t1v, 0);
	double vec_us = elapsed_us(t0v, t1v);

	// Time deque
	timeval t0d, t1d;
	gettimeofday(&t0d, 0);
	sorter.mergeInsertSortDeque();
	gettimeofday(&t1d, 0);
	double deq_us = elapsed_us(t0d, t1d);

	std::cout << "After: ";
	sorter.printVector();

	std::cout << std::fixed << std::setprecision(5);
	std::cout << "Time to process a range of " << sorter.getVector().size()
			  << " elements with std::vector : " << vec_us << " us" << std::endl;
	std::cout << "Time to process a range of " << sorter.getDeque().size()
			  << " elements with std::deque  : " << deq_us << " us" << std::endl;

	return 0;
}