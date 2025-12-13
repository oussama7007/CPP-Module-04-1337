/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-si- <oait-si-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 14:48:15 by oait-si-          #+#    #+#             */
/*   Updated: 2025/12/13 14:48:20 by oait-si-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "ICharacter.h"
#include "AMateria.h"

class Character : public ICharacter
{
    private:
        std::string _name;
        AMateria* _inventory[4]; // The inventory array

    public:
        Character(std::string const & name);
        Character(const Character& other);
        Character& operator=(const Character& other);
        virtual ~Character();

        virtual std::string const & getName() const;
        virtual void equip(AMateria* m);
        virtual void unequip(int idx);
        virtual void use(int idx, ICharacter& target);
};