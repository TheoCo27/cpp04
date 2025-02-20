/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theog <theog@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 18:05:58 by tcohen            #+#    #+#             */
/*   Updated: 2025/02/20 01:28:01 by theog            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "AMateria.hpp"

class MateriaSource
{
    protected:
		AMateria* _inventory[4];
		int _inventorySize;
		AMateria** _MateriaThrash;
        int _thrash_size;

    public:
        MateriaSource(void);
        MateriaSource(const MateriaSource &copy);
        MateriaSource& operator=(const MateriaSource &copy);
        virtual ~MateriaSource(void);
        virtual void learnMateria(AMateria*);
        virtual AMateria* createMateria(std::string const & type);
};