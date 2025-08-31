/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: e <e@student.42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 20:15:21 by e                 #+#    #+#             */
/*   Updated: 2025/08/31 14:59:40 by e                ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include <iostream>

FragTrap::FragTrap() : ClapTrap("Default") {
	hitPoints = 100;
	energyPoints = 100;
	attackDamage = 30;
	std::cout << "FragTrap " << name << " constructed with default values." << std::endl;
}

FragTrap::FragTrap(const std::string& name) : ClapTrap(name) {
	hitPoints = 100;
	energyPoints = 100;
	attackDamage = 30;
	std::cout << "FragTrap " << name << " constructed." << std::endl;
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other) {
	std::cout << "FragTrap " << name << " copy constructed." << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& other) {
	if (this != &other) {
		ClapTrap::operator=(other);
	}
	std::cout << "FragTrap " << name << " assigned." << std::endl;
	return *this;
}

FragTrap::~FragTrap() {
	std::cout << "FragTrap " << name << " destructed." << std::endl;
}

void FragTrap::attack(const std::string& target) {
	if (energyPoints > 0 && hitPoints > 0) {
		--energyPoints;
		std::cout << "FragTrap " << name << " launches a powerful attack on " << target 
				  << ", causing " << attackDamage << " points of damage!" << std::endl;
	} else {
		std::cout << "FragTrap " << name << " has insufficient energy or hit points to attack." << std::endl;
	}
}

void FragTrap::highFivesGuys(void) {
	std::cout << "FragTrap " << name << " requests a high five!" << std::endl;
}