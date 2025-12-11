/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-si- <oait-si-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 15:28:31 by oait-si-          #+#    #+#             */
/*   Updated: 2025/12/11 14:19:38 by oait-si-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Animal.h"
#include "Dog.h"
#include "Cat.h"
#include "WrongAnimal.h"
#include "WrongCat.h"



void    f()
{
    system("leaks Animal");
}
int main()
{
    atexit(f);
    std::cout << "--- 1. ARRAY TEST (Subject Requirement) ---" << std::endl;
    const int size = 4; 
    const Animal* animals[size];

 
    for (int i = 0; i < size / 2; i++) {
        animals[i] = new Dog();
    }
    for (int i = size / 2; i < size; i++) {
        animals[i] = new Cat();
    }

    
    animals[0]->makeSound(); // Woof
    animals[size - 1]->makeSound(); // Meow

    std::cout << "\n--- 2. DESTRUCTION LOOP (Check for Leaks) ---" << std::endl;

    for (int i = 0; i < size; i++) {
        delete animals[i];
    }

    std::cout << "\n--- 3. DEEP COPY PROOF ---" << std::endl;

    Dog* dog1 = new Dog();
    Dog* dog2 = new Dog(*dog1); 

    std::cout << "Original Dog created. Copy created." << std::endl;
    
  
    delete dog1; 
    std::cout << "Original Dog deleted." << std::endl;

    dog2->makeSound(); 
    delete dog2;       

    return 0;
}