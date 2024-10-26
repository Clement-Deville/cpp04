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
}

Cat::Cat(const Cat &Cpy)
{
	std::cout << "\e[0;32mCat Copy constructor called\e[0m" << std::endl;
	*this = Cpy;
}

Cat::~Cat()
{
	std::cout << "\e[0;31mCat Destructor called\e[0m" << std::endl;
}

Cat & Cat::operator=(const Cat &Cpy)
{
	std::cout << "\e[0;32mCat Copy assignement operator called\e[0m" << std::endl;
	return((Cat &)A_Animal::operator=(Cpy));
}

void Cat::makeSound() const
{
	std::cout << this->type << " is meowing, MIAOUUU" << std::endl;
}
