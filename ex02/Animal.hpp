/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theog <theog@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 18:18:48 by tcohen            #+#    #+#             */
/*   Updated: 2025/02/17 12:46:39 by theog            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>

class Animal
{
	protected:
		std::string type;
		Animal(void);
		Animal(std::string type);
		Animal& operator=(const Animal &copy);
		Animal(const Animal &copy);
	public:
		virtual ~Animal(void);
		virtual void makeSound(void) const = 0;
		virtual std::string& getType(void);
};