/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theog <theog@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 17:50:49 by tcohen            #+#    #+#             */
/*   Updated: 2025/02/20 01:37:58 by theog            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "AMateria.hpp"

class Character : public ICharacter
{
	protected:
		std::string		_Name;
		AMateria*		_inventory[4];
		int				_inventorySize;
		AMateria**		_MateriaThrash;
		int				_ThrashSize;
		int				_error;
		
	public:
		Character(void);
		Character(const Character &copy);
		Character& operator=(const Character &copy);
		virtual ~Character(void);
		virtual std::string const & getName() const;
		virtual void equip(AMateria* m);
		virtual void unequip(int idx);
		virtual void use(int idx, Character& target);
		int get_materia_index(AMateria *m);
		int add_to_thrash(AMateria *m);
		void clean_thrash(void);
};