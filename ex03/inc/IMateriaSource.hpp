/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theog <theog@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 18:05:58 by tcohen            #+#    #+#             */
/*   Updated: 2025/02/19 15:04:03 by theog            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "AMateria.hpp"

class IMateriaSource
{
    protected:
		AMateria* _inventory[4];
		int _inventorySize;
		AMateria** _MateriaThrash;
        int _thrash_size;

    public:
        IMateriaSource(void);
        IMateriaSource(const IMateriaSource &copy);
        IMateriaSource& operator=(const IMateriaSource &copy);
        virtual ~IMateriaSource() {}
        virtual void learnMateria(AMateria*) = 0;
        virtual AMateria* createMateria(std::string const & type) = 0;
};