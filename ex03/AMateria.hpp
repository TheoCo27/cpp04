/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcohen <tcohen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 18:05:26 by tcohen            #+#    #+#             */
/*   Updated: 2025/02/17 18:05:28 by tcohen           ###   ########.fr       */
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
		std::string type;
	public:
		virtual ~AMateria(void);
		std::string const & getType() const;
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);
};