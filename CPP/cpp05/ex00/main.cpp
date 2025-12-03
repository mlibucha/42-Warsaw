/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: e <e@student.42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 01:19:55 by e                 #+#    #+#             */
/*   Updated: 2025/11/12 13:19:55 by e                ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"

static void sep(const std::string& title) {
    std::cout << "\n=== " << title << " ===\n";
}

int main() {
    sep("Valid constructions");
    try {
        Bureaucrat a("Alice", 1);
        Bureaucrat b("Bob", 150);
        Bureaucrat c("Charlie", 42);
        std::cout << a << std::endl;
        std::cout << b << std::endl;
        std::cout << c << std::endl;
    } catch (std::exception& e) {
        std::cout << "Unexpected exception: " << e.what() << std::endl;
    }

    sep("Invalid constructions");
    try {
        Bureaucrat x("X", 0);
    } catch (std::exception& e) {
        std::cout << "Caught: " << e.what() << std::endl;
    }
    try {
        Bureaucrat y("Y", 151);
    } catch (std::exception& e) {
        std::cout << "Caught: " << e.what() << std::endl;
    }

    sep("Increment / Decrement");
    try {
        Bureaucrat d("Dana", 2);
        std::cout << d << std::endl;
        d.incrementGrade(); // 2 -> 1
        std::cout << d << std::endl;
        d.incrementGrade(); // should throw
    } catch (std::exception& e) {
        std::cout << "Caught: " << e.what() << std::endl;
    }
    try {
        Bureaucrat e("Eve", 150);
        std::cout << e << std::endl;
        e.decrementGrade(); // should throw
    } catch (std::exception& e) {
        std::cout << "Caught: " << e.what() << std::endl;
    }

    sep("Copy and assign");
    try {
        Bureaucrat f("Frank", 10);
        Bureaucrat g = f; // copy
        std::cout << f << std::endl;
        std::cout << g << std::endl;
        Bureaucrat h("Harry", 100);
        h = f; // assign (name unchanged, grade copied)
        std::cout << h << std::endl;
    } catch (std::exception& e) {
        std::cout << "Unexpected exception: " << e.what() << std::endl;
    }

    return 0;
}