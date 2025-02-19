/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcohen <tcohen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 18:05:43 by tcohen            #+#    #+#             */
/*   Updated: 2025/02/19 20:45:59 by tcohen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Ice.hpp" 

Ice::Ice(void): AMateria("Ice")
{
	std::cout << "Ice defaut constructor called" << std::endl;
}
Ice::Ice(const Ice &copy): AMateria(copy)
{
	std::cout << "Ice copy constructor called" << std::endl;
}
Ice& Ice::operator=(const Ice &copy)
{
	std::cout << "Ice assignmement operator called" << std::endl;
	if(this != &copy)
		this->_type = copy._type;
	return (*this);
}
Ice::~Ice(void)
{
	std::cout << "Ice defaut destructor called" << std::endl;
}
AMateria* Ice::clone() const
{
	std::cout << "Ice clone called" << std::endl;
	return(new Ice);
}

void Ice::use(ICharacter& target)
{
	std::cout << " heals "<< target.getName() << "'s wounds" << std::endl;
}