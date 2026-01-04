/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlibucha <mlibucha@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 18:31:10 by mlibucha          #+#    #+#             */
/*   Updated: 2026/01/02 18:17:06 by mlibucha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "BitcoinExchange.hpp"

#include <cctype>
#include <sstream>
#include <cstdlib>



BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::~BitcoinExchange() {}


std::string trim(const std::string &s)
{
	std::string::size_type start = s.find_first_not_of(" \t");
	if (start == std::string::npos)
		return "";
	std::string::size_type end = s.find_last_not_of(" \t");
	return s.substr(start, end - start + 1);
}

bool parseFloat(const std::string &str, float &out)
{
	std::stringstream ss(str);
	ss >> out;
	return !ss.fail() && ss.eof();
}

bool isLeap(int year)
{
	return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

void BitcoinExchange::loadDataBase(const char *fileName)
{
	std::ifstream file(fileName);
	if (!file.is_open())
	{
		std::cerr << "Error: could not open data file." << std::endl;
		return;
	}

	std::string line;
	std::getline(file, line);
	while (std::getline(file, line))
	{
		size_t comma = line.find(',');
		if (comma == std::string::npos)
			continue;
		std::string date = trim(line.substr(0, comma));
		std::string rateStr = trim(line.substr(comma + 1));
		float rate;
		if (!isValidDate(date) || !parseFloat(rateStr, rate))
			continue;
		dataBase[date] = rate;
	}
}

bool BitcoinExchange::isValidDate(const std::string &date)
{
	if (date.size() != 10 || date[4] != '-' || date[7] != '-')
		return false;
	for (size_t i = 0; i < date.size(); ++i)
	{
		if (i == 4 || i == 7)
			continue;
		if (!std::isdigit(date[i]))
			return false;
	}
	int year = atoi(date.substr(0, 4).c_str());
	int month = atoi(date.substr(5, 2).c_str());
	int day = atoi(date.substr(8, 2).c_str());
	if (month < 1 || month > 12)
		return false;
	int monthDays[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	if (isLeap(year))
		monthDays[1] = 29;
	if (day < 1 || day > monthDays[month - 1])
		return false;
	return true;
}

bool BitcoinExchange::isValidValue(const std::string &valueStr, float &value)
{
	if (!parseFloat(valueStr, value))
		return false;
	if (value < 0)
	{
		std::cerr << "Error: not a positive number." << std::endl;
		return false;
	}
	if (value > 1000)
	{
		std::cerr << "Error: too large a number." << std::endl;
		return false;
	}
	return true;
}

float BitcoinExchange::getExchangeRate(const std::string &date)
{
	if (dataBase.empty())
		return -1.0f;

	std::map<std::string, float>::const_iterator it = dataBase.lower_bound(date);
	if (it != dataBase.end() && it->first == date)
		return it->second;
	if (it == dataBase.begin())
		return -1.0f;
	--it;
	return it->second;
}

void BitcoinExchange::processInputFile(const char *fileName)
{
	std::ifstream file(fileName);
	if (!file.is_open())
	{
		std::cerr << "Error: could not open file." << std::endl;
		return;
	}

	std::string line;
	std::getline(file, line);
	while (std::getline(file, line))
	{
		size_t pipe = line.find('|');
		if (pipe == std::string::npos)
		{
			std::cerr << "Error: bad input => " << line << std::endl;
			continue;
		}
		std::string date = trim(line.substr(0, pipe));
		std::string valueStr = trim(line.substr(pipe + 1));
		float value;
		if (!isValidDate(date))
		{
			std::cerr << "Error: bad input => " << line << std::endl;
			continue;
		}
		if (!isValidValue(valueStr, value))
			continue;
		float rate = getExchangeRate(date);
		if (rate < 0)
		{
			std::cerr << "Error: bad input => " << date << std::endl;
			continue;
		}
		float result = value * rate;
		std::cout << date << " => " << value << " = " << result << std::endl;
	}
}