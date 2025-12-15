/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-si- <oait-si-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 17:08:48 by oait-si-          #+#    #+#             */
/*   Updated: 2025/12/15 15:47:56 by oait-si-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "AMateria.h"
#include "Character.h"
#include "Cure.h"
#include "Ice.h"
#include "ICharacter.h"
#include "IMateriaSource.h"
#include "MateriaSource.h"



void testSubject() {
    std::cout << "\n========================================" << std::endl;
    std::cout << "       TEST 1: SUBJECT STANDARD" << std::endl;
    std::cout << "========================================" << std::endl;
    
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
}

// =========================================================================
// TEST 2: MATERIA SOURCE (Factory) LIMITS
// Checks if the factory handles unknown types and full memory correctly.
// =========================================================================
void testMateriaSource() {
    std::cout << "\n========================================" << std::endl;
    std::cout << "       TEST 2: MATERIA SOURCE" << std::endl;
    std::cout << "========================================" << std::endl;

    IMateriaSource* src = new MateriaSource();
    
    std::cout << "[1] Learning 4 Materias..." << std::endl;
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());

    std::cout << "[2] Trying to learn 5th (Should not leak or crash)..." << std::endl;
    AMateria* overflow = new Ice();
    src->learnMateria(overflow); 
    // Note: In a real implementation, 'overflow' might be deleted by learnMateria 
    // if full, or you must handle it. Your MateriaSource should handle this gracefully.

    std::cout << "[3] Creating unknown Materia..." << std::endl;
    AMateria* unknown = src->createMateria("fire");
    if (unknown == NULL)
        std::cout << "✅ Correct: Returned NULL for unknown type." << std::endl;
    else
        std::cout << "❌ Error: Created unknown type!" << std::endl;

    delete src;
}

// =========================================================================
// TEST 3: CHARACTER INVENTORY & UNEQUIP
// Checks strict requirements: 4 slots, unequip doesn't delete.
// =========================================================================
void testInventory() {
    std::cout << "\n========================================" << std::endl;
    std::cout << "    TEST 3: INVENTORY & UNEQUIP" << std::endl;
    std::cout << "========================================" << std::endl;

    Character* me = new Character("Gamer");
    AMateria* m1 = new Ice();

    std::cout << "[1] Equipping item..." << std::endl;
    me->equip(m1);
    
    std::cout << "[2] Unequipping item (Logic Check)..." << std::endl;
    me->unequip(0); // m1 is removed from array but NOT deleted
    
    std::cout << "[3] Re-equipping (finding empty slot)..." << std::endl;
    me->equip(m1); // Should put it back in slot 0

    // Fill up inventory
    me->equip(new Cure());
    me->equip(new Ice());
    me->equip(new Cure()); // Now full (4 items)

    std::cout << "[4] Equipping 5th item (Should be rejected)..." << std::endl;
    AMateria* extra = new Ice();
    me->equip(extra); // Should do nothing

    // CLEANUP
    delete extra; // We must delete extra manually since it wasn't equipped
    delete me;    // Deletes the 4 items inside
}

// =========================================================================
// TEST 4: DEEP COPY (The Crash Test)
// Ensures copy constructor makes a NEW inventory, not a pointer copy.
// =========================================================================
void testDeepCopy() {
    std::cout << "\n========================================" << std::endl;
    std::cout << "       TEST 4: DEEP COPY CHECK" << std::endl;
    std::cout << "========================================" << std::endl;

    Character* original = new Character("Original");
    original->equip(new Ice());
    original->equip(new Cure());

    // Copy Constructor
    Character* copy = new Character(*original);

    // DELETE ORIGINAL
    delete original;
    std::cout << "Original deleted. Testing copy survival..." << std::endl;

    // Verify copy still works (Accessing its own memory)
    // If deep copy failed, this crashes here (using deleted pointer).
    copy->use(0, *copy); 
    copy->use(1, *copy);

    delete copy;
}

// =========================================================================
// TEST 5: ASSIGNMENT OPERATOR & TYPE SAFETY
// Checks that assigning a Cure to an Ice doesn't change the type.
// =========================================================================
void testTypeLogic() {
    std::cout << "\n========================================" << std::endl;
    std::cout << "       TEST 5: TYPE SAFETY" << std::endl;
    std::cout << "========================================" << std::endl;

    Ice ice;
    Cure cure;

    AMateria* icePtr = &ice;
    AMateria* curePtr = &cure;

    std::cout << "Before Assignment -> Ice Type: " << ice.getType() << std::endl;

    // FORCE ASSIGNMENT via pointers (dereferenced)
    *icePtr = *curePtr; 

    std::cout << "After Assignment  -> Ice Type: " << ice.getType() << std::endl;

    if (ice.getType() == "ice")
        std::cout << "✅ SUCCESS: Identity preserved." << std::endl;
    else
        std::cout << "❌ FAIL: Identity stolen! (Ice became Cure)" << std::endl;
}

int main() {
    testSubject();
    // testMateriaSource();
    // testInventory();
    // testDeepCopy();
    // testTypeLogic();
    

    return 0;
}



