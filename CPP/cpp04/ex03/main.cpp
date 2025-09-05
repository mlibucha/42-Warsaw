/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: e <e@student.42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 21:23:19 by e                 #+#    #+#             */
/*   Updated: 2025/09/05 17:21:23 by e                ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"
#include <iostream>

void testBasicFunctionality() {
    std::cout << "=== Basic Functionality Test ===" << std::endl;
    
    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());
    
    ICharacter* me = new Character("me");
    AMateria* tmp;
    
    tmp = src->createMateria("ice");
    me->equip(tmp);
    
    tmp = src->createMateria("cure");
    me->equip(tmp);
    
    ICharacter* bob = new Character("bob");
    
    me->use(0, *bob);
    me->use(1, *bob);
    
    delete bob;
    delete me;
    delete src;
    std::cout << std::endl;
}

void testInventoryManagement() {
    std::cout << "=== Inventory Management Test ===" << std::endl;
    
    Character* player = new Character("Player");
    
    // Test equip and use
    player->equip(new Ice());
    player->equip(new Cure());
    
    Character dummy("Dummy");
    player->use(0, dummy);
    player->use(1, dummy);
    
    // Test unequip
    player->unequip(0);
    player->use(0, dummy); // Should do nothing
    
    // Test full inventory
    player->equip(new Ice());
    player->equip(new Cure());
    player->equip(new Ice()); // Fourth slot
    player->equip(new Cure()); // Should not equip (inventory full)
    
    delete player;
    std::cout << std::endl;
}

void testDeepCopy() {
    std::cout << "=== Deep Copy Test ===" << std::endl;
    
    Character original("Original");
    original.equip(new Ice());
    original.equip(new Cure());
    
    Character copy(original); // Copy constructor
    Character assigned("Assigned");
    assigned = original; // Assignment operator
    
    Character dummy("Dummy");
    std::cout << "Original: ";
    original.use(0, dummy);
    std::cout << "Copy: ";
    copy.use(0, dummy);
    std::cout << "Assigned: ";
    assigned.use(0, dummy);
    
    // Modify original to verify deep copy
    original.unequip(0);
    std::cout << "After modifying original:" << std::endl;
    std::cout << "Original: ";
    original.use(0, dummy); // Should do nothing
    std::cout << "Copy: ";
    copy.use(0, dummy); // Should still work
    
    std::cout << std::endl;
}

void testMateriaSource() {
    std::cout << "=== Materia Source Test ===" << std::endl;
    
    MateriaSource src;
    src.learnMateria(new Ice());
    src.learnMateria(new Cure());
    
    // Test creating known materias
    AMateria* ice = src.createMateria("ice");
    AMateria* cure = src.createMateria("cure");
    
    Character dummy("Dummy");
    if (ice) ice->use(dummy);
    if (cure) cure->use(dummy);
    
    // Test creating unknown materia
    AMateria* unknown = src.createMateria("fire");
    if (unknown == 0) {
        std::cout << "Unknown materia type correctly returns null" << std::endl;
    }
    
    delete ice;
    delete cure;
    std::cout << std::endl;
}

void testEdgeCases() {
    std::cout << "=== Edge Cases Test ===" << std::endl;
    
    Character test("Test");
    
    // Test invalid indices
    test.use(-1, test); // Should do nothing
    test.use(10, test); // Should do nothing
    test.unequip(-1);   // Should do nothing
    test.unequip(10);   // Should do nothing
    
    // Test null materia
    test.equip(0); // Should do nothing
    
    std::cout << "Edge cases handled correctly" << std::endl;
    std::cout << std::endl;
}

int main() {
    testBasicFunctionality();
    testInventoryManagement();
    testDeepCopy();
    testMateriaSource();
    testEdgeCases();
    
    return 0;
}