/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeville <cdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 18:30:33 by cdeville          #+#    #+#             */
/*   Updated: 2024/12/13 19:21:04 by cdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal()
{
	std::cout << "\e[0;32mAnimal Default constructor called\e[0m" << std::endl;
	this->type = "Animal";
}

Animal::Animal(const Animal &Cpy)
{
	std::cout << "\e[0;32mAnimal Copy constructor called\e[0m" << std::endl;
	*this = Cpy;
}

Animal::~Animal()
{
	std::cout << "\e[0;31mAnimal Destructor called\e[0m" << std::endl;
}

Animal & Animal::operator=(const Animal &Cpy)
{
	std::cout << "\e[0;32mAnimal Copy assignement operator called\e[0m" << std::endl;
	if (this == &Cpy)
		return (*this);
	this->type = Cpy.type;
	return (*this);
}

void Animal::makeSound() const
{
	std::cout << "This animal has no type and can't make a sound" << std::endl;
}

std::string Animal::getType(void) const
{
	return (this->type);
}
