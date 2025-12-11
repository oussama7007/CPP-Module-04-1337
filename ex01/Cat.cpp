/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-si- <oait-si-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 15:19:57 by oait-si-          #+#    #+#             */
/*   Updated: 2025/12/11 14:10:11 by oait-si-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.h"

Cat::Cat() : Animal() {
    this->type = "Cat";
    this->brain = new Brain();
    std::cout << "Cat Constructor" << std::endl;
}

Cat::Cat(const Cat& other) : Animal(other) {
    std::cout << "Cat Copy Constructor" << std::endl;

    this->brain = new Brain(*other.brain); 
}

Cat& Cat::operator=(const Cat& other) {
    std::cout << "Cat Assignment Operator" << std::endl;
    if (this != &other)
    {
        Animal::operator=(other);
        delete this->brain; 
        this->brain = new Brain(*other.brain);
    }
    return *this;
}

Cat::~Cat() {
    delete this->brain;
    std::cout << "Cat Destructor" << std::endl;
}

void Cat::makeSound() const {
    std::cout << "Meow!" << std::endl;
}