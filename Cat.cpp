/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-si- <oait-si-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 13:53:59 by oait-si-          #+#    #+#             */
/*   Updated: 2025/12/09 14:32:26 by oait-si-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.h"

Cat::Cat() :type("Cat"), Animal()
{
    // message
}

Cat::Cat(const Cat& obj): Animal(obj)
{
    // message
    *this = obj;
}

Cat& operator=(const Cat& obj) 
{
    if(this != obj)
        Animel::operator(obj);
}