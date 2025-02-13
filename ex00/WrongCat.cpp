/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcohen <tcohen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 18:19:29 by tcohen            #+#    #+#             */
/*   Updated: 2025/02/13 20:52:21 by tcohen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat(void) : WrongAnimal()
{
	std::cout << "WrongCat default constructor called" << std::endl;
	this->type = "WrongCat";
}
WrongCat::WrongCat(const WrongCat &copy) : WrongAnimal(copy)
{
	std::cout << "WrongCat Copy constructor called" << std::endl;
	*this = copy;
}
WrongCat& WrongCat::operator=(const WrongCat &copy)
{
	if (this != &copy)
	{
		this->type = copy.type;
	}
	return (*this);
}

WrongCat::~WrongCat(void)
{
	std::cout << "WrongCat Destructor called" << std::endl;
}