/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: e <e@student.42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 14:29:46 by e                 #+#    #+#             */
/*   Updated: 2025/11/20 16:25:59 by e                ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scalar.hpp"
#include <cstring>
#include <cctype>
#include <cerrno>
#include <climits>
#include <cstdlib>
#include <limits>
#include <iomanip>
#include <cmath>

void ScalarConverter::convert_to_float(const std::string& literal)
{
	if (literal == "nanf" || literal == "+inff" || literal == "-inff")
	{
		std::cout << "float: " << literal << std::endl;
		return;
	}
	if (literal == "nan" || literal == "+inf" || literal == "-inf")
	{
		if (literal == "nan")
			std::cout << "float: nanf" << std::endl;
		else if (literal == "+inf")
			std::cout << "float: +inff" << std::endl;
		else
			std::cout << "float: -inff" << std::endl;
		return;
	}

	double baseValue = 0.0;
	if (literal.length() == 1 && !std::isdigit(static_cast<unsigned char>(literal[0])))
	{
		baseValue = static_cast<unsigned char>(literal[0]);
	}
	else
	{
		std::string work = literal;
		if (work.size() > 1 && (work[work.size() - 1] == 'f'))
			work.erase(work.size() - 1);

		errno = 0;
		char* end = NULL;
		baseValue = std::strtod(work.c_str(), &end);
		if (errno == ERANGE || end == work.c_str() || *end != '\0')
		{
			std::cout << "float: impossible" << std::endl;
			return;
		}
	}
	if (std::fabs(baseValue) > static_cast<double>(std::numeric_limits<float>::max()))
	{
		std::cout << "float: impossible" << std::endl;
		return;
	}
	std::ios::fmtflags oldFlags = std::cout.flags();
	std::streamsize oldPrec = std::cout.precision();
	std::cout << std::fixed << std::setprecision(1)
			  << "float: " << static_cast<float>(baseValue) << "f" << std::endl;
	std::cout.flags(oldFlags);
	std::cout.precision(oldPrec);
}

void ScalarConverter::convert_to_double(const std::string& literal)
{
	if (literal == "nan" || literal == "+inf" || literal == "-inf")
	{
		std::cout << "double: " << literal << std::endl;
		return;
	}
	if (literal == "nanf" || literal == "+inff" || literal == "-inff")
	{
		if (literal == "nanf")
			std::cout << "double: nan" << std::endl;
		else if (literal == "+inff")
			std::cout << "double: +inf" << std::endl;
		else
			std::cout << "double: -inf" << std::endl;
		return;
	}

	double value = 0.0;
	if (literal.length() == 1 && !std::isdigit(static_cast<unsigned char>(literal[0])))
	{
		value = static_cast<unsigned char>(literal[0]);
	}
	else
	{
		std::string work = literal;
		if (work.size() > 1 && work[work.size() - 1] == 'f')
			work.erase(work.size() - 1);

		errno = 0;
		char* end = NULL;
		value = std::strtod(work.c_str(), &end);
		if (errno == ERANGE || end == work.c_str() || *end != '\0')
		{
			std::cout << "double: impossible" << std::endl;
			return;
		}
	}
	std::ios::fmtflags oldFlags = std::cout.flags();
	std::streamsize oldPrec = std::cout.precision();
	std::cout << std::fixed << std::setprecision(1)
			  << "double: " << value << std::endl;
	std::cout.flags(oldFlags);
	std::cout.precision(oldPrec);
}

void ScalarConverter::convert_to_int(const std::string& literal)
{
	 const char* s = literal.c_str();
	 char* end = NULL;
	 long val = std::strtol(s, &end, 10);
	if(literal.length() == 1 && !isdigit(literal[0]))
		std::cout << "int: " << static_cast<int>(literal[0]) << std::endl;
	else if("2137483647" > literal && literal.length() >= 11)
		std::cout << "int: " << "overflow"<<  std::endl;
	else if("-2137483648" > literal && literal.length() >= 11)
		std::cout << "int: " << "overflow"<<  std::endl;
	else
		std::cout << "int: " << val <<  std::endl;
}

void ScalarConverter::convert_to_char(const std::string& literal)
{
	if(literal.length() < 3)
	{
		if(literal >= "127")
		{
			if(isprint(literal[0]))
				std::cout << "char: '" << literal[0] << "'" << std::endl;
			else
				std::cout << "char: Non 2displayable" << std::endl;
		}
		else
			std::cout << "char: impossible" << std::endl;
	}
	else
		std::cout << "char: impossible" << std::endl;
}

void ScalarConverter::convert(const std::string& literal)
{
	std::cout << "Converting literal: " << literal << std::endl;
	convert_to_char(literal);
	convert_to_int(literal);
	convert_to_float(literal);
	convert_to_double(literal);
}