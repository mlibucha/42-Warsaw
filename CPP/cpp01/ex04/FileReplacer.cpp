/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FileReplacer.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: e <e@student.42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 16:23:53 by e                 #+#    #+#             */
/*   Updated: 2025/08/16 16:27:45 by e                ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FileReplacer.hpp"
#include <fstream>
#include <iostream>
#include <sstream>

bool FileReplacer::replaceInFile(const std::string& filename,
							   const std::string& s1,
							   const std::string& s2) {
	if (s1.empty()) {
		std::cerr << "Error: s1 cannot be empty" << std::endl;
		return false;
	}
	std::ifstream inputFile(filename.c_str());
	if (!inputFile.is_open()) {
		std::cerr << "Error: could not open file " << filename << std::endl;
		return false;
	}
	std::ofstream outputFile((filename + ".replace").c_str());
	if (!outputFile.is_open()) {
		std::cerr << "Error: could not create output file" << std::endl;
		inputFile.close();
		return false;
	}
	std::string line;
	while (std::getline(inputFile, line))
	{
		size_t pos = 0;
		size_t found;
		std::string newLine;
		while ((found = line.find(s1, pos)) != std::string::npos)
		{
			newLine += line.substr(pos, found - pos);
			if (found == std::string::npos)
				break;
			newLine += s2;
			pos = found + s1.length();
		}
		newLine += line.substr(pos);
		outputFile << newLine << std::endl;
	}
	inputFile.close();
	outputFile.close();
	return true;
}