/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcohen <tcohen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 18:05:26 by tcohen            #+#    #+#             */
/*   Updated: 2025/02/19 20:18:51 by tcohen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "ICharacter.hpp"

class AMateria
{
	protected:
		AMateria(void);
		AMateria(const AMateria &copy);
		AMateria& operator=(const AMateria &copy);
		std::string _type;
	public:
		virtual ~AMateria(void);
		AMateria(std::string const & type);
		std::string const & getType(void) const;
		virtual AMateria* clone(void) const = 0;
		virtual void use(ICharacter& target);
};