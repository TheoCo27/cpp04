/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcohen <tcohen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 18:18:54 by tcohen            #+#    #+#             */
/*   Updated: 2025/02/14 13:49:11 by tcohen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
	private:
		Brain *tab_ideas;
	public:
		Cat(void);
		Cat(const Cat &copy);
		Cat& operator=(const Cat &copy);
		virtual ~Cat(void);
		void makeSound(void) const;
		Brain *getTab_ideas(void);

};