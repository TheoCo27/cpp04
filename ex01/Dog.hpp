/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theog <theog@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 19:56:30 by tcohen            #+#    #+#             */
/*   Updated: 2025/02/16 01:05:30 by theog            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#pragma once
#include "Animal.hpp"
#include "Brain.hpp"
#define SIZE 4
#define L_ARRAY 10

class Dog : public Animal
{
	private:
		Brain *tab_ideas;
	public:
		Dog(void);
		Dog(const Dog &copy);
		Dog& operator=(const Dog &copy);
		virtual ~Dog(void);
		void makeSound(void) const;
		Brain *getTab_ideas(void);
		int* largeArray;
};