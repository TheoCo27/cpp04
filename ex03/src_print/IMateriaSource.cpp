/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcohen <tcohen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 15:28:10 by tcohen            #+#    #+#             */
/*   Updated: 2025/02/21 15:43:52 by tcohen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/IMateriaSource.hpp"

IMateriaSource::IMateriaSource(void)
{
	std::cout << "IMateriaSource default contructor called" << std::endl;
}
IMateriaSource::IMateriaSource(const IMateriaSource &copy)
{
	std::cout << "IMateriaSource copy constructor called" << std::endl;
	(void)copy;
}
IMateriaSource& IMateriaSource::operator=(const IMateriaSource &copy)
{
	(void)copy;
	std::cout << "IMateriaSource operator assignememnt called" << std::endl;
	return (*this);
}