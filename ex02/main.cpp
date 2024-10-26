/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeville <cdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 18:30:09 by cdeville          #+#    #+#             */
/*   Updated: 2024/10/26 14:02:44 by cdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"

#define N_A_AnimalS 10

int main(void)
{
	{
		const A_Animal *lotsOfA_Animals[N_A_AnimalS];

		for (int i = 0; i < N_A_AnimalS; i++)
		{
			if (i < N_A_AnimalS / 2)
				lotsOfA_Animals[i] = new Dog();
			else
				lotsOfA_Animals[i] = new Cat();
		}
		std::cout << "-------------------------------------\n";
		std::cout << lotsOfA_Animals[0]->getType() << std::endl;
		std::cout << lotsOfA_Animals[5]->getType() << std::endl;
		Brain *brain;
		brain = &lotsOfA_Animals[0]->getBrain();
		brain->setIdea("I want sarshisitas!");
		brain->setIdea("Let's play ball!!");
		brain->setIdea("Feed me human!");
		std::cout << lotsOfA_Animals[0]->getBrain().getIdea(0) << std::endl;
		std::cout << lotsOfA_Animals[0]->getBrain().getIdea(1) << std::endl;
		std::cout << "-------------------------------------\n";
		for (int i = 0; i < N_A_AnimalS; i++)
			delete lotsOfA_Animals[i];
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
	A_Animal test();
	return (0);
}


