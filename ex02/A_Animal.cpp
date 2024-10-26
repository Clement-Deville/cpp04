/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   A_Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeville <cdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 18:30:33 by cdeville          #+#    #+#             */
/*   Updated: 2024/10/26 13:53:21 by cdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "A_Animal.hpp"

A_Animal::A_Animal()
{
	std::cout << "\e[0;32mA_Animal Default constructor called\e[0m" << std::endl;
	this->type = "A_Animal";
	this->_brain = new Brain();
}

A_Animal::A_Animal(const A_Animal &Cpy)
{
	std::cout << "\e[0;32mA_Animal Copy constructor called\e[0m" << std::endl;
	*this = Cpy;
}

A_Animal::~A_Animal()
{
	std::cout << "\e[0;31mA_Animal Destructor called\e[0m" << std::endl;
	delete this->_brain;
}

A_Animal & A_Animal::operator=(const A_Animal &Cpy)
{
	std::cout << "\e[0;32mA_Animal Copy assignement operator called\e[0m" << std::endl;
	if (this == &Cpy)
		return (*this);
	this->type = Cpy.type;
	delete this->_brain;
	this->_brain = new Brain(*Cpy._brain);
	return (*this);
}

void A_Animal::makeSound() const
{
	std::cout << "This A_Animal has no type and can't make a sound" << std::endl;
}

std::string A_Animal::getType(void) const
{
	return (this->type);
}

Brain	&A_Animal::getBrain(void) const
{
	return (*_brain);
}
