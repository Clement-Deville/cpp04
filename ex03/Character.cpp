/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeville <cdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 13:10:33 by cdeville          #+#    #+#             */
/*   Updated: 2024/12/12 19:02:24 by cdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(): floor_size(4), floor_used(0)
{
	this->_floor = new AMateria *[4]();
	std::cout << "\e[0;32mCharacter Default constructor called\e[0m" << std::endl;
	this->_name = "Unamed character";
	for (int i = 0; i < 4; i++)
		this->_slot[i] = NULL;
}

Character::Character(const std::string name):
	floor_size(4), floor_used(0)
{
	this->_floor = new AMateria *[4]();
	std::cout << "\e[0;32mCharacter name constructor called\e[0m" << std::endl;
	this->_name = name;
	for (int i = 0; i < 4; i++)
		_slot[i] = NULL;
}

Character::Character(const Character &Cpy):
	floor_size(4), floor_used(0)
{
	this->_floor = new AMateria *[4]();
	std::cout << "\e[0;32mCharacter Copy constructor called\e[0m" << std::endl;
	// for (int i = 0; i < 4; i++)
	// 	this->_slot[i] = NULL;
	//! VERFIER COMPORTEMENT SI CONSTRUCTEUR APPELE ALORS QUE DEJA INSTANCIER
	*this = Cpy;
}

Character::~Character()
{
	std::list<AMateria *>::iterator it;

	std::cout << "\e[0;31mCharacter Destructor called\e[0m" << std::endl;
	Character::del_floor();
	for (int i = 0; i < 4; i++)
		delete this->_slot[i];
	// {
		// this->_slot[i] = NULL;
		// if (this->_slot[i])
		// {
		// }
	// }
}

Character & Character::operator=(const Character &Cpy)
{
	std::cout << "\e[0;32mCharacter Copy assignement operator called\e[0m" << std::endl;
	if (this == &Cpy)
		return (*this);
	this->_name = Cpy._name;
	for (int i = 0; i < 4; i++)
	{
		if (this->_slot[i])
		{
			Character::put_floor(this->_slot[i]);
			this->_slot[i] = NULL;
		}
	}
	for (int i = 0; i < 4; i++)
	{
		if (Cpy._slot[i])
			this->_slot[i] = Cpy._slot[i]->clone();
		else
			this->_slot[i] = NULL;
	}
	return (*this);
}

std::string const & Character::getName() const
{
	return (this->_name);
}

void Character::equip(AMateria* m)
{
	if (m == NULL)
		return ;
	// for (int i = 0; i < 4; i++)
	// {
	// 	if (this->_slot[i]
	// 		&& this->_slot[i]->getType() == m->getType())
	// 	{
	// 		std::cerr << "This Materia type is already possessed"
	// 			<< std::endl;
	// 		return;
	// 	}
	// }
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
	// delete this->_slot[idx];
	Character::put_floor(this->_slot[idx]);
	this->_slot[idx] = NULL;
}

void Character::use(int idx, ICharacter& target)
{
	if (idx < 0 || idx > 4 || this->_slot[idx] == NULL)
	{
		std::cerr << "No existing Materia at this index to use" << std::endl;
		return ;
	}
	this->_slot[idx]->use(target);
}

void	Character::del_floor()
{
	std::cout << "FLOOR USED AT DESTRUC" << this->floor_used << std::endl;
	// for (unsigned int i = 0; i < this->floor_used; i++)
	// 	delete this->_floor[i];
	if (this->floor_used)
		delete this->_floor[0];
		// std::cout << "here" << std::endl;
	delete [] this->_floor;
}

void	Character::put_floor(AMateria *m)
{
	delete m;
	return ;
	// if (this->floor_size == this->floor_used)
	// {
	// 	this->floor_size *= 2;
	// 	AMateria **new_floor = new AMateria *[floor_size];
	// 	for (unsigned int i = 0; i < this->floor_used; i++)
	// 		new_floor[i] = this->_floor[i];
	// 	delete [] this->_floor;
	// 	this->_floor = new_floor;
	// }
	// std::cout << "PUT FLOOR: USED: " << floor_used << " SIZE: " << floor_size << std::endl;
	// this->_floor[0] = NULL;
	// std::cout << "SIZE OF floor[0]: " << sizeof(this->_floor[0]) << " SIZE OF M: "
	// 	<< sizeof(m) << std::endl;
	this->_floor[0] = NULL;
	this->floor_used++;
	(void)m;
}
