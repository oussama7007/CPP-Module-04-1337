/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-si- <oait-si-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 15:59:53 by oait-si-          #+#    #+#             */
/*   Updated: 2025/12/13 15:59:55 by oait-si-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* MateriaSource.cpp */
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
        // Delete old templates
        for (int i = 0; i < 4; i++) {
            if (this->templates[i])
                delete this->templates[i];
        }
        // Copy new templates
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
            this->templates[i] = m; // Store the pointer
            return;
        }
    }
    // If full, we should probably delete m so we don't leak it, 
    // but the subject is vague. Standard practice is to do nothing or delete.
    // Ideally: delete m; std::cout << "Source full" << std::endl;
}

AMateria* MateriaSource::createMateria(std::string const & type) {
    for (int i = 0; i < 4; i++) {
        if (this->templates[i] && this->templates[i]->getType() == type)
            return this->templates[i]->clone(); // Return a CLONE, not the original
    }
    return 0; // Return 0 if unknown type
}