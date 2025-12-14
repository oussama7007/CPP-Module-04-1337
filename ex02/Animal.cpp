/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-si- <oait-si-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 16:18:11 by oait-si-          #+#    #+#             */
/*   Updated: 2025/12/14 15:41:16 by oait-si-         ###   ########.fr       */
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



std::string Animal::getType() const {
    return this->type;
}