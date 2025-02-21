/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcohen <tcohen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 01:24:27 by theog             #+#    #+#             */
/*   Updated: 2025/02/21 15:46:17 by tcohen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "AMateria.hpp"

class IMateriaSource
{
	// protected:
	// 	IMateriaSource(void);
	// 	IMateriaSource(const IMateriaSource &copy);
	// 	IMateriaSource& operator=(const IMateriaSource &copy);
    public:
		virtual ~IMateriaSource() {}
		virtual void learnMateria(AMateria*) = 0;
    	virtual AMateria* createMateria(std::string const & type) = 0;
};	