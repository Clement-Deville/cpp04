/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeville <cdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 18:30:09 by cdeville          #+#    #+#             */
/*   Updated: 2024/12/13 19:21:40 by cdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"

#define N_ANIMALS 10

int main(void)
{
	{
		const Animal *lotsOfAnimals[N_ANIMALS];

		for (int i = 0; i < N_ANIMALS; i++)
		{
			if (i < N_ANIMALS / 2)
				lotsOfAnimals[i] = new Dog();
			else
				lotsOfAnimals[i] = new Cat();
		}
		std::cout << "-------------------------------------\n";
		std::cout << lotsOfAnimals[0]->getType() << std::endl;
		std::cout << lotsOfAnimals[5]->getType() << std::endl;
		Brain *brain = new Brain();
		brain->setIdea("I want sarshisitas!");
		brain->setIdea("Let's play ball!!");
		brain->setIdea("Feed me human!");
		delete brain;
		std::cout << "-------------------------------------\n";
		for (int i = 0; i < N_ANIMALS; i++)
			delete lotsOfAnimals[i];
	}
	std::cout << "-------------------------------------\n";
	{
		std::cout << "Check deep copy of Dog class using copy constructor:\n" << std::endl;
		Dog *dogA = new Dog;
		Dog *dogB = new Dog(*dogA);

		delete dogA;
		delete dogB;
	}
	std::cout << "-------------------------------------\n";
	{
		std::cout << "Check deep copy of Dog class using assignment operator overload:\n" << std::endl;
		Dog *dogA = new Dog;
		Dog *dogB = new Dog;

		*dogA = *dogB;
		delete dogA;
		delete dogB;
	}
	std::cout << "-------------------------------------\n";
	{
		std::cout << "Check deep copy of Cat class using copy constructor:\n" << std::endl;
		Cat *catA = new Cat;
		Cat *catB = new Cat(*catA);

		delete catA;
		delete catB;
	}
	std::cout << "-------------------------------------\n";
	{
		std::cout << "Check deep copy of Cat class using assignment operator overload:\n" << std::endl;
		Cat *catA = new Cat;
		Cat *catB = new Cat;

		*catA = *catB;
		delete catA;
		delete catB;
	}
	return (0);
}


