/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcohen <tcohen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 18:05:37 by tcohen            #+#    #+#             */
/*   Updated: 2025/02/21 20:56:16 by tcohen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Cure.hpp"

Cure::Cure(void): AMateria("cure")
{

}
Cure::Cure(const Cure &copy): AMateria(copy)
{

}
Cure& Cure::operator=(const Cure &copy)
{
	if(this != &copy)
		this->_type = copy._type;
	return (*this);
}
Cure::~Cure(void)
{
	
}
AMateria* Cure::clone() const
{
	return (new(std::nothrow) Cure);
}

void Cure::use(ICharacter& target)
{
	std::cout << "* heals "<< target.getName() << "'s wounds *" << std::endl;
}