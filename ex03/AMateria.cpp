/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-si- <oait-si-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 18:05:09 by oait-si-          #+#    #+#             */
/*   Updated: 2025/12/14 17:47:33 by oait-si-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "AMateria.h"
#include "ICharacter.h" 

AMateria::AMateria(std::string const & type) : type(type)
{
    // std::cout << "AMateria constr" << std::endl;
}

AMateria::AMateria(const AMateria& other)
{
    // std::cout << "AMateria copy constr" << std::endl;
    *this = other;
}

AMateria& AMateria::operator=(const AMateria& other)
{
    
    (void)other;
    return *this;
}

AMateria::~AMateria()
{
    // std::cout << "AMateria destr" << std::endl;
}

std::string const & AMateria::getType() const
{
    return this->type;
}

void AMateria::use(ICharacter& target)
{
    // Base class does nothing, but needs a body to compile.
    // Derived classes will override this.
    (void)target;
}