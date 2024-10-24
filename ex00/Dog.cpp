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
	this->type = "Dog";
}

Dog::Dog(const Dog &Cpy)
{
	*this = Cpy;
}

Dog::~Dog()
{

}

Dog & Dog::operator=(const Dog &Cpy)
{
	if (this == &Cpy)
		return (*this);
	this->type = Cpy.type;
	return (*this);
}

void Dog::makeSound()
{
	std::cout << this->type << " is barking, OUAF OUAF" << std::endl;
}
