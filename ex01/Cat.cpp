/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcohen <tcohen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 18:18:51 by tcohen            #+#    #+#             */
/*   Updated: 2025/02/14 14:14:33 by tcohen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void) : Animal()
{
	std::cout << "Cat default constructor called" << std::endl;
	this->type = "Cat";
	this->tab_ideas = NULL;
	this->tab_ideas = new Brain;
}
Cat::Cat(const Cat &copy) : Animal(copy)
{
	std::cout << "Cat Copy constructor called" << std::endl;
	*this = copy;

}
Cat& Cat::operator=(const Cat &copy)
{
	if (this != &copy)
	{
		this->type = copy.type;
		for (int i = 0; i < 100; i++)
			this->tab_ideas[i] = copy.tab_ideas[i];
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