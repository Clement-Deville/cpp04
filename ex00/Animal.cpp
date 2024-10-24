/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeville <cdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 18:30:33 by cdeville          #+#    #+#             */
/*   Updated: 2024/10/24 19:13:10 by cdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal()
{
	this->type = "Animal";
}

Animal::Animal(const Animal &Cpy)
{
	*this = Cpy;
}

Animal::~Animal()
{

}

Animal & Animal::operator=(const Animal &Cpy)
{
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
