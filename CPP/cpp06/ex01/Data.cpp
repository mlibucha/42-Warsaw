/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: e <e@student.42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 16:38:02 by e                 #+#    #+#             */
/*   Updated: 2025/11/20 16:38:17 by e                ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

Data::Data(int i, const std::string& n, double v) 
    : id(i), name(n), value(v) {}

bool Data::operator==(const Data& other) const {
    return id == other.id && name == other.name && value == other.value;
}

void Data::display() const {
    std::cout << "Data { id: " << id << ", name: \"" << name 
              << "\", value: " << value << " }" << std::endl;
}