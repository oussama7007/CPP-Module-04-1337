/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-si- <oait-si-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 15:59:53 by oait-si-          #+#    #+#             */
/*   Updated: 2025/12/15 16:11:44 by oait-si-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "MateriaSource.h"

MateriaSource::MateriaSource() {
    for (int i = 0; i < 4; i++)
        this->templates[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource& other) {
    for (int i = 0; i < 4; i++) {
        if (other.templates[i])
            this->templates[i] = other.templates[i]->clone();
        else
            this->templates[i] = NULL;
    }
}

MateriaSource& MateriaSource::operator=(const MateriaSource& other) {
    if (this != &other) {
        
        for (int i = 0; i < 4; i++) {
            if (this->templates[i])
                delete this->templates[i];
        }
      
        for (int i = 0; i < 4; i++) {
            if (other.templates[i])
                this->templates[i] = other.templates[i]->clone();
            else
                this->templates[i] = NULL;
        }
    }
    return *this;
}

MateriaSource::~MateriaSource() {
    for (int i = 0; i < 4; i++) {
        if (this->templates[i])
            delete this->templates[i];
    }
}

void MateriaSource::learnMateria(AMateria* m) {
    if (!m) return;
    for (int i = 0; i < 4; i++) {
        if (this->templates[i] == NULL) {
            this->templates[i] = m; 
            return;
        }
    }

}

AMateria* MateriaSource::createMateria(std::string const & type) {
    for (int i = 0; i < 4; i++) {
        if (this->templates[i] && this->templates[i]->getType() == type)
            return this->templates[i]->clone(); 
    }
    return 0; 
}