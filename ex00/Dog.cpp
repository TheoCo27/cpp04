/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcohen <tcohen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 18:18:57 by tcohen            #+#    #+#             */
/*   Updated: 2025/02/13 20:55:07 by tcohen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void) : Animal()
{
	std::cout << "Dog default constructor called" << std::endl;
	this->type = "Dog";
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
	}
	return (*this);
}

Dog::~Dog(void)
{
	std::cout << "Dog Destructor called" << std::endl;
}

void Dog::makeSound(void) const
{
	std::cout << "WOOF WOOF dat's da sound of DoggyDog" << std::endl;
}

