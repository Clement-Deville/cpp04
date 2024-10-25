/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeville <cdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 18:30:33 by cdeville          #+#    #+#             */
/*   Updated: 2024/10/24 18:46:04 by cdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat()
{
	std::cout << "\e[0;32mWrongCat Default constructor called\e[0m" << std::endl;
	this->type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat &Cpy)
{
	std::cout << "\e[0;32mWrongCat Copy constructor called\e[0m" << std::endl;
	*this = Cpy;
}

WrongCat::~WrongCat()
{
	std::cout << "\e[0;31mWrongCat Destructor called\e[0m" << std::endl;
}

WrongCat & WrongCat::operator=(const WrongCat &Cpy)
{
	std::cout << "\e[0;32mWrongCat Name constructor called\e[0m" << std::endl;
	if (this == &Cpy)
		return (*this);
	this->type = Cpy.type;
	return (*this);
}

void WrongCat::makeSound() const
{
	std::cout << this->type << " is meowing, MIAOUUU" << std::endl;
}
