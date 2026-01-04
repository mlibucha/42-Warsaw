/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlibucha <mlibucha@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 18:18:27 by mlibucha          #+#    #+#             */
/*   Updated: 2026/01/03 15:06:18 by mlibucha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP


#include <iostream>
#include <stack>
#include <string>
#include <sstream>
#include <cctype>
#include <cstdlib>


class RPN
{
	private:
		std::stack<int>  numbers;
		
	public:
		RPN();
		~RPN();
		bool    is_valid_string(const std::string& str);
		bool    isOperator(const std::string& token);
		bool    isNumber(const std::string& token);
		int     performOperation(const std::string& op, int a, int b);
		bool    evaluateExpression(const std::string& expression, int& result);
};



#endif