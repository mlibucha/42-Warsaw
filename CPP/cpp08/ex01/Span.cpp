/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: e <e@student.42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 16:17:34 by e                 #+#    #+#             */
/*   Updated: 2025/12/03 16:20:03 by e                ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(unsigned int n) : _n(n) {}


Span::~Span() {}
void Span::addNumber(int number) {
	if (_numbers.size() >= _n) {
		throw std::runtime_error("Span is full");
	}
	_numbers.push_back(number);
}

int Span::shortestSpan() {
	if (_numbers.size() < 2) {
		throw std::runtime_error("Not enough numbers to find a span");
	}
	std::vector<int> sortedNumbers = _numbers;
	std::sort(sortedNumbers.begin(), sortedNumbers.end());
	int minSpan = INT_MAX;
	for (size_t i = 1; i < sortedNumbers.size(); ++i) {
		int span = sortedNumbers[i] - sortedNumbers[i - 1];
		if (span < minSpan) {
			minSpan = span;
		}
	}
	return minSpan;
}

int Span::longestSpan() {
	if (_numbers.size() < 2) {
		throw std::runtime_error("Not enough numbers to find a span");
	}
	int minNumber = *std::min_element(_numbers.begin(), _numbers.end());
	int maxNumber = *std::max_element(_numbers.begin(), _numbers.end());
	return maxNumber - minNumber;
}