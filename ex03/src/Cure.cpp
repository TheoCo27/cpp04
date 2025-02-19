/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcohen <tcohen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 18:05:37 by tcohen            #+#    #+#             */
/*   Updated: 2025/02/19 20:47:17 by tcohen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Cure.hpp"

Cure::Cure(void): AMateria("cure")
{
	std::cout << "Cure defaut constructor called" << std::endl;
}
Cure::Cure(const Cure &copy): AMateria(copy)
{
	std::cout << "Cure copy constructor called" << std::endl;
}
Cure& Cure::operator=(const Cure &copy)
{
	std::cout << "Cure assignmement operator called" << std::endl;
	if(this != &copy)
		this->_type = copy._type;
	return (*this);
}
Cure::~Cure(void)
{
	std::cout << "Cure defaut destructor called" << std::endl;
}
AMateria* Cure::clone() const
{
	std::cout << "Cure clone called" << std::endl;
	return (new Cure);
}

void Cure::use(ICharacter& target)
{
	std::cout << " heals "<< target.getName() << "'s wounds" << std::endl;
}