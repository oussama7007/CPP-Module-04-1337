/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-si- <oait-si-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 18:11:16 by oait-si-          #+#    #+#             */
/*   Updated: 2025/12/13 14:46:39 by oait-si-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Cure.h"
#include "ICharacter.h"

Cure::Cure() : AMateria("cure") {}

Cure::Cure(const Cure& other) : AMateria(other) {
    *this = other;
}

Cure& Cure::operator=(const Cure& other) {
    if (this != &other)
        AMateria::operator=(other);
    return *this;
}

Cure::~Cure() {}

AMateria* Cure::clone() const {
    return new Cure(*this);
}

void Cure::use(ICharacter& target) {
    std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}