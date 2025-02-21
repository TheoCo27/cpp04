/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcohen <tcohen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 17:42:44 by tcohen            #+#    #+#             */
/*   Updated: 2025/02/21 20:50:26 by tcohen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/AMateria.hpp"

//protected:
AMateria::AMateria(void)
{

}
AMateria::AMateria(const AMateria &copy) : _type(copy._type)
{

}
AMateria& AMateria::operator=(const AMateria &copy)
{
	if (this != &copy)
		this->_type = copy._type;
	return (*this);
}
//public:
AMateria:: ~AMateria(void)
{

}
AMateria::AMateria(std::string const & type)
{
	this->_type = type;
}
std::string const & AMateria::getType(void) const
{
	return(this->_type);
}
void AMateria::use(ICharacter& target)
{
	std::cout << "Abstract attack against "<< target.getName() << std::endl;
}