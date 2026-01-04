/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlibucha <mlibucha@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 18:24:11 by mlibucha          #+#    #+#             */
/*   Updated: 2025/12/14 21:01:40 by mlibucha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include  "BitcoinExchange.hpp"



int main (int argc, char **argv)
{
	

	if (argc != 2)
	{
		std::cerr << "Error: could not open file." << std::endl;
		return 1;
	}
	BitcoinExchange btcExchange;

	btcExchange.loadDataBase("data.csv");
	btcExchange.processInputFile(argv[1]);

	return 0;
}