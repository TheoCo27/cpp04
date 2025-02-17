/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcohen <tcohen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 18:18:51 by tcohen            #+#    #+#             */
/*   Updated: 2025/02/16 23:02:29 by tcohen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"


Cat::Cat(void) : Animal()
{
	std::cout << "Cat default constructor called" << std::endl;
	this->type = "Cat";
	this->tab_ideas = NULL;
	try
	{
		this->tab_ideas = new Brain;
	}
	catch(const std::exception& e)
	{
		std::cout << "New failed for tab_ideas in Cat class because " << e.what() << std::endl;
		return;
	}
}
Cat::Cat(const Cat &copy) : Animal(copy)
{
    std::cout << "Cat Copy constructor called" << std::endl;
	this->tab_ideas = NULL;
	try 
	{
		this->tab_ideas = new Brain(*copy.tab_ideas); // Copie en profondeur
	}
	catch(const std::bad_alloc &e)
	{
		std::cout << "New failed for tab_ideas in Cat class because " << e.what() << std::endl;
		return;	
	}
}
Cat& Cat::operator=(const Cat &copy)
{
    if (this != &copy)
    {
        this->type = copy.type;

        // Supprimer l'ancien Brain et en créer un nouveau
        delete this->tab_ideas;
		try
        {this->tab_ideas = new Brain(*copy.tab_ideas);}
		catch(const std::bad_alloc &e)
		{
			std::cout << "New failed for tab_ideas in Cat class because " << e.what() << std::endl;			
			this->tab_ideas = NULL;	
		}
    }
    return (*this);
}

Cat::~Cat(void)
{
	std::cout << "Cat Destructor called" << std::endl;
	if (this->tab_ideas)
		delete this->tab_ideas;
}

void Cat::makeSound(void) const
{
	std::cout << "MEOW MEOW dat's da sound of CattyCat" << std::endl;
}

Brain *Cat::getTab_ideas(void)
{
	return (this->tab_ideas);
}