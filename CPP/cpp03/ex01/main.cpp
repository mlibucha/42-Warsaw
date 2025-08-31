/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: e <e@student.42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 17:17:15 by e                 #+#    #+#             */
/*   Updated: 2025/08/30 20:16:37 by e                ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
    std::cout << "=== Testing ClapTrap ===" << std::endl;
    ClapTrap clap1("Clap1");
    ClapTrap clap2("Clap2");

    clap1.attack("Clap2");
    clap2.takeDamage(clap1.getAttackDamage());

    clap2.attack("Clap1");
    clap1.takeDamage(clap2.getAttackDamage());

    clap1.beRepaired(5);
    clap2.beRepaired(3);

    std::cout << "\n=== Testing ScavTrap ===" << std::endl;
    ScavTrap scav1("Scav1");
    ScavTrap scav2("Scav2");

    scav1.attack("Scav2");
    scav2.takeDamage(scav1.getAttackDamage());

    scav2.attack("Scav1");
    scav1.takeDamage(scav2.getAttackDamage());

    scav1.beRepaired(10);
    scav2.beRepaired(5);

    std::cout << "\n=== Testing ScavTrap special capacity ===" << std::endl;
    scav1.guardGate();
    scav2.guardGate();

    std::cout << "\n=== Testing copy and assignment ===" << std::endl;
    ScavTrap scav3(scav1);
    ScavTrap scav4;
    scav4 = scav2;

    std::cout << "\n=== Testing destruction order ===" << std::endl;
    return 0;
}