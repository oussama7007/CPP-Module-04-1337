/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-si- <oait-si-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 09:48:48 by oait-si-          #+#    #+#             */
/*   Updated: 2025/12/09 17:22:56 by oait-si-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.h"
#include "Dog.h"
#include "Cat.h"
#include "WrongAnimal.h"
#include "WrongCat.h"

int main()
{
   
    std::cout << "=== Testing Correct Polymorphism ===" << std::endl;
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();

    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;

    i->makeSound(); // will output the cat sound!
    j->makeSound(); // will output the dog sound!
    meta->makeSound();

    delete j;
    delete i;
    delete meta;

    std::cout << std::endl << "=== Testing Wrong Polymorphism ===" << std::endl;
    
    // --- WRONG TEST (No Virtual) ---
     WrongAnimal a;
     WrongCat b;
    const WrongAnimal* wrongMeta = &a;
    const WrongAnimal* wrongCat =  &b;

    std::cout << wrongCat->getType() << " " << std::endl;

    // ISSUE HERE: Because makeSound() is NOT virtual in WrongAnimal,
    // the pointer 'wrongCat' (which is of type WrongAnimal*) will call
    // the WrongAnimal version, NOT the WrongCat version.
    wrongCat->makeSound(); 
    wrongMeta->makeSound();

    // delete wrongCat;
    // delete wrongMeta;

    return 0;
}