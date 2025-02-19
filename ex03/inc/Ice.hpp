/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theog <theog@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 18:05:46 by tcohen            #+#    #+#             */
/*   Updated: 2025/02/19 15:04:40 by theog            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "AMateria.hpp"

class Ice : public AMateria
{
    Ice(void);
    Ice(const Ice &copy);
    Ice& operator=(const Ice &copy);
    ~Ice(void);
    virtual AMateria* clone() const;
    virtual void use(ICharacter& target);
};