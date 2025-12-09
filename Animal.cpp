/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-si- <oait-si-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 13:28:49 by oait-si-          #+#    #+#             */
/*   Updated: 2025/12/09 13:29:20 by oait-si-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


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