/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlibucha <mlibucha@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 15:10:54 by mlibucha          #+#    #+#             */
/*   Updated: 2026/01/03 15:15:57 by mlibucha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "PmergeMe.hpp"

int main(int argc, char **argv)
{

	if(argc < 2 || argv[1] == NULL)
	{
		std::cerr << "Error: invalid number of arguments." << std::endl;
		return 1;
	}
	PmergeMe sorter;
	if (!sorter.parseInput(argc, argv))
	{
		std::cerr << "Error" << std::endl;
		return 1;
	}

	std::cout << "Before: ";
	sorter.printVector();

	sorter.mergeInsertSortVector();
	sorter.mergeInsertSortDeque();

	std::cout << "After:  ";
	sorter.printVector();

	return 0;
}