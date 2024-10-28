/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeville <cdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 13:05:29 by cdeville          #+#    #+#             */
/*   Updated: 2024/10/28 13:05:48 by cdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure()
{
	std::cout << "\e[0;32mCure Default constructor called\e[0m" << std::endl;
	this->_type = "cure";
}

Cure::Cure(const Cure &Cpy)
{
	std::cout << "\e[0;32mCure Copy constructor called\e[0m" << std::endl;
	*this = Cpy;
}

Cure::~Cure()
{
	std::cout << "\e[0;31mCure Destructor called\e[0m" << std::endl;
}

Cure & Cure::operator=(const Cure &Cpy)
{
	std::cout << "\e[0;32mCure Copy assignement operator called\e[0m" << std::endl;
	if (this == &Cpy)
		return (*this);
	this->_type = Cpy._type;
	return (*this);
}

void Cure::use(ICharacter& target)
{
	std::string name;

	name = target.getName();
	if (name.empty())
	{
		std::cerr << "You need to choose a valid target.."
			<< std::endl;
		return ;
	}
	std::cout << "* heals " << name
		<< "’s wounds *" << std::endl;
}

AMateria* Cure::clone() const
{
	return (new Cure(*this));
}
