/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeville <cdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 18:30:33 by cdeville          #+#    #+#             */
/*   Updated: 2024/10/24 18:46:04 by cdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()
{
	std::cout << "\e[0;32mDog Default constructor called\e[0m" << std::endl;
	this->type = "Dog";
}

Dog::Dog(const Dog &Cpy)
{
	std::cout << "\e[0;32mDog Copy constructor called\e[0m" << std::endl;
	*this = Cpy;
}

Dog::~Dog()
{
	std::cout << "\e[0;31mDog Destructor called\e[0m" << std::endl;
}

Dog & Dog::operator=(const Dog &Cpy)
{
	std::cout << "\e[0;32mDog Copy assignement operator called\e[0m";
	if (this == &Cpy)
		return (*this);
	this->type = Cpy.type;
	return (*this);
}

void Dog::makeSound() const
{
	std::cout << this->type << " is barking, OUAF OUAF" << std::endl;
}
