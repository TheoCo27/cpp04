/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcohen <tcohen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 18:05:54 by tcohen            #+#    #+#             */
/*   Updated: 2025/02/21 21:29:55 by tcohen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/AMateria.hpp"
#include "../inc/MateriaSource.hpp"

//public:
MateriaSource::MateriaSource(void) : IMateriaSource()
{
	std::cout << "MateriaSource default constructor called" << std::endl;
	this->_error = 0;
	this->_inventorySize = 0;
	for(int i = 0; i < 4; i++)
		this->_inventory[i] = NULL;
}
MateriaSource::MateriaSource(const MateriaSource &copy) : IMateriaSource(copy)
{
	std::cout << "MateriaSource copy constructor called" << std::endl;
	this->_error = copy._error;
	this->_inventorySize = copy._inventorySize;
	for(int i = 0; i < 4; i++)
		this->_inventory[i] = NULL;
	for(int i = 0; i < copy._inventorySize; i++)
	{
		if ((this->_inventory[i] = copy._inventory[i]->clone()) == NULL)
		{
			this->_error = 1;
			for(int i = 0; i < this->_inventorySize; i++)
			{
				if (this->_inventory[i])
					delete this->_inventory[i];
				this->_inventory[i] = NULL;
			}
			break;
		}
	}
}
MateriaSource& MateriaSource::operator=(const MateriaSource &copy)
{
	std::cout << "MateriaSource operator assignement called" << std::endl;
	this->_error = copy._error;
	this->_inventorySize = copy._inventorySize;
	for(int i = 0; i < 4; i++)
	{
		if (this->_inventory[i])
			delete this->_inventory[i];
		this->_inventory[i] = NULL;
	}
	for(int i = 0; i < copy._inventorySize; i++)
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
			break;
		}
	}
    return (*this);
}

static void erase_double_ptr(AMateria **tab, AMateria *ptr, int tab_size, int start)
{
	for(int i = start + 1; i < tab_size; i++)
	{
		if (ptr == tab[i])
			tab[i] = NULL;
	}
}

MateriaSource::~MateriaSource(void)
{
	std::cout << "MateriaSource destructor called" << std::endl;

	for(int i = 0; i < 4; i++)
	{
		if (this->_inventory[i])
		{
			erase_double_ptr(this->_inventory, this->_inventory[i], 4, i);
			delete this->_inventory[i];
			this->_inventory[i] = NULL;
		}
	}
}
//method

void MateriaSource::learnMateria(AMateria* m)
{
	if (this->_inventorySize >= 4)
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