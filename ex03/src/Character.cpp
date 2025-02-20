/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theog <theog@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 18:05:51 by tcohen            #+#    #+#             */
/*   Updated: 2025/02/20 01:42:12 by theog            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Character.hpp"

//public:
Character::Character(void) : ICharacter()
{
	this->_Name = "Slim Shady";
	this->_error = 0;
	this->_ThrashSize = 0;
	this->_inventorySize = 0;
	this->_MateriaThrash = NULL;
	for(int i = 0; i < 4; i++)
		this->_inventory[i] = NULL;

}
Character::Character(const Character &copy) : ICharacter(copy)
{
	this->_Name = copy._Name;
	this->_error = copy._error;
	this->_ThrashSize = 0;
	this->_inventorySize = copy._inventorySize;
	this->_MateriaThrash = NULL;
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
Character& Character::operator=(const Character &copy)
{
	this->_Name = copy._Name;
	this->_error = copy._error;
	this->_ThrashSize = 0;
	this->_inventorySize = copy._inventorySize;
	this->clean_thrash();
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

Character::~Character(void)
{
	this->clean_thrash();
	for(int i = 0; i <= this->_inventorySize; i++)
	{
		if (this->_inventory[i])
			delete this->_inventory[i];
			this->_inventory[i] = NULL;
	}
}

std::string const & Character::getName(void) const
{
	return(this->_Name);
}
//method

int Character::get_materia_index(AMateria *m)
{
	for(int i = 0; i < 4; i++)
	{
		if (this->_inventory[i] == m)
			return (i);
	}
	return(-1);
}

void Character::clean_thrash(void)
{
	if (this->_ThrashSize == 0)
		return;
	for (int i = 0; i < this->_ThrashSize; i++)
	{
		if(this->_MateriaThrash[i])
			delete this->_MateriaThrash[i];
		this->_MateriaThrash[i] = NULL;
	}
	delete [] this->_MateriaThrash;
	this->_MateriaThrash = NULL;
	this->_ThrashSize = 0;
}

int Character::add_to_thrash(AMateria *m)
{	
	AMateria **thrash_temp;

	thrash_temp = new(std::nothrow) AMateria *[this->_ThrashSize + 1];
	if(!thrash_temp)
		return(this->_error = 1, 1);
	for(int i = 0; i < this->_ThrashSize + 1; i++)
		thrash_temp[i] = this->_MateriaThrash[i];
	thrash_temp[this->_ThrashSize] = m;
	if(!this->_MateriaThrash != NULL)
		delete [] this->_MateriaThrash;
	this->_MateriaThrash = thrash_temp;
	this->_ThrashSize++;
}

void Character::equip(AMateria* m)
{
	if (this->_inventorySize == 3)
	{
		std::cout << "You're inventory is full" << std::endl;
		return;
	}
	this->_inventory[_inventorySize] = m;
	this->_inventorySize++;
	std::cout << "Materia of type " << m->getType() << " has been succesfully added to inventory" << std::endl;
}
void Character::unequip(int idx)
{
	if (idx > this->_inventorySize || idx < 0)
	{
		std::cout << "Invalid index detected" << std::endl;
		return;
	}
	if (idx == _inventorySize)
	{
		add_to_thrash(this->_inventory[idx]);
		this->_inventory[idx] = NULL;
		this->_inventorySize--;
	}
	else
	{
		add_to_thrash(this->_inventory[idx]);
		for(int i = idx; i <= this->_inventorySize; i++)
			this->_inventory[i] = this->_inventory[i + 1];
		this->_inventory[idx] = NULL;
		this->_inventorySize--;	
	}
	std::cout << "Materia of type " << this->_inventory[idx]->getType() << " has been succesfully removed from inventory" << std::endl;
}
void Character::use(int idx, Character& target)
{
	if (idx > this->_inventorySize || idx < 0)
	{
		std::cout << "Invalid index detected" << std::endl;
		return;
	}

	std::cout << "I " << this->_Name << " ";
	this->_inventory[idx]->use(target);
}