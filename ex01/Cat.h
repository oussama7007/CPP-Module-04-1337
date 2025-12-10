/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-si- <oait-si-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 15:19:54 by oait-si-          #+#    #+#             */
/*   Updated: 2025/12/10 15:34:43 by oait-si-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.h"

class Cat : public Animal
{
    public:
        Cat();
        Cat(const Cat& obj);
        Cat& operator=(const Cat& obj);
        ~Cat();

        void makeSound() const;
};
#endif 