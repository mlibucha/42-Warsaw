/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: e <e@student.42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 15:23:40 by e                 #+#    #+#             */
/*   Updated: 2025/06/28 17:15:12 by e                ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main() {
	randomChump("BlackZombie");
	Zombie* Zombie = newZombie("WhiteZombie");
	Zombie->announce();
	delete Zombie;

	return 0;
}