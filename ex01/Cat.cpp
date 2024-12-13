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
	std::cout << "\e[0;32mCat Default constructor called\e[0m" << std::endl;
	this->type = "Cat";
	this->_brain = new Brain();
}

Cat::Cat(const Cat &Cpy)
{
	std::cout << "\e[0;32mCat Copy constructor called\e[0m" << std::endl;
	this->_brain = NULL;
	*this = Cpy;
}

Cat::~Cat()
{
	std::cout << "\e[0;31mCat Destructor called\e[0m" << std::endl;
	delete this->_brain;
}

Cat & Cat::operator=(const Cat &Cpy)
{
	std::cout << "\e[0;32mCat Copy assignement operator called\e[0m" << std::endl;
	if (this == &Cpy)
		return (*this);
	this->type = Cpy.type;
	delete this->_brain;
	this->_brain = new Brain(*Cpy._brain);
	return (*this);
}

void Cat::makeSound() const
{
	std::cout << this->type << " is meowing, MIAOUUU" << std::endl;
}
