/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: e <e@student.42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 15:23:40 by e                 #+#    #+#             */
/*   Updated: 2025/06/29 11:51:54 by e                ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include "Zombie.h"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Usage: " << argv[0] << " <amount>" << std::endl;
		return 1;
	}
	int amount = std::atoi(argv[1]);
	if (amount <= 0)
	{
		std::cerr << "Amount must be a positive integer." << std::endl;
		return 1;
	}
	Zombie* horde = zombieHorde(amount, "HordeZombie");
	if (!horde)
	{
		std::cerr << "Failed to create zombie horde." << std::endl;
		return 1;
	}
	for (int i = 0; i < amount; ++i)
	{
		horde[i].announce();
	}
	Zombie* Zombie = newZombie("WhiteZombie");
	Zombie->announce();
	delete Zombie;

	return 0;
}