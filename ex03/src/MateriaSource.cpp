/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theog <theog@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 18:05:54 by tcohen            #+#    #+#             */
/*   Updated: 2025/02/20 14:27:01 by theog            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/AMateria.hpp"
#include "../inc/MateriaSource.hpp"

//public:
MateriaSource::MateriaSource(void) : IMateriaSource()
{
	this->_error = 0;
	this->_inventorySize = 0;
	for(int i = 0; i < 4; i++)
		this->_inventory[i] = NULL;
}
MateriaSource::MateriaSource(const MateriaSource &copy) : IMateriaSource(copy)
{
	this->_error = copy._error;
	this->_inventorySize = copy._inventorySize;
	for(int i = 0; i < 4; i++)
		this->_inventory[i] = NULL;
	for(int i = 0; i <= copy._inventorySize; i++)
	{
		if ((this->_inventory[i] = copy._inventory[i]->clone()) == NULL)
		{
			this->_error = 1;
			for(int i = 0; i <= this->_inventorySize; i++)
			{
				if (this->_inventory[i])
					delete this->_inventory[i];
				this->_inventory[i] = NULL;
			}
		}
	}
}
MateriaSource& MateriaSource::operator=(const MateriaSource &copy)
{
	this->_error = copy._error;
	this->_inventorySize = copy._inventorySize;
	for(int i = 0; i < 4; i++)
	{
		if (this->_inventory[i])
			delete this->_inventory[i];
		this->_inventory[i] = NULL;
	}
	for(int i = 0; i <= copy._inventorySize; i++)
	{
		if (copy._inventory[i] && (this->_inventory[i] = copy._inventory[i]->clone()) == NULL)
		{
			this->_error = 1;
			for(int i = 0; i < 4; i++)
			{
				if (this->_inventory[i])
					delete this->_inventory[i];
				this->_inventory[i] = NULL;
			}
		}
	}
}

MateriaSource::~MateriaSource(void)
{
	for(int i = 0; i <= this->_inventorySize; i++)
	{
		if (this->_inventory[i])
			delete this->_inventory[i];
			this->_inventory[i] = NULL;
	}
}
//method

void MateriaSource::learnMateria(AMateria* m)
{
	if (this->_inventorySize == 3)
	{
		std::cout << "You're Materia Source inventory is full" << std::endl;
		return;
	}
	this->_inventory[_inventorySize] = m;
	this->_inventorySize++;
	std::cout << "Materia of type " << m->getType() << " has been succesfully LEARNED" << std::endl;
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
    for(int i = 0; i < 4; i++)
    {
        if (this->_inventory[i] && this->_inventory[i]->getType() == type)
            return(this->_inventory[i]->clone());
    }
    std::cout << "This type hasn t been learned already" << std::endl;
    return (NULL);
}