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

#include <vector>
#include <deque>
#include <string>
#include <iostream>

class PmergeMe {
public:
    PmergeMe();
    ~PmergeMe();

    // Parse argv into internal containers. Only positive integers (>0) are allowed.
    bool parseInput(int argc, char** argv);

    void printVector() const;
    void printDeque() const;

    void mergeInsertSortVector();
    void mergeInsertSortDeque();

    const std::vector<int>& getVector() const { return vec; }
    const std::deque<int>& getDeque() const { return deq; }

private:
    std::vector<int> vec;
    std::deque<int>  deq;
};

#endif // PMERGEME_HPP

