/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcohen <tcohen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 15:27:34 by tcohen            #+#    #+#             */
/*   Updated: 2025/02/21 20:51:00 by tcohen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ICharacter.hpp"

ICharacter::ICharacter(void)
{

}

ICharacter::ICharacter(const ICharacter &copy)
{
	(void)copy;
}
ICharacter& ICharacter::operator=(const ICharacter &copy)
{
	(void)copy;
	return (*this);
}