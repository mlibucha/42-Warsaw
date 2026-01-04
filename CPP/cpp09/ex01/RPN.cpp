/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlibucha <mlibucha@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 18:18:09 by mlibucha          #+#    #+#             */
/*   Updated: 2026/01/03 15:05:30 by mlibucha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"


RPN::RPN() {}

RPN::~RPN() {}


bool RPN::isOperator(const std::string& token)
{
	return token == "+" || token == "-" || token == "*" || token == "/";
}

bool RPN::isNumber(const std::string& token)
{
	if (token.empty())
		return false;
	for (size_t i = 0; i < token.length(); ++i)
	{
		if (!std::isdigit(token[i]))
			return false;
	}
	return true;
}

bool RPN::is_valid_string(const std::string& str)
{
	std::istringstream iss(str);
	std::string token;
	while (iss >> token)
	{
		if (!isNumber(token) && !isOperator(token))
			return false;
	}
	return true;
}

int RPN::performOperation(const std::string& op, int a, int b)
{
	if (op == "+")
		return a + b;
	if (op == "-")
		return a - b;
	if (op == "*")
		return a * b;
	if (op == "/")
	{
		if (b == 0)
		{
			std::cerr << "Error: division by zero." << std::endl;
			return 0;
		}
		return a / b;
	}
	return 0;
}

bool RPN::evaluateExpression(const std::string& expression, int& result)
{
	std::stack<int> stack;
	std::istringstream iss(expression);
	std::string token;

	while (iss >> token)
	{
		if (isNumber(token))
		{
			stack.push(std::atoi(token.c_str()));
		}
		else if (isOperator(token))
		{
			if (stack.size() < 2)
			{
				std::cerr << "Error: invalid expression." << std::endl;
				return false;
			}
			int b = stack.top();
			stack.pop();
			int a = stack.top();
			stack.pop();
			int res = performOperation(token, a, b);
			stack.push(res);
		}
	}

	if (stack.size() != 1)
	{
		std::cerr << "Error: invalid expression." << std::endl;
		return false;
	}

	result = stack.top();
	return true;
}