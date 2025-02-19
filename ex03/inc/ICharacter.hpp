/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcohen <tcohen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 17:50:49 by tcohen            #+#    #+#             */
/*   Updated: 2025/02/19 22:18:53 by tcohen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

class ICharacter
{
	protected:
		std::string		_Name;
		AMateria*		_inventory[4];
		int				_inventorySize;
		AMateria**		_MateriaThrash;
		int				_ThrashSize;
		int				_error;
		
	public:
		ICharacter(void);
		ICharacter(const ICharacter &copy);
		ICharacter& operator=(const ICharacter &copy);
		virtual ~ICharacter() {}
		virtual std::string const & getName() const = 0;
		virtual void equip(AMateria* m) = 0;
		virtual void unequip(int idx) = 0;
		virtual void use(int idx, ICharacter& target) = 0;
		int get_materia_index(AMateria *m);
		int add_to_thrash(AMateria *m);
		void clean_thrash(void);
};