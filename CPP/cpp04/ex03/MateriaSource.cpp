/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: e <e@student.42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 17:22:05 by e                 #+#    #+#             */
/*   Updated: 2025/09/05 17:22:06 by e                ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

MateriaSource::MateriaSource() : learnedCount(0) {
    for (int i = 0; i < TEMPLATE_SIZE; i++) {
        templates[i] = 0;
    }
}

MateriaSource::MateriaSource(const MateriaSource& other) : learnedCount(other.learnedCount) {
    copyTemplates(other);
}

MateriaSource& MateriaSource::operator=(const MateriaSource& other) {
    if (this != &other) {
        clearTemplates();
        learnedCount = other.learnedCount;
        copyTemplates(other);
    }
    return *this;
}

MateriaSource::~MateriaSource() {
    clearTemplates();
}

void MateriaSource::clearTemplates() {
    for (int i = 0; i < TEMPLATE_SIZE; i++) {
        if (templates[i] != 0) {
            delete templates[i];
            templates[i] = 0;
        }
    }
    learnedCount = 0;
}

void MateriaSource::copyTemplates(const MateriaSource& other) {
    for (int i = 0; i < TEMPLATE_SIZE; i++) {
        if (other.templates[i] != 0) {
            templates[i] = other.templates[i]->clone();
        } else {
            templates[i] = 0;
        }
    }
}

void MateriaSource::learnMateria(AMateria* m) {
    if (m == 0 || learnedCount >= TEMPLATE_SIZE) return;
    
    for (int i = 0; i < TEMPLATE_SIZE; i++) {
        if (templates[i] == 0) {
            templates[i] = m->clone();
            learnedCount++;
            return;
        }
    }
}

AMateria* MateriaSource::createMateria(std::string const & type) {
    for (int i = 0; i < TEMPLATE_SIZE; i++) {
        if (templates[i] != 0 && templates[i]->getType() == type) {
            return templates[i]->clone();
        }
    }
    return 0;
}