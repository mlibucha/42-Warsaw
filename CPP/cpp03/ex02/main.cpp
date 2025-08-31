/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: e <e@student.42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 17:17:15 by e                 #+#    #+#             */
/*   Updated: 2025/08/31 14:52:55 by e                ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

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
	std::cout << "\n=== Testing FragTrap ===" << std::endl;
	FragTrap frag1("Frag1");
	FragTrap frag2("Frag2");
	frag1.attack("Frag2");
	frag2.takeDamage(frag1.getAttackDamage());
	frag2.attack("Frag1");
	frag1.takeDamage(frag2.getAttackDamage());
	frag1.beRepaired(15);
	frag2.beRepaired(8);
	std::cout << "\n=== Testing FragTrap special capacity ===" << std::endl;
	frag1.highFivesGuys();
	frag2.highFivesGuys();
	std::cout << "\n=== Testing copy and assignment ===" << std::endl;
	FragTrap frag3(frag1);
	FragTrap frag4;
	frag4 = frag2;
	std::cout << "\n=== Testing destruction order ===" << std::endl;
	return 0;
}