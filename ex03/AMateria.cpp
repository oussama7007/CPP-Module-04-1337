/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-si- <oait-si-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 18:05:09 by oait-si-          #+#    #+#             */
/*   Updated: 2025/12/15 19:02:09 by oait-si-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "AMateria.h"
#include "ICharacter.h" 


AMateria::AMateria() : type("default") {
    
}

AMateria::AMateria(std::string const & type) : type(type)
{
   
}

AMateria::AMateria(const AMateria& other)
{
   
    *this = other;
}

AMateria& AMateria::operator=(const AMateria& other)
{
    
    (void)other;
    return *this;
}

AMateria::~AMateria()
{
}

std::string const & AMateria::getType() const
{
    return this->type;
}

void AMateria::use(ICharacter& target)
{
    (void)target;
}