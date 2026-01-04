/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlibucha <mlibucha@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 18:18:30 by mlibucha          #+#    #+#             */
/*   Updated: 2026/01/03 15:06:45 by mlibucha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Error: invalid number of arguments." << std::endl;
		return 1;
	}
	if (argv[1] == NULL || std::string(argv[1]).empty())
	{
		std::cerr << "Error: empty expression." << std::endl;
		return 1;
	}

	RPN rpn;
	if (!rpn.is_valid_string(std::string(argv[1])))
	{
		std::cerr << "Error" << std::endl;
		return 1;
	}

	int result = 0;
	if (!rpn.evaluateExpression(std::string(argv[1]), result))
	{
		return 1;
	}

	std::cout << result << std::endl;
	return 0;
}