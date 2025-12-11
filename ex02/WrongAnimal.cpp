/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-si- <oait-si-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 15:58:39 by oait-si-          #+#    #+#             */
/*   Updated: 2025/12/11 15:58:42 by oait-si-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "WrongAnimal.h"

WrongAnimal::WrongAnimal() : type("WrongAnimal") {
    std::cout << "WrongAnimal Constructor" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& other) {
    *this = other;
    std::cout << "WrongAnimal Copy Constructor" << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other) {
    if (this != &other)
        this->type = other.type;
    std::cout << "WrongAnimal Assignment Operator" << std::endl;
    return *this;
}

WrongAnimal::~WrongAnimal() {
    std::cout << "WrongAnimal Destructor" << std::endl;
}

void WrongAnimal::makeSound() const {
    std::cout << "* Wrong Generic Animal Sound *" << std::endl;
}

std::string WrongAnimal::getType() const {
    return this->type;
}