/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-si- <oait-si-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 15:16:10 by oait-si-          #+#    #+#             */
/*   Updated: 2025/12/14 17:54:05 by oait-si-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Character.h"

Character::Character(std::string const & name) : _name(name)
{
    
    for (int i = 0; i < 4; i++)
        this->_inventory[i] = NULL;
}

Character::Character(const Character& other) : _name(other._name)
{
  
    for (int i = 0; i < 4; i++)
    {
        if (other._inventory[i])
            this->_inventory[i] = other._inventory[i]->clone();
        else
            this->_inventory[i] = NULL;
    }
}

Character& Character::operator=(const Character& other)
{
    if (this != &other)
    {
        this->_name = other._name;
        
        for (int i = 0; i < 4; i++)
        {
            if (this->_inventory[i])
                delete this->_inventory[i];
        }
       
        for (int i = 0; i < 4; i++)
        {
            if (other._inventory[i])
                this->_inventory[i] = other._inventory[i]->clone();
            else
                this->_inventory[i] = NULL;
        }
    }
    return *this;
}

Character::~Character()
{
    
    for (int i = 0; i < 4; i++)
    {
        if (this->_inventory[i])
            delete this->_inventory[i];
    }
}

std::string const & Character::getName() const {
    return this->_name;
}

void Character::equip(AMateria* m)
{
    if (!m) return;
    
    for (int i = 0; i < 4; i++)
    {
        if (this->_inventory[i] == NULL)
        {
            this->_inventory[i] = m;
            return;
        }
    }
    
}

void Character::unequip(int idx)
{
    if (idx >= 0 && idx < 4)
        this->_inventory[idx] = NULL; 

}

void Character::use(int idx, ICharacter& target)
{
    if (idx >= 0 && idx < 4 && this->_inventory[idx])
    {
        this->_inventory[idx]->use(target);
    }
}