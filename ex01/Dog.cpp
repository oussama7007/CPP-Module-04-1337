/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-si- <oait-si-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 15:19:52 by oait-si-          #+#    #+#             */
/*   Updated: 2025/12/10 15:34:20 by oait-si-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.h"

Dog::Dog() : Animal() {
    this->type = "Dog";
    std::cout << "Dog Constructor" << std::endl;
}

Dog::Dog(const Dog& other) : Animal(other) {
    std::cout << "Dog Copy Constructor" << std::endl;
    *this = other;
}

Dog& Dog::operator=(const Dog& other) {
    std::cout << "Dog Assignment Operator" << std::endl;
    if (this != &other)
        Animal::operator=(other); 
    return *this;
}

Dog::~Dog() {
    std::cout << "Dog Destructor" << std::endl;
}

void Dog::makeSound() const {
    std::cout << "Woof Woof!" << std::endl;
}