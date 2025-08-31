/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: e <e@student.42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 15:50:21 by e                 #+#    #+#             */
/*   Updated: 2025/08/29 14:54:04 by e                ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Point.hpp"

int main() {
    // Test case 1: Point inside triangle
    Point a(0, 0);
    Point b(10, 0);
    Point c(0, 10);
    Point inside(2, 2);
    
    std::cout << "Point inside triangle: " << bsp(a, b, c, inside) << std::endl;
    
    // Test case 2: Point outside triangle
    Point outside(10, 10);
    std::cout << "Point outside triangle: " << bsp(a, b, c, outside) << std::endl;
    
    // Test case 3: Point on vertex (should return false)
    Point vertex(0, 0);
    std::cout << "Point on vertex: " << bsp(a, b, c, vertex) << std::endl;
    
    // Test case 4: Point on edge (should return false)
    Point edge(5, 0);
    std::cout << "Point on edge: " << bsp(a, b, c, edge) << std::endl;
    
    return 0;
}