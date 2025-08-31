/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap..cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: e <e@student.42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 20:30:21 by e                 #+#    #+#             */
/*   Updated: 2025/08/31 17:59:28 by e                ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"
#include <iostream>

DiamondTrap::DiamondTrap() : ClapTrap("Default_clap_name"), FragTrap(), ScavTrap() {
    name = "Default";
    hitPoints = FragTrap::hitPoints; // 100 from FragTrap
    energyPoints = ScavTrap::energyPoints; // 50 from ScavTrap
    attackDamage = FragTrap::attackDamage; // 30 from FragTrap
    std::cout << "DiamondTrap " << name << " constructed with default values." << std::endl;
}

DiamondTrap::DiamondTrap(const std::string& name) 
    : ClapTrap(name + "_clap_name"), FragTrap(), ScavTrap() {
    this->name = name;
    hitPoints = FragTrap::hitPoints; // 100 from FragTrap
    energyPoints = ScavTrap::energyPoints; // 50 from ScavTrap
    attackDamage = FragTrap::attackDamage; // 30 from FragTrap
    std::cout << "DiamondTrap " << this->name << " constructed." << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& other) 
    : ClapTrap(other), FragTrap(other), ScavTrap(other) {
    *this = other;
    std::cout << "DiamondTrap " << name << " copy constructed." << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other) {
    if (this != &other) {
        ClapTrap::operator=(other);
        name = other.name;
    }
    std::cout << "DiamondTrap " << name << " assigned." << std::endl;
    return *this;
}

DiamondTrap::~DiamondTrap() {
    std::cout << "DiamondTrap " << name << " destructed." << std::endl;
}

void DiamondTrap::whoAmI() {
    std::cout << "DiamondTrap name: " << name << ", ClapTrap name: " << ClapTrap::name << std::endl;
}