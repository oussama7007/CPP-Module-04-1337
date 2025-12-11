/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-si- <oait-si-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 16:02:23 by oait-si-          #+#    #+#             */
/*   Updated: 2025/12/11 16:25:50 by oait-si-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>

class Brain 
{
    private:
        std::string ideas[100];
    public:
        Brain();
        Brain(const Brain& obj);
        Brain&  operator=(const Brain& obj);
        ~Brain();
};


#endif 