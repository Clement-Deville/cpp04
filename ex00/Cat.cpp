/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeville <cdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 18:30:33 by cdeville          #+#    #+#             */
/*   Updated: 2024/10/24 18:46:04 by cdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat()
{
	this->type = "Cat";
}

Cat::Cat(const Cat &Cpy)
{
	*this = Cpy;
}

Cat::~Cat()
{

}

Cat & Cat::operator=(const Cat &Cpy)
{
	if (this == &Cpy)
		return (*this);
	this->type = Cpy.type;
	return (*this);
}

void Cat::makeSound()
{
	std::cout << this->type << " is meowing, MIAOUUU" << std::endl;
}
