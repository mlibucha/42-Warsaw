/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: e <e@student.42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 14:55:52 by e                 #+#    #+#             */
/*   Updated: 2025/08/19 14:05:55 by e                ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>

int main(int argc, char **argv) {
	Harl harl;

	if (argc != 2) {
		std::cout << "Usage: ./harlFilter <LOG_LEVEL>\n";
		return 1;
	}

	harl.filter(argv[1]);
	return 0;
}