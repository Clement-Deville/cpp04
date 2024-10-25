/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeville <cdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 18:30:09 by cdeville          #+#    #+#             */
/*   Updated: 2024/10/25 13:35:28 by cdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main()
{
const Animal* meta = new Animal();
const Animal* j = new Dog();
const Animal* i = new Cat();
std::cout << j->getType() << " " << std::endl;
std::cout << i->getType() << " " << std::endl;
i->makeSound(); //will output the cat sound!
j->makeSound();
meta->makeSound();

// WRONG ANIMAL

const WrongAnimal* lol = new WrongAnimal();
const WrongAnimal* t = new WrongCat();
std::cout << t->getType() << " " << std::endl;
t->makeSound(); //will NOT output the cat sound!
lol->makeSound();
delete (meta);
delete (lol);
delete (i);
delete (j);
delete (t);
return 0;
}
