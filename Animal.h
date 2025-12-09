/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-si- <oait-si-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 09:48:52 by oait-si-          #+#    #+#             */
/*   Updated: 2025/12/09 14:14:28 by oait-si-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef ANIMAL_HPP
#define ANIMAL_HPP


#include <iostream>

class Animal {
    protected:
        std::string type; 

    public:
        Animal();
        Animal(const Animal& other);
        Animal& operator=(const Animal& other);
        virtual ~Animal(); 

        virtual void makeSound() const;
        std::string getType() const;
};


#endif 