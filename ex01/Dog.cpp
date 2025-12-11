/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-si- <oait-si-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 15:19:52 by oait-si-          #+#    #+#             */
/*   Updated: 2025/12/11 14:09:00 by oait-si-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Dog.cpp */
#include "Dog.h"

Dog::Dog() : Animal() 
{
    this->type = "Dog";
    this->brain = new Brain(); // <--- 1. ALLOCATE MEMORY
    std::cout << "Dog Constructor" << std::endl;
}

// Deep Copy Constructor
Dog::Dog(const Dog& other) : Animal(other) 
{
    std::cout << "Dog Copy Constructor" << std::endl;
    // Do NOT just do *this = other; It's risky with pointers in constructors
    // Create a new Brain by copying the other dog's brain
    this->brain = new Brain(*other.brain); 
}

// Deep Assignment Operator
Dog& Dog::operator=(const Dog& other) 
{
    std::cout << "Dog Assignment Operator" << std::endl;
    if (this != &other)
    {
        Animal::operator=(other); // Call base assignment
        
        // 2. CLEAN UP OLD BRAIN
        delete this->brain; 
        
        // 3. CREATE NEW DEEP COPY
        // This relies on Brain's copy constructor working correctly
        this->brain = new Brain(*other.brain); 
    }
    return *this;
}

Dog::~Dog() 
{
    delete this->brain; 
    std::cout << "Dog Destructor" << std::endl;
}

void Dog::makeSound() const 
{
    std::cout << "Woof Woof!" << std::endl;
}