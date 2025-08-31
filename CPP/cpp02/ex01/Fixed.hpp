/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: e <e@student.42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 20:37:20 by e                 #+#    #+#             */
/*   Updated: 2025/08/26 20:38:06 by e                ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed {
private:
    int                 _value;
    static const int    _fractionalBits = 8;

public:
    // Orthodox Canonical Form
    Fixed();                           // Default constructor
    Fixed(const Fixed& other);         // Copy constructor
    Fixed& operator=(const Fixed& other); // Copy assignment operator
    ~Fixed();                          // Destructor

    // New constructors
    Fixed(const int value);            // Integer constructor
    Fixed(const float value);          // Float constructor

    // Conversion functions
    float toFloat(void) const;
    int toInt(void) const;

    // Member functions
    int getRawBits(void) const;
    void setRawBits(int const raw);
};

// Overload of the insertion operator
std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif