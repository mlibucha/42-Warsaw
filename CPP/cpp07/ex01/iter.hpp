/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: e <e@student.42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 13:12:59 by e                 #+#    #+#             */
/*   Updated: 2025/11/26 14:20:31 by e                ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>



template <typename T, typename F>
void iter(T *arr, std::size_t len, F func)
{
	for (std::size_t i = 0; i < len; ++i)
		func(arr[i]);
}

#endif