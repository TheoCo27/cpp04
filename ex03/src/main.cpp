/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcohen <tcohen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 18:08:40 by tcohen            #+#    #+#             */
/*   Updated: 2025/02/21 20:34:43 by tcohen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Character.hpp"
#include "../inc/MateriaSource.hpp"
#include "../inc/Ice.hpp"
#include "../inc/Cure.hpp"

void main_test(void)
{
    IMateriaSource	*src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	ICharacter		*me = new Character("me");

	AMateria		*tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);

	ICharacter		*bob = new Character("bob");
    // Character* og(dynamic_cast<Character *>(me));
    // og->print_inventory();
	me->use(0, *bob);
	me->use(1, *bob);

	delete (bob);
	delete (me);
	delete (src);
}

// void abstract_test(void)
// {
// 	IMateriaSource obj;
// 	AMateria obj2;
// 	ICharacter obj3;
// }

void materiaSource_test(void)
{
    IMateriaSource	*src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	src->learnMateria(new Cure());
	src->learnMateria(new Ice());
	//Inventory full
	AMateria *test = new Ice();	
	src->learnMateria(test);
	// create Materia polymorphe
	AMateria *ptr = src->createMateria("ice");
	AMateria *ptr2 = src->createMateria("cure");
	AMateria *ptr3 = src->createMateria("unknown");

	Character bob("bob");
	ptr->use(bob);
	ptr2->use(bob);
	if (ptr3 == NULL)
		std::cout << "ptr3 is null" << std::endl;
	delete ptr;
	delete ptr2;
	delete src;
	delete test;
}

void same_materiaSource_test(void)
{
    IMateriaSource	*src = new MateriaSource();
	AMateria *ptr = new Ice();
	src->learnMateria(ptr);
	src->learnMateria(ptr);
	src->learnMateria(ptr);
	src->learnMateria(ptr);
	//Inventory full
	src->learnMateria(ptr);
	// create Materia polymorphe
	AMateria *ptr1 = src->createMateria("ice");
	AMateria *ptr2 = src->createMateria("ice");
	AMateria *ptr3 = src->createMateria("unknown");

	Character bob("bob");
	ptr1->use(bob);
	ptr2->use(bob);
	if (ptr3 == NULL)
		std::cout << "ptr3 is null" << std::endl;
	delete ptr1;
	delete ptr2;
	delete src;
}

void character_inventory_test(void)
{
	ICharacter		*me = new Character("me");
	me->equip(new Ice());
	me->equip(new Cure());
	me->equip(new Ice());
	me->equip(new Cure());
	//Inventory full
	AMateria *test = new Ice();	
	me->equip(test);
	//Empty Inventory
	me->unequip(0);
	me->unequip(0);
	me->unequip(0);
	me->unequip(0);
	//Invalid index from unequip
	me->unequip(0);
	ICharacter		*bob = new Character("bob");
    // Invalid Index from use
	me->use(0, *bob);
	me->use(1, *bob);
	delete (bob);
	delete (me);
	delete (test);
}

void test_thomas(void)
{
	IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());
    ICharacter* me = new Character("me");
    AMateria* tmp;
    tmp = src->createMateria("Ice");
    me->equip(tmp);
    tmp = src->createMateria("Cure");
    me->equip(tmp);
    me->equip(tmp);
    ICharacter* bob = new Character("bob");
    me->use(0, *bob);
    me->use(1, *bob);
    me->use(4, *bob);
    me->unequip(0);
    me->use(0, *bob);
    me->unequip(1);
    me->use(1, *bob);
    me->unequip(1);
    me->unequip(4);
    delete bob;
    delete me;
    delete src;
}

void character_same_inventory_test(void)
{
	ICharacter		*me = new Character("me");
	AMateria *test = new Ice();	
	me->equip(test);
	me->equip(test);
	me->equip(test);
	me->equip(test);
	//Inventory full
	me->equip(test);
	//Empty Inventory
	me->unequip(0);
	me->unequip(0);
	me->unequip(0);
	me->unequip(0);
	//Invalid index from unequip
	me->unequip(0);
	me->equip(test);
	ICharacter		*bob = new Character("bob");
    // Invalid Index from use
	me->use(0, *bob);
	me->use(1, *bob);
	delete (bob);
	delete (me);
}

int main()
{
	//main_test();
	//materiaSource_test();
	//character_inventory_test();
	//character_same_inventory_test();
	//test_thomas();
	//character_same_inventory_test();
	same_materiaSource_test();
}
