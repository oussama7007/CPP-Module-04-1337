/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-si- <oait-si-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 13:28:49 by oait-si-          #+#    #+#             */
/*   Updated: 2025/12/09 14:14:38 by oait-si-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.h"

Animal::Animal() : type("Animal") {
    std::cout << "Animal Default Constructor" << std::endl;
}

Animal::Animal(const Animal& obj) {
    std::cout << "Animal Copy Constructor" << std::endl;
    *this = obj;
}

Animal& Animal::operator=(const Animal& obj) {
    std::cout << "Animal Assignation operator" << std::endl;
    if (this != &obj)
        this->type = obj.type;
    return *this;
}

Animal::~Animal() {
    std::cout << "Animal Destructor" << std::endl;
}

void Animal::makeSound() const {
    std::cout << "* Generic Animal Sound *" << std::endl;
}

std::string Animal::getType() const {
    return this->type;
}