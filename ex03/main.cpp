/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-si- <oait-si-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 17:08:48 by oait-si-          #+#    #+#             */
/*   Updated: 2025/12/14 18:52:58 by oait-si-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


/* main.cpp */
#include "AMateria.h"
#include "Character.h"
#include "Cure.h"
#include "Ice.h"
#include "ICharacter.h"
#include "IMateriaSource.h"
#include "MateriaSource.h"

// int main()
// {
    // IMateriaSource* src = new MateriaSource();
    // src->learnMateria(new Ice());
    // src->learnMateria(new Cure());

    // ICharacter* me = new Character("me");
    
    // AMateria* tmp;
    // tmp = src->createMateria("ice");
    // me->equip(tmp);
    // tmp = src->createMateria("cure");
    // me->equip(tmp);
    
    // ICharacter* bob = new Character("bob");
    
    // me->use(0, *bob);
    // me->use(1, *bob);
    
    // delete bob;
    // delete me;
    // delete src;
    
    // return 0;


// }



int main()
{
        std::cout << "\n--- TEST: Type Assignment Logic ---" << std::endl;
        Ice ice;
        Cure cure;
        std::cout << "[Before] Ice type: " << ice.getType() << std::endl;
        std::cout << "[Before] Cure type: " << cure.getType() << std::endl;
    
        AMateria* IceRef = &ice;
        AMateria* cureRef = &crue;
    
        std::cout << "Assigning cure to is ....\n";
        // IceRef = cureRef;
        std::cout << "[after] ice type :" << ice.getType() << std::endl;
    
}