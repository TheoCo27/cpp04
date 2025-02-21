/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcohen <tcohen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 15:28:10 by tcohen            #+#    #+#             */
/*   Updated: 2025/02/21 20:51:13 by tcohen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/IMateriaSource.hpp"

IMateriaSource::IMateriaSource(void)
{

}
IMateriaSource::IMateriaSource(const IMateriaSource &copy)
{
	(void)copy;
}
IMateriaSource& IMateriaSource::operator=(const IMateriaSource &copy)
{
	(void)copy;
	return (*this);
}