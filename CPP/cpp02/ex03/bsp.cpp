/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: e <e@student.42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 14:56:20 by e                 #+#    #+#             */
/*   Updated: 2025/08/31 18:02:34 by e                ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include <cmath>

static Fixed calculateArea(Point const a, Point const b, Point const c) {
    Fixed term1 = a.getX().operator*(b.getY().operator-(c.getY()));
    Fixed term2 = b.getX().operator*(c.getY().operator-(a.getY()));
    Fixed term3 = c.getX().operator*(a.getY().operator-(b.getY()));
    Fixed sum = term1.operator+(term2).operator+(term3);
    Fixed area = sum.operator/(Fixed(2.0f));
    if (area.operator<(Fixed(0))) {
        return area.operator*(Fixed(-1));
    }
    return area;
}

bool bsp(Point const a, Point const b, Point const c, Point const point) {
    Fixed areaABC = calculateArea(a, b, c);
    Fixed areaPBC = calculateArea(point, b, c);
    Fixed areaAPC = calculateArea(a, point, c);
    Fixed areaABP = calculateArea(a, b, point);
    Fixed totalArea = areaPBC.operator+(areaAPC).operator+(areaABP);
    if (areaPBC.operator==(Fixed(0)) || areaAPC.operator==(Fixed(0)) || areaABP.operator==(Fixed(0))) {
        return false;
    }
    return (totalArea.operator==(areaABC));
}