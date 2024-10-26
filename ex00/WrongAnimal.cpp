/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeville <cdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 18:30:33 by cdeville          #+#    #+#             */
/*   Updated: 2024/10/25 11:57:27 by cdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	std::cout << "\e[0;32mWrongAnimal Default constructor called\e[0m" << std::endl;
	this->type = "WrongAnimal";
}

WrongAnimal::WrongAnimal(const WrongAnimal &Cpy)
{
	std::cout << "\e[0;32mWrongAnimal Copy constructor called\e[0m" << std::endl;
	*this = Cpy;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "\e[0;31mWrongAnimal Destructor called\e[0m" << std::endl;
}

WrongAnimal & WrongAnimal::operator=(const WrongAnimal &Cpy)
{
	std::cout << "\e[0;32mWrong Animal Copy assignement operator called\e[0m";
	if (this == &Cpy)
		return (*this);
	this->type = Cpy.type;
	return (*this);
}

void WrongAnimal::makeSound() const
{
	std::cout << "This WrongAnimal has no type and can't make a sound" << std::endl;
}

std::string WrongAnimal::getType(void) const
{
	return (this->type);
}
