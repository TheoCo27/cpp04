/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theog <theog@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 18:05:58 by tcohen            #+#    #+#             */
/*   Updated: 2025/02/20 14:28:15 by theog            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "AMateria.hpp"
#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
    protected:
		AMateria*		_inventory[4];
		int				_inventorySize;
		AMateria**		_MateriaThrash;
		int				_ThrashSize;
		int				_error;

    public:
        MateriaSource(void);
        MateriaSource(const MateriaSource &copy);
        MateriaSource& operator=(const MateriaSource &copy);
        virtual ~MateriaSource(void);
        virtual void learnMateria(AMateria *m);
        virtual AMateria* createMateria(std::string const & type);
};