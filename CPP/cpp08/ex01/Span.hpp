/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: e <e@student.42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 16:16:08 by e                 #+#    #+#             */
/*   Updated: 2025/12/03 16:20:01 by e                ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
#include <algorithm>
#include <stdexcept>
#include <climits>

class Span {
	
	public:
		Span(unsigned int n);
		~Span();
		void addNumber(int number);
		int shortestSpan();
		int longestSpan();
	
	private:
		unsigned int _n;
		std::vector<int> _numbers;
};

#endif 