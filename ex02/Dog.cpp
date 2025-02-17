/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcohen <tcohen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 18:18:57 by tcohen            #+#    #+#             */
/*   Updated: 2025/02/16 22:42:07 by tcohen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"


Dog::Dog(void) : Animal()
{
	std::cout << "Dog default constructor called" << std::endl;
	this->type = "Dog";
	this->tab_ideas = NULL;
	this->largeArray = NULL;
	try
	{
		this->tab_ideas = new Brain;
	}
	catch(const std::exception& e)
	{
		std::cout << "New failed for tab_ideas in Dog class because " << e.what() << std::endl;
		return;
	}
	try
	{
		//this->largeArray = new int[10000000000000000];  // Tente d'allouer un tableau gigantesque
		this->largeArray = new int [L_ARRAY];
	}
	catch(std::bad_alloc &e)
	{
		std::cout << "New failed for LargeArray in Dog class because " << e.what() << std::endl;
		delete this->tab_ideas;
		this->tab_ideas = NULL;
	}
	for (int i = 0; i < L_ARRAY; i++)
        this->largeArray[i] = 0;
}
Dog::Dog(const Dog &copy) : Animal(copy)
{
    std::cout << "Dog Copy constructor called" << std::endl;
	this->tab_ideas = NULL;
	this->largeArray = NULL;
	try 
	{
		this->tab_ideas = new Brain(*copy.tab_ideas); // Copie en profondeur
	}
	catch(const std::bad_alloc &e)
	{
		std::cout << "New failed for tab_ideas in Dog class because " << e.what() << std::endl;
		return;	
	}
	try
	{
		this->largeArray = new int[L_ARRAY];	
	}
	catch(const std::exception& e)
	{
		std::cerr <<"New failed for LargeArray in Dog class because " << e.what() << '\n';
		delete this->tab_ideas;
		this->tab_ideas = NULL;
		return;
	}
    for (int i = 0; i < L_ARRAY; i++)
        this->largeArray[i] = copy.largeArray[i];
}
Dog& Dog::operator=(const Dog &copy)
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
			std::cout << "New failed for tab_ideas in Dog class because " << e.what() << std::endl;			
			this->tab_ideas = NULL;	
		}
        for (int i = 0; i < L_ARRAY; i++)
            this->largeArray[i] = copy.largeArray[i];
    }
    return (*this);
}

Dog::~Dog(void)
{
	std::cout << "Dog Destructor called" << std::endl;
	if (this->tab_ideas)
		delete this->tab_ideas;
	if (this->largeArray)
		delete [] this->largeArray;
}

void Dog::makeSound(void) const
{
	std::cout << "WOOF WOOF dat's da sound of DoggyDog" << std::endl;
}

Brain *Dog::getTab_ideas(void)
{
	return (this->tab_ideas);
}


