/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlibucha <mlibucha@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 15:11:14 by mlibucha          #+#    #+#             */
/*   Updated: 2026/01/03 15:11:43 by mlibucha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP


#include <iostream>
#include <vector>
#include <deque>
#include <string>
#include <sstream>
#include <cctype>
#include <cstdlib>



class PmergeMe
{
	private:
		std::vector<int>  vec;
		std::deque<int>   deq;
		
	public:
		PmergeMe();
		~PmergeMe();
		bool    parseInput(int argc, char** argv);
		void    mergeInsertSortVector();
		void    mergeInsertSortDeque();
		void    printVector() const;
		void    printDeque() const;
};



#endif

