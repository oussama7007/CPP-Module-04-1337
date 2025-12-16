/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-si- <oait-si-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 17:08:48 by oait-si-          #+#    #+#             */
/*   Updated: 2025/12/16 17:11:49 by oait-si-         ###   ########.fr       */
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


    std::cout << "[3] Creating unknown Materia..." << std::endl;
    AMateria* unknown = src->createMateria("fire");
    if (unknown == NULL)
        std::cout << "✅ Correct: Returned NULL for unknown type." << std::endl;
    else
        std::cout << "❌ Error: Created unknown type!" << std::endl;

    delete src;
    delete overflow;
}



void testDeepCopy() {
    std::cout << "\n========================================" << std::endl;
    std::cout << "       TEST 3: DEEP COPY CHECK" << std::endl;
    std::cout << "========================================" << std::endl;

    Character* original = new Character("Original");
    original->equip(new Ice());
    original->equip(new Cure());

    
    Character* copy = new Character(*original);

    
    delete original;
    std::cout << "Original deleted. Testing copy survival..." << std::endl;


    copy->use(0, *copy); 
    copy->use(1, *copy);

    delete copy;
}



int main() {

    testSubject();
    testMateriaSource();
    testDeepCopy();
    

    return 0;
}



