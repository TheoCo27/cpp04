/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theog <theog@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 17:42:44 by tcohen            #+#    #+#             */
/*   Updated: 2025/02/20 14:52:31 by theog            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/AMateria.hpp"

//protected:
AMateria::AMateria(void)
{
	std::cout << "Amateria defaut constructor called" << std::endl;
}
AMateria::AMateria(const AMateria &copy) : _type(copy._type)
{
	std::cout << "Amateria copy constructor called" << std::endl;
}
AMateria& AMateria::operator=(const AMateria &copy)
{
	std::cout << "Amateria assignement operator called" << std::endl;
	if (this != &copy)
		this->_type = copy._type;
	return (*this);
}
//public:
AMateria:: ~AMateria(void)
{
	std::cout << "Amateria defaut destructor called" << std::endl;
}
AMateria::AMateria(std::string const & type)
{
	std::cout << "Amateria type constructor called" << std::endl;
	this->_type = type;
}
std::string const & AMateria::getType(void) const
{
	return(this->_type);
}
void AMateria::use(ICharacter& target)
{
	std::cout << "Amateria use function called" << std::endl;
	std::cout << "Abstract attack against "<< target.getName() << std::endl;
}