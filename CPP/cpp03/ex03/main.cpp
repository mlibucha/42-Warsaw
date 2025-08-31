/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: e <e@student.42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 17:17:15 by e                 #+#    #+#             */
/*   Updated: 2025/08/31 18:00:03 by e                ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main()
{
    std::cout << "=== Testing DiamondTrap ===" << std::endl;
    DiamondTrap diamond1("Diamond1");
    DiamondTrap diamond2("Diamond2");
    std::cout << "\n=== Testing DiamondTrap attributes ===" << std::endl;
    std::cout << "Diamond1 - HP: " << diamond1.getHitPoints() 
              << ", EP: " << diamond1.getEnergyPoints()
              << ", AD: " << diamond1.getAttackDamage() << std::endl;
    std::cout << "\n=== Testing DiamondTrap attack (from ScavTrap) ===" << std::endl;
    diamond1.attack("Target");
    diamond2.attack("AnotherTarget");
    std::cout << "\n=== Testing DiamondTrap special capacities ===" << std::endl;
    diamond1.whoAmI();
    diamond2.whoAmI();
    std::cout << "\n=== Testing FragTrap capacity ===" << std::endl;
    diamond1.highFivesGuys();
    std::cout << "\n=== Testing ScavTrap capacity ===" << std::endl;
    diamond2.guardGate();
    std::cout << "\n=== Testing copy and assignment ===" << std::endl;
    DiamondTrap diamond3(diamond1);
    DiamondTrap diamond4;
    diamond4 = diamond2;
    std::cout << "\n=== Testing destruction order ===" << std::endl;
    return 0;
}