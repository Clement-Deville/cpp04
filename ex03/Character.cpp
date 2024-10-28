/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeville <cdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 13:10:33 by cdeville          #+#    #+#             */
/*   Updated: 2024/10/28 13:49:57 by cdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character()
{
	std::cout << "\e[0;32mCharacter Default constructor called\e[0m" << std::endl;
	this->_name = "Unamed character";
	for (int i = 0; i < 4; i++)
		_slot[i] = NULL;
}

Character::Character(const std::string name)
{
	std::cout << "\e[0;32mCharacter name constructor called\e[0m" << std::endl;
	this->_name = name;
	for (int i = 0; i < 4; i++)
		_slot[i] = NULL;
}

Character::Character(const Character &Cpy)
{
	std::cout << "\e[0;32mCharacter Copy constructor called\e[0m" << std::endl;
	*this = Cpy;
}

Character::~Character()
{
	std::cout << "\e[0;31mCharacter Destructor called\e[0m" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (this->_slot[i])
		{
			delete this->_slot[i];
			this->_slot[i] = NULL;
		}
	}
}

Character & Character::operator=(const Character &Cpy)
{
	std::cout << "\e[0;32mCharacter Copy assignement operator called\e[0m" << std::endl;
	if (this == &Cpy)
		return (*this);
	this->_name = Cpy._name;
	for (int i = 0; i < 4; i++)
	{
		if (Cpy._slot[i])
			_slot[i] = Cpy._slot[i]->clone();
	}
	return (*this);
}

std::string const & Character::getName() const
{
	return (this->_name);
}

void Character::equip(AMateria* m)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_slot[i]
			&& this->_slot[i]->getType() == m->getType())
		{
			std::cerr << "This Materia type is already possessed"
				<< std::endl;
			return;
		}
	}
	for (int i = 0; i < 4; i++)
	{
		if (this->_slot[i] == NULL)
		{
			_slot[i] = m;
			return ;
		}
	}
	std::cerr << "No slot available, you must unequip a Materia first"
		<< std::endl;
}

void Character::unequip(int idx)
{
	if (idx < 0 || idx > 4 || this->_slot[idx] == NULL)
	{
		std::cerr << "No existing Materia at this index to unequip" << std::endl;
		return ;
	}
	delete this->_slot[idx];
	this->_slot[idx] = NULL;
}

void Character::use(int idx, ICharacter& target)
{
	if (idx < 0 || idx > 4 ||this->_slot[idx] == NULL)
	{
		std::cerr << "No existing Materia at this index to use" << std::endl;
		return ;
	}
	this->_slot[idx]->use(target);
}
