/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: e <e@student.42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 13:12:32 by e                 #+#    #+#             */
/*   Updated: 2025/11/26 14:54:39 by e                ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <iostream>
#include <cstddef>

/* free function (not a lambda) so it works with -std=c++98 */
static void printInt(int const &v)
{
	std::cout << v << std::endl;
}

int main(void)
{
	int arr[4] = {0, 1, 2, 3};

	iter(arr, 4, printInt);

	return 0;
}