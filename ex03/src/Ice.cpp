/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcohen <tcohen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 18:05:43 by tcohen            #+#    #+#             */
/*   Updated: 2025/02/21 20:50:47 by tcohen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Ice.hpp" 

Ice::Ice(void): AMateria("ice")
{

}
Ice::Ice(const Ice &copy): AMateria(copy)
{

}
Ice& Ice::operator=(const Ice &copy)
{
	if(this != &copy)
		this->_type = copy._type;
	return (*this);
}
Ice::~Ice(void)
{

}
AMateria* Ice::clone() const
{
	return(new(std::nothrow) Ice);
}

void Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at "<< target.getName() << " *" << std::endl;
}