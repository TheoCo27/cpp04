/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcohen <tcohen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 18:18:51 by tcohen            #+#    #+#             */
/*   Updated: 2025/02/13 20:55:41 by tcohen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void) : Animal()
{
	std::cout << "Cat default constructor called" << std::endl;
	this->type = "Cat";
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
	}
	return (*this);
}

Cat::~Cat(void)
{
	std::cout << "Cat Destructor called" << std::endl;
}

void Cat::makeSound(void) const
{
	std::cout << "MEOW MEOW dat's da sound of CattyCat" << std::endl;
}
