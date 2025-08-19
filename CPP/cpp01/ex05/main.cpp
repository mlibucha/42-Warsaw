/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: e <e@student.42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 13:52:18 by e                 #+#    #+#             */
/*   Updated: 2025/08/17 14:12:51 by e                ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>

int main() {
	Harl harl;
	
	std::cout << "DEBUG level:" << std::endl;
	harl.complain("DEBUG");
	std::cout << "\nINFO level:" << std::endl;
	harl.complain("INFO");
	std::cout << "\nWARNING level:" << std::endl;
	harl.complain("WARNING");
	std::cout << "\nERROR level:" << std::endl;
	harl.complain("ERROR");
	std::cout << "\nInvalid level:" << std::endl;
	harl.complain("WHINING");
	return 0;
}