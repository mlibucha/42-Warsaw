/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scalar.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: e <e@student.42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 14:27:53 by e                 #+#    #+#             */
/*   Updated: 2025/11/20 14:33:59 by e                ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALAR_HPP
#define SCALAR_HPP

#include <string>
#include <stdexcept>
#include <iostream>
#include <iomanip>
#include <limits>
#include <cmath>


class ScalarConverter {
public:
	static void convert(const std::string& literal);
	void static convert_to_char(const std::string& literal);
	void static convert_to_int(const std::string& literal);
	void static convert_to_float(const std::string& literal);
	void static convert_to_double(const std::string& literal);

private:
	ScalarConverter();
	~ScalarConverter();
	ScalarConverter(const ScalarConverter& other);
	ScalarConverter& operator=(const ScalarConverter& other);

};

#endif /* SCALAR_HPP */