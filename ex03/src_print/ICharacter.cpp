/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcohen <tcohen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 15:27:34 by tcohen            #+#    #+#             */
/*   Updated: 2025/02/21 21:36:06 by tcohen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ICharacter.hpp"

ICharacter::ICharacter(void)
{
	std::cout << "ICharacter default cpnstructor called" << std::endl;
}

ICharacter::ICharacter(const ICharacter &copy)
{
	(void)copy;
	std::cout << "ICharacter copy constructor called" << std::endl;
}
ICharacter& ICharacter::operator=(const ICharacter &copy)
{
	(void)copy;
	std::cout << "Icharcarter operator assignement called" << std::endl;
	return (*this);
}

// ICharacter::~ICharacter(void)
// {
// 	std::cout << "Icharcarter destructor called" << std::endl;

// }