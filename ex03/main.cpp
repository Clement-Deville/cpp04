/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeville <cdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 13:08:36 by cdeville          #+#    #+#             */
/*   Updated: 2024/12/13 16:13:09 by cdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"

int main()
{
	{
		IMateriaSource* src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());
		ICharacter* me = new Character("me");
		AMateria* tmp;
		tmp = src->createMateria("ice");
		me->equip(tmp);
		tmp = src->createMateria("cure");
		me->equip(tmp);
		ICharacter* bob = new Character("bob");
		me->use(0, *bob);
		me->use(1, *bob);
		std::cout << std::endl;

		delete bob;
		delete me;
		delete src;
	}
	{
		std::cout << "1. Create new MateriaSource and learn materias (check maximum too):" << std::endl;
		IMateriaSource* src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());
		AMateria *mat = new Cure();
		src->learnMateria(mat);
		std::cout << std::endl;

	//! VERIFIER DEEP COPY
	//* POURQUOI NE PAS CREER UN FLOOR PROPRE A CHAQUE CHARACTER ET SUPPRIMER TOUT A LA FIN?
		std::cout << "2. Create 2 new characters and test deep copy:" << std::endl;
		Character *dur0 = new Character("Alice");
		ICharacter *dur1 = new Character("Bruce");
		AMateria *tmp_materia = src->createMateria("ice");
		dur0->equip(tmp_materia);
		dur0->use(0, *dur0);
		*dur1 = *dur0;
		delete dur0;
		delete dur1;
		std::cout << std::endl;

		std::cout << "3. Create materias and equip them (also check unknown materias):" << std::endl;
		AMateria* tmp;
		ICharacter *dur2 = new Character("Alice");
		tmp = src->createMateria("ice");
		dur2->equip(tmp);
		tmp = src->createMateria("cure");
		dur2->equip(tmp);
		tmp = src->createMateria("hi");
		dur2->equip(tmp);
		delete src;
		std::cout << std::endl;

		std::cout << "4. Check maximum equipped too:" << std::endl;
		AMateria *cure = new Cure();
		AMateria *ice = new Ice();
		dur2->equip(cure);
		dur2->equip(ice);
		dur2->unequip(2);
		dur2->unequip(2);
		dur2->unequip(6);
		std::cout << std::endl;

		std::cout << "5. Use materias on new chacarter:" << std::endl;
		ICharacter* bob = new Character("Bob");
		dur2->use(0, *bob);
		dur2->use(1, *bob);
		dur2->use(2, *bob);
		dur2->use(6, *bob);
		dur2->use(-4, *bob);
		dur2->use(3, *bob);
		delete bob;
		std::cout << std::endl;

		delete dur2;
		delete mat;
	}
	{
		std::cout <<
		"/**========================================================================\n" <<
		 "*                           CHECKING AMATERIAS\n" <<
		 "*========================================================================**/\n" << std::endl;

		std::cout << "\n*** TESTING CONSTRUCTORS: ***\n" << std::endl;
		{
			const Ice Original;
			std::cout << "\n";

			Ice Cpy(Original);
			std::cout << "\n";

			Cpy = Original;
			std::cout << "\n";
		}
		{
			const Cure Original;
			std::cout << "\n";

			Cure Cpy(Original);
			std::cout << "\n";

			Cpy = Original;
			std::cout << "\n";

		}

		std::cout << "\n*** TESTING POLYMORPHISM: ***\n" << std::endl;

		Character	Joey("Joey");
		Character	unamed;
		AMateria	*pointer_ice = new Ice();
		AMateria	*pointer_cure = new Cure();

		std::cout << "\n\n*** TESTING USE METHOD: ***\n" << std::endl;

		pointer_ice->use(Joey);
		pointer_cure->use(Joey);

		//* UNAMED CHARACTER
		pointer_ice->use(unamed);
		pointer_cure->use(unamed);

		std::cout << "\n\n*** TESTING CLONE METHOD: ***\n" << std::endl;

		const AMateria *const_Materia = new Ice();
		AMateria *clone = const_Materia->clone();

		std::cout << "\n\n*** TESTING GETER: ***\n" << std::endl;

		std::cout << "Const AMateria type: " << const_Materia->getType() << std::endl;
		std::cout << "Clone AMateria type: " << clone->getType() << std::endl;

		delete const_Materia;
		delete	clone;
		delete	pointer_cure;
		delete	pointer_ice;
	}
	{
		std::cout <<
		"/**========================================================================\n" <<
		 "*                           CHECKING MATERIASOURCE\n" <<
		 "*========================================================================**/\n" << std::endl;

		std::cout << "\n*** TESTING CONSTRUCTORS: ***\n" << std::endl;

		{
			const MateriaSource Original;
			std::cout << "\n";

			MateriaSource Cpy(Original);
			std::cout << "\n";

			Cpy = MateriaSource(Original);
			std::cout << "\n";

			Cpy = Original;
		}

		std::cout << "\n*** TESTING METHODS: ***\n" << std::endl;

		std::cout << "\n*** TESTING LEARN: ***\n" << std::endl;

		IMateriaSource* src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());

		//*  CHECK MAX
		AMateria *mat = new Cure();
		src->learnMateria(mat);
		delete mat;
		std::cout << std::endl;

		std::cout << "\n*** TESTING CREATE MATERIA: ***\n" << std::endl;

		{
			AMateria *tmp = src->createMateria("ice");
			delete tmp;
			std::cout << "\n";

			tmp = src->createMateria("cure");
			delete tmp;
			std::cout << "\n";

			//* NO MATCHING TYPE
			tmp = NULL;
			tmp = src->createMateria("");
			delete tmp;
			std::cout << "\n";
		}

		delete src;
	}
	{
		std::cout <<
		"/**========================================================================\n" <<
		 "*                           CHECKING CHARACTERS\n" <<
		 "*========================================================================**/\n" << std::endl;

		std::cout << "\n*** TESTING CONSTRUCTORS: ***\n" << std::endl;

		{
			const Character Original;
			std::cout << "\n";

			Character Cpy(Original);
			std::cout << "\n";

			Cpy = Character(Original);
			std::cout << "\n";

			Cpy = Original;
		}

		std::cout << "\n*** TESTING METHODS: ***\n" << std::endl;

		IMateriaSource* src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());

		ICharacter *Joey = new Character;

		std::cout << "\n*** TESTING EQUIP: ***\n" << std::endl;

		AMateria *tmp;

		Joey->equip(src->createMateria("ice")); //1
		Joey->equip(src->createMateria("cure")); //2
		tmp = src->createMateria("invalid"); // to not loose the pointer
		Joey->equip(tmp); // INVALID
		delete tmp;
		Joey->equip(src->createMateria("ice")); //3
		Joey->equip(src->createMateria("cure")); //4
		tmp = src->createMateria("ice"); // to not loose the pointer
		Joey->equip(tmp); // OUT OF RANGE
		delete tmp;

		std::cout << "\n*** TESTING UNEQUIP: ***\n" << std::endl;

		Joey->unequip(-1);
		Joey->unequip(2);
		Joey->unequip(2);

		std::cout << "\n*** TESTING USE: ***\n" << std::endl;

		for (int i = 0; i < 5; i++)
			Joey->use(i, *Joey);

		std::cout << "\n*** TESTING DEEP COPY: ***\n" << std::endl;

		ICharacter *Joey_Cpy = new Character(*dynamic_cast<Character *>(Joey));
		delete Joey;

		for (int i = 0; i < 5; i++)
			Joey_Cpy->use(i, *Joey_Cpy);

		delete Joey_Cpy;
		delete src;
	}
	return (0);
}

