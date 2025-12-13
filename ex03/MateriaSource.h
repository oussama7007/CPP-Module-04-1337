/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-si- <oait-si-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 15:59:44 by oait-si-          #+#    #+#             */
/*   Updated: 2025/12/13 16:47:51 by oait-si-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#pragma once
#include "IMateriaSource.h"

class MateriaSource : public IMateriaSource
{
    private:
        AMateria* templates[4]; // Stores the "blueprints"

    public:
        MateriaSource();
        MateriaSource(const MateriaSource& other);
        MateriaSource& operator=(const MateriaSource& other);
        virtual ~MateriaSource();

        virtual void learnMateria(AMateria*);
        virtual AMateria* createMateria(std::string const & type);
};