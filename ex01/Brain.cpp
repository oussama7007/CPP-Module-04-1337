/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-si- <oait-si-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 15:20:02 by oait-si-          #+#    #+#             */
/*   Updated: 2025/12/13 17:09:26 by oait-si-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.h"

Brain::Brain()
{
    std::cout << "Brain Default Constructor called" << std::endl;
}


Brain::Brain(const Brain& obj)
{
    std::cout << "Brain Copy Constructor called" << std::endl;

    for (int i = 0; i < 100; i++) {
        this->ideas[i] = obj.ideas[i];
    }
}


Brain& Brain::operator=(const Brain& obj)
{
    std::cout << "Brain Copy Assignment Operator called" << std::endl;
    if (this != &obj) 
    {
        for (int i = 0; i < 100; i++) {
            this->ideas[i] = obj.ideas[i];
        }
    }
    return *this;
}

Brain::~Brain()
{
    std::cout << "Brain Destructor called" << std::endl;
}