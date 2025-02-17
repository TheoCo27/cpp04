/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcohen <tcohen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 18:19:23 by tcohen            #+#    #+#             */
/*   Updated: 2025/02/13 20:30:40 by tcohen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void) : type("King-Kong")
{
	std::cout << "WrongAnimal default constructor called" << std::endl;
}
WrongAnimal::WrongAnimal(std::string type) : type(type)
{
	std::cout << "WrongAnimal type constructor called" << std::endl; 
}
WrongAnimal::WrongAnimal(const WrongAnimal &copy)
{
	*this = copy;
}
WrongAnimal& WrongAnimal::operator=(const WrongAnimal &copy)
{
	if (this != &copy)
		this->type = copy.type;
	return (*this);
}
WrongAnimal::~WrongAnimal(void)
{
	std::cout << "WrongAnimal Destructor called" << std::endl;
}
void WrongAnimal::makeSound(void) const
{
	std::cout << "SKUUUU SKUUUUU it's da sound of WrongAnimal" << std::endl;
}