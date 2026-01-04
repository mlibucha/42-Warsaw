/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlibucha <mlibucha@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 18:25:32 by mlibucha          #+#    #+#             */
/*   Updated: 2026/01/02 18:11:54 by mlibucha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP


#include <iostream> 
#include <map>
#include <fstream>
#include <string>

class BitcoinExchange
{
	private:
		std::map<std::string, float>  dataBase;
		
	public:
		BitcoinExchange();
		~BitcoinExchange();
		void    loadDataBase(const char *fileName);
		void    processInputFile(const char *fileName);
		bool    isValidDate(const std::string& date);
		bool    isValidValue(const std::string& valueStr, float& value);
		float   getExchangeRate(const std::string& date);
};


#endif