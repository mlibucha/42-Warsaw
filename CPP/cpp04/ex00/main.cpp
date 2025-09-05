/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: e <e@student.42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 21:23:19 by e                 #+#    #+#             */
/*   Updated: 2025/09/05 18:36:37 by e                ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main() {
    std::cout << "=== Testing Polymorphism ===" << std::endl;
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();

    std::cout << "\n=== Testing getType() ===" << std::endl;
    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;

    std::cout << "\n=== Testing makeSound() ===" << std::endl;
    i->makeSound();
    j->makeSound();
    meta->makeSound();

    std::cout << "\n=== Testing Wrong Animals (No Polymorphism) ===" << std::endl;
    const WrongAnimal* wrongMeta = new WrongAnimal();
    const WrongAnimal* wrongCat = new WrongCat();

    std::cout << wrongCat->getType() << " " << std::endl;
    wrongCat->makeSound();
    wrongMeta->makeSound();

    std::cout << "\n=== Cleanup ===" << std::endl;
    delete meta;
    delete j;
    delete i;
    delete wrongMeta;
    delete wrongCat;

    std::cout << "\n=== Additional Tests ===" << std::endl;
    Dog originalDog;
    Dog copiedDog(originalDog);
    
    Cat originalCat;
    Cat copiedCat = originalCat;

    return 0;
}