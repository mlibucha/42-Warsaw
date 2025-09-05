/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: e <e@student.42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 17:22:55 by e                 #+#    #+#             */
/*   Updated: 2025/09/05 17:22:56 by e                ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(std::string const & name) : name(name) {
    for (int i = 0; i < INVENTORY_SIZE; i++) {
        inventory[i] = 0;
    }
}

Character::Character(const Character& other) : name(other.name) {
    copyInventory(other);
}

Character& Character::operator=(const Character& other) {
    if (this != &other) {
        name = other.name;
        clearInventory();
        copyInventory(other);
    }
    return *this;
}

Character::~Character() {
    clearInventory();
}

void Character::clearInventory() {
    for (int i = 0; i < INVENTORY_SIZE; i++) {
        if (inventory[i] != 0) {
            delete inventory[i];
            inventory[i] = 0;
        }
    }
}

void Character::copyInventory(const Character& other) {
    for (int i = 0; i < INVENTORY_SIZE; i++) {
        if (other.inventory[i] != 0) {
            inventory[i] = other.inventory[i]->clone();
        } else {
            inventory[i] = 0;
        }
    }
}

std::string const & Character::getName() const {
    return name;
}

void Character::equip(AMateria* m) {
    if (m == 0) return;
    
    for (int i = 0; i < INVENTORY_SIZE; i++) {
        if (inventory[i] == 0) {
            inventory[i] = m;
            return;
        }
    }
}

void Character::unequip(int idx) {
    if (idx >= 0 && idx < INVENTORY_SIZE) {
        inventory[idx] = 0;
    }
}

void Character::use(int idx, ICharacter& target) {
    if (idx >= 0 && idx < INVENTORY_SIZE && inventory[idx] != 0) {
        inventory[idx]->use(target);
    }
}