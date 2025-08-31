/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: e <e@student.42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 20:21:03 by e                 #+#    #+#             */
/*   Updated: 2025/08/30 20:17:11 by e                ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : name("Default"), hitPoints(10), energyPoints(10), attackDamage(0) {
    std::cout << "ClapTrap " << name << " constructed with default values." << std::endl;
}

ClapTrap::ClapTrap(const std::string& name) : name(name), hitPoints(10), energyPoints(10), attackDamage(0) {
    std::cout << "ClapTrap " << name << " constructed." << std::endl;
}


ClapTrap::ClapTrap(const ClapTrap& other) 
    : name(other.name), 
      hitPoints(other.hitPoints), 
      energyPoints(other.energyPoints), 
      attackDamage(other.attackDamage) {
    std::cout << "ClapTrap " << name << " copy constructed." << std::endl;
}


ClapTrap& ClapTrap::operator=(const ClapTrap& other) {
    if (this != &other) {
        name = other.name;
        hitPoints = other.hitPoints;
        energyPoints = other.energyPoints;
        attackDamage = other.attackDamage;
    }
    std::cout << "ClapTrap " << name << " assigned." << std::endl;
    return *this;
}


ClapTrap::~ClapTrap() {
    std::cout << "ClapTrap " << name << " destructed." << std::endl;
}


void ClapTrap::attack(const std::string& target) {
    if (energyPoints > 0 && hitPoints > 0) {
        --energyPoints;
        std::cout << "ClapTrap " << name << " attacks " << target << ", causing " << attackDamage << " points of damage!" << std::endl;
    } else {
        std::cout << "ClapTrap " << name << " has insufficient energy or hit points to attack." << std::endl;
    }
}

void ClapTrap::takeDamage(unsigned int amount) {
    if (amount >= hitPoints) {
        hitPoints = 0;
        std::cout << "ClapTrap " << name << " takes " << amount << " points of damage and is now destroyed!" << std::endl;
    } else {
        hitPoints -= amount;
        std::cout << "ClapTrap " << name << " takes " << amount << " points of damage, remaining hit points: " << hitPoints << "." << std::endl;
    }
}

void ClapTrap::beRepaired(unsigned int amount) {
    if (energyPoints > 0 && hitPoints > 0) {
        --energyPoints;
        hitPoints += amount;
        std::cout << "ClapTrap " << name << " repairs itself for " << amount << " points, new hit points: " << hitPoints << "." << std::endl;
    } else {
        std::cout << "ClapTrap " << name << " has insufficient energy or hit points to repair." << std::endl;
    }
}

// Getters implementation
std::string ClapTrap::getName() const {
    return name;
}

unsigned int ClapTrap::getHitPoints() const {
    return hitPoints;
}

unsigned int ClapTrap::getEnergyPoints() const {
    return energyPoints;
}

unsigned int ClapTrap::getAttackDamage() const {
    return attackDamage;
}

// Setters implementation
void ClapTrap::setName(const std::string& name) {
    this->name = name;
}

void ClapTrap::setHitPoints(unsigned int hitPoints) {
    this->hitPoints = hitPoints;
}

void ClapTrap::setEnergyPoints(unsigned int energyPoints) {
    this->energyPoints = energyPoints;
}

void ClapTrap::setAttackDamage(unsigned int attackDamage) {
    this->attackDamage = attackDamage;
}