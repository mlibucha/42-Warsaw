/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: e <e@student.42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 14:55:58 by e                 #+#    #+#             */
/*   Updated: 2025/11/28 14:15:27 by e                ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Array.hpp"

int main() {
    Array<int> empty;
    std::cout << "empty.size() = " << empty.size() << std::endl;
    Array<int> ints(5);
    for (std::size_t i = 0; i < ints.size(); ++i) {
        std::cout << "ints[" << i << "] = " << ints[i] << std::endl;
    }
    for (std::size_t i = 0; i < ints.size(); ++i) {
        ints[i] = static_cast<int>(i * 10);
    }
    Array<int> copyInts(ints);
    copyInts[0] = 999;
    std::cout << "ints[0] = " << ints[0] << " | copyInts[0] = " << copyInts[0] << std::endl;
    Array<std::string> strs(3);
    strs[0] = "hello";
    strs[1] = "world";
    strs[2] = "!";
    Array<std::string> strs2;
    strs2 = strs;
    strs2[1] = "42";
    std::cout << "strs[1] = " << strs[1] << " | strs2[1] = " << strs2[1] << std::endl;
    try {
        std::cout << ints[10] << std::endl; // should throw
    } catch (const std::exception& e) {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }

    return 0;
}