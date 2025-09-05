/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: e <e@student.42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 17:23:15 by e                 #+#    #+#             */
/*   Updated: 2025/09/05 17:23:16 by e                ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "ICharacter.hpp"

AMateria::AMateria(std::string const & type) : type(type) {}

AMateria::AMateria(const AMateria& other) : type(other.type) {}

AMateria& AMateria::operator=(const AMateria& other) {
    if (this != &other) {
        type = other.type;
    }
    return *this;
}

AMateria::~AMateria() {}

std::string const & AMateria::getType() const {
    return type;
}

void AMateria::use(ICharacter& target) {
    std::cout << "* uses materia on " << target.getName() << " *" << std::endl;
}