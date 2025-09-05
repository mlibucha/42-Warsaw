/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: e <e@student.42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 21:26:40 by e                 #+#    #+#             */
/*   Updated: 2025/09/03 15:58:27 by e                ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include <string>

class Animal {
protected:
    std::string type;
    
    Animal();
    Animal(const Animal& other);

public:
    Animal& operator=(const Animal& other);
    virtual ~Animal();

    virtual void makeSound() const = 0;
    std::string getType() const;
};

#endif