/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcohen <tcohen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 18:18:57 by tcohen            #+#    #+#             */
/*   Updated: 2025/02/14 16:48:28 by tcohen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void) : Animal()
{
	std::cout << "Dog default constructor called" << std::endl;
	this->type = "Dog";
	this->tab_ideas = NULL;
	try
	{
		this->tab_ideas = new Brain;
	}
	catch(const std::exception& e)
	{
		std::cout << "New failed for tab_ideas in Dog class because " << e.what() << std::endl;
		this->largeArray = NULL;
		return;
	}
	this->largeArray = NULL;
	try
	{
		//this->largeArray = new int[10000000000000000];  // Tente d'allouer un tableau gigantesque
		this->largeArray = new int [10];
	}
	catch(std::bad_alloc &e)
	{
		std::cout << "New failed for LargeArray in Dog class because " << e.what() << std::endl;
		delete this->tab_ideas;
		this->tab_ideas = NULL;
	}
}
Dog::Dog(const Dog &copy) : Animal(copy)
{
	std::cout << "Dog Copy constructor called" << std::endl;
	*this = copy;
}
Dog& Dog::operator=(const Dog &copy)
{
	if (this != &copy)
	{
		this->type = copy.type;
		for (int i = 0; i < 100; i++)
			this->tab_ideas[i] = copy.tab_ideas[i];
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


