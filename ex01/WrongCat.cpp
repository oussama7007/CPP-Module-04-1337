/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-si- <oait-si-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 15:19:41 by oait-si-          #+#    #+#             */
/*   Updated: 2025/12/10 15:21:12 by oait-si-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.h"

WrongCat::WrongCat() : WrongAnimal() {
    this->type = "WrongCat";
    std::cout << "WrongCat Constructor" << std::endl;
}

WrongCat::WrongCat(const WrongCat& other) : WrongAnimal(other) {
    *this = other;
    std::cout << "WrongCat Copy Constructor" << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& other) {
    if (this != &other)
        WrongAnimal::operator=(other);
    std::cout << "WrongCat Assignment Operator" << std::endl;
    return *this;
}

WrongCat::~WrongCat() {
    std::cout << "WrongCat Destructor" << std::endl;
}

void WrongCat::makeSound() const {
    std::cout << "Wrong Meow!" << std::endl;
}