/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: e <e@student.42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 21:23:19 by e                 #+#    #+#             */
/*   Updated: 2025/09/05 18:38:38 by e                ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include <iostream>
#include <sstream>

void testBasicFunctionality() {
    std::cout << "=== Basic Functionality Test ===" << std::endl;
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    std::cout << "j type: " << j->getType() << std::endl;
    std::cout << "i type: " << i->getType() << std::endl;
    j->makeSound();
    i->makeSound();
    delete j;
    delete i;
    std::cout << std::endl;
}

void testArrayOfAnimals() {
    std::cout << "=== Array of Animals Test ===" << std::endl;
    const int numAnimals = 6;
    Animal* animals[numAnimals];
    
    for (int i = 0; i < numAnimals / 2; i++) {
        animals[i] = new Dog();
        Dog* dog = dynamic_cast<Dog*>(animals[i]);
        dog->setIdea(0, "I want to play fetch");
        dog->setIdea(1, "I'm hungry");
    }
    
    for (int i = numAnimals / 2; i < numAnimals; i++) {
        animals[i] = new Cat();
        Cat* cat = dynamic_cast<Cat*>(animals[i]);
        cat->setIdea(0, "I want to sleep");
        cat->setIdea(1, "I'm curious");
    }
    
    for (int i = 0; i < numAnimals; i++) {
        std::cout << "Animal " << i << " (" << animals[i]->getType() << "): ";
        animals[i]->makeSound();
    }
    
    for (int i = 0; i < numAnimals; i++) {
        delete animals[i];
    }
    std::cout << std::endl;
}

void testDeepCopy() {
    std::cout << "=== Deep Copy Test ===" << std::endl;
    
    Dog* originalDog = new Dog();
    originalDog->setIdea(0, "I love bones!");
    originalDog->setIdea(1, "I want to play fetch!");
    
    Dog* copiedDog = new Dog(*originalDog);
    copiedDog->setIdea(0, "I love toys instead!");
    
    std::cout << "Original dog idea 0: " << originalDog->getIdea(0) << std::endl;
    std::cout << "Copied dog idea 0: " << copiedDog->getIdea(0) << std::endl;
    std::cout << "Original dog idea 1: " << originalDog->getIdea(1) << std::endl;
    std::cout << "Copied dog idea 1: " << copiedDog->getIdea(1) << std::endl;
    
    Dog anotherDog;
    anotherDog = *originalDog;
    anotherDog.setIdea(0, "I'm assigned!");
    
    std::cout << "Assigned dog idea 0: " << anotherDog.getIdea(0) << std::endl;
    std::cout << "Original dog idea 0: " << originalDog->getIdea(0) << std::endl;
    
    delete originalDog;
    delete copiedDog;
    
    Cat* originalCat = new Cat();
    originalCat->setIdea(0, "I love fish!");
    originalCat->setIdea(1, "I want to sleep!");
    
    Cat* copiedCat = new Cat(*originalCat);
    copiedCat->setIdea(0, "I love chicken instead!");
    
    std::cout << "Original cat idea 0: " << originalCat->getIdea(0) << std::endl;
    std::cout << "Copied cat idea 0: " << copiedCat->getIdea(0) << std::endl;
    
    delete originalCat;
    delete copiedCat;
    std::cout << std::endl;
}

void testBrainFunctionality() {
    std::cout << "=== Brain Functionality Test ===" << std::endl;
    
    Dog smartDog;
    for (int i = 0; i < 5; i++) {
        std::stringstream ss;
        ss << i;
        smartDog.setIdea(i, "Dog thought " + ss.str());
    }
    
    Cat smartCat;
    for (int i = 0; i < 5; i++) {
        std::stringstream ss;
        ss << i;
        smartCat.setIdea(i, "Cat thought " + ss.str());
    }
    
    std::cout << "Smart dog thoughts:" << std::endl;
    for (int i = 0; i < 5; i++) {
        std::cout << "  " << smartDog.getIdea(i) << std::endl;
    }
    
    std::cout << "Smart cat thoughts:" << std::endl;
    for (int i = 0; i < 5; i++) {
        std::cout << "  " << smartCat.getIdea(i) << std::endl;
    }
    std::cout << std::endl;
}

int main() {
    testBasicFunctionality();
    testArrayOfAnimals();
    testDeepCopy();
    testBrainFunctionality();
    
    std::cout << "=== Exercise Required Test ===" << std::endl;
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    
    delete j;
    delete i;
    
    return 0;
}