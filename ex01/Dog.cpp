/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-si- <oait-si-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 15:19:52 by oait-si-          #+#    #+#             */
/*   Updated: 2025/12/13 18:45:01 by oait-si-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Dog.h"

Dog::Dog() : Animal() 
{
    this->type = "Dog";
    this->brain = new Brain(); 
    std::cout << "Dog Constructor" << std::endl;
}

Dog::Dog(const Dog& other) : Animal(other) 
{
    std::cout << "Dog Copy Constructor" << std::endl;
    this->brain = new Brain(*other.brain); 
}


Dog& Dog::operator=(const Dog& other) 
{
    std::cout << "Dog Assignment Operator" << std::endl;
    if (this != &other)
    {
        Animal::operator=(other); 
           
        delete this->brain; 
    
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