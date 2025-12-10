/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-si- <oait-si-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 15:19:59 by oait-si-          #+#    #+#             */
/*   Updated: 2025/12/10 15:46:47 by oait-si-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP


class Brain 
{
    public:
        Brain();
        Brain(const Brain& obj);
        Brain&  operator=(const Brain& obj);
        ~Brain();
};


#endif 