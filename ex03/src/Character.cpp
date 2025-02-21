/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcohen <tcohen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 18:05:51 by tcohen            #+#    #+#             */
/*   Updated: 2025/02/21 20:49:20 by tcohen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../inc/Character.hpp"

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

Character::Character(std::string name) : ICharacter()
{
    this->_Name = name;
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
    for(int i = 0; i < copy._inventorySize; i++)
    {
        if (copy._inventory[i])
            this->_inventory[i] = copy._inventory[i]->clone();
    }
}

Character& Character::operator=(const Character &copy)
{
    if (this == &copy)
        return *this;
    
    this->_Name = copy._Name;
    this->_error = copy._error;
    this->clean_thrash();
    
    for(int i = 0; i < 4; i++)
    {
        if (this->_inventory[i])
            delete this->_inventory[i];
        this->_inventory[i] = NULL;
    }
    
    this->_inventorySize = copy._inventorySize;
    for(int i = 0; i < copy._inventorySize; i++)
    {
        if (copy._inventory[i])
            this->_inventory[i] = copy._inventory[i]->clone();
    }
    
    return *this;
}

static void erase_double_ptr(AMateria **tab, AMateria *ptr, int tab_size, int start)
{
	for(int i = start + 1; i < tab_size; i++)
	{
		if (ptr == tab[i])
			tab[i] = NULL;
	}
}

Character::~Character(void)
{
    this->clean_thrash();
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

std::string const & Character::getName(void) const
{
    return this->_Name;
}

static bool check_intab(AMateria **tab, int tab_size, AMateria *ptr)
{
	for(int i = 0; i < tab_size; i++)
	{
		if (tab[i] == ptr)
			return (1);
	}
	return (0);
}

void Character::clean_thrash(void)
{
	if (this->_MateriaThrash == NULL)
		return ;
    for (int i = 0; i < this->_ThrashSize; i++)
    {
        if (this->_MateriaThrash[i])
        {
			if(check_intab(this->_inventory, 4, this->_MateriaThrash[i]) == 1)
			{
				this->_MateriaThrash[i] = NULL;
				continue;
			}
			erase_double_ptr(this->_MateriaThrash, this->_MateriaThrash[i], this->_ThrashSize, i);
			delete this->_MateriaThrash[i];
			this->_MateriaThrash[i] = NULL;
		}
    }
	if (this->_MateriaThrash)
    	delete[] this->_MateriaThrash;
    this->_MateriaThrash = NULL;
    this->_ThrashSize = 0;
}

int Character::add_to_thrash(AMateria *m)
{
    AMateria **thrash_temp = new(std::nothrow) AMateria*[this->_ThrashSize + 1];
    if (!thrash_temp)
        return (this->_error = 1, 1);
    if(this->_MateriaThrash)
    {	for (int i = 0; i < this->_ThrashSize; i++)
        	{thrash_temp[i] = this->_MateriaThrash[i];}
		delete[] this->_MateriaThrash;
	}
    thrash_temp[this->_ThrashSize] = m;
    this->_MateriaThrash = thrash_temp;
    this->_ThrashSize++;
    
    return 0;
}

void Character::equip(AMateria* m)
{
	if(m == NULL)
	{
		return;
	}
    if (this->_inventorySize >= 4)
    {
        return;
    }
    this->_inventory[_inventorySize++] = m;
}

void Character::unequip(int idx)
{
    if (idx >= this->_inventorySize || idx < 0)
    {
        return;
    }
    
    AMateria *toTrash = this->_inventory[idx];
    for(int i = idx; i < this->_inventorySize - 1; i++)
        this->_inventory[i] = this->_inventory[i + 1];
    
    this->_inventory[this->_inventorySize - 1] = NULL;
    this->_inventorySize--;
    add_to_thrash(toTrash);
}

void Character::use(int idx, ICharacter& target)
{
    if (idx >= this->_inventorySize || idx < 0 || !this->_inventory[idx])
    {
        return;
    }
    this->_inventory[idx]->use(target);
}

void Character::print_inventory(void)
{
    // for(int i = 0; i < 4; i++)
    // {
    //     if (this->_inventory[i])
    //         std::cout << "Index: " << i << " is type " << this->_inventory[i]->getType() << std::endl;
    // 
    for(int i = 0; i < 4; i++)
    {
        if (this->_inventory[i])
            std::cout << "Index: " << i << " address: " << this->_inventory[i] << std::endl;
    }
}

void Character::print_thrash_adress(void)
{
    // for(int i = 0; i < 4; i++)
    // {
    //     if (this->_inventory[i])
    //         std::cout << "Index: " << i << " is type " << this->_inventory[i]->getType() << std::endl;
    // 
    for(int i = 0; i < this->_ThrashSize; i++)
    {
        if (this->_MateriaThrash[i])
            std::cout << "Index: " << i << " adsress: " << this->_MateriaThrash[i] << std::endl;
    }
}