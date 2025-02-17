/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theog <theog@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 18:19:17 by tcohen            #+#    #+#             */
/*   Updated: 2025/02/17 12:47:40 by theog            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int error_new(Animal *tab_animal[SIZE], std::bad_alloc e)
{
	std::cout << "New failed " << e.what() << std::endl;
	for (int i = 0; i < SIZE; i++)
	{
		if (tab_animal[i])
			delete tab_animal[i];
	}
	return (1);
}

void destroy_animals(Animal *tab_animals[SIZE])
{
	for(int i = 0; i < SIZE; i++)
		delete tab_animals[i];
}

int main()
{
	Animal *tab_animal[SIZE];
	Dog* dog_ptr;
	Cat* cat_ptr;

	//Animal chips;
	for (int i = 0; i < SIZE; i++)
		tab_animal[i] = NULL;
	for (int i = 0; i < SIZE; i++)
	{
		try
		{
			if (i <= (SIZE / 2 - 1))
					tab_animal[i] = new Dog;
			else
				tab_animal[i] = new Cat;
		}
		catch (std::bad_alloc &e)
		{
			return(error_new(tab_animal, e));
		}
	}
	std::cout << "\n\nDeep copy testing\n\n" << std::endl;
	dog_ptr = dynamic_cast<Dog *>(tab_animal[0]);
	dog_ptr->makeSound();
	Dog dog1;
	Dog dog2(dog1);

	std::cout << "dog1 adress is " << &dog1 << std::endl;
	std::cout << "dog2 address is " << &dog2 << std::endl;
	std::cout << "dog1.type address is " << &dog1.getType() << std::endl;
	std::cout << "dog2.type address is " << &dog2.getType() << std::endl;

	cat_ptr = dynamic_cast<Cat *>(tab_animal[SIZE -1]);
	cat_ptr->makeSound();
	Cat cat1;
	Cat cat2(cat1);

	std::cout << "cat1 adress is " << &cat1 << std::endl;
	std::cout << "cat2 address is " << &cat2 << std::endl;
	std::cout << "cat1.type address is " << &cat1.getType() << std::endl;
	std::cout << "cat2.type address is " << &cat2.getType() << std::endl;
 
	std::cout << "\n\nEND Deep copy testing\n\n" << std::endl;
	destroy_animals(tab_animal);
}
