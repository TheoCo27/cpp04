/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theog <theog@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 17:50:49 by tcohen            #+#    #+#             */
/*   Updated: 2025/02/20 14:47:21 by theog            ###   ########.fr       */
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
		Character(std::string name);
		Character(const Character &copy);
		Character& operator=(const Character &copy);
		virtual ~Character(void);
		std::string const & getName() const;
		void equip(AMateria* m);
		void unequip(int idx);
		void use(int idx, ICharacter& target);
		int get_materia_index(AMateria *m);
		int add_to_thrash(AMateria *m);
		void clean_thrash(void);
};