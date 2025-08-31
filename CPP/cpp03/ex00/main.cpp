/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: e <e@student.42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 17:17:15 by e                 #+#    #+#             */
/*   Updated: 2025/08/30 16:58:18 by e                ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main()
{
	ClapTrap clap1("Clap1");
	ClapTrap clap2("Clap2");

	clap1.attack("Clap2");
	clap2.takeDamage(clap1.getAttackDamage());

	clap2.attack("Clap1");
	clap1.takeDamage(clap2.getAttackDamage());

	clap1.beRepaired(5);
	clap2.beRepaired(3);

	return 0;
}