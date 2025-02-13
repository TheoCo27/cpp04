/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcohen <tcohen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 18:18:44 by tcohen            #+#    #+#             */
/*   Updated: 2025/02/13 20:29:33 by tcohen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(void) : type("King-Kong")
{
	std::cout << "Animal default constructor called" << std::endl;
}
Animal::Animal(std::string type) : type(type)
{
	std::cout << "Animal type constructor called" << std::endl; 
}
Animal::Animal(const Animal &copy)
{
	*this = copy;
}
Animal& Animal::operator=(const Animal &copy)
{
	if (this != &copy)
		this->type = copy.type;
	return (*this);
}
Animal::~Animal(void)
{
	std::cout << "Animal Destructor called" << std::endl;
}
void Animal::makeSound(void) const
{
	std::cout << "Woop Woop it's da sound of Animal" << std::endl;
}

std::string Animal::getType(void) const
{
	return (this->type);
}