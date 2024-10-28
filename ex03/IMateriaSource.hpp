/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeville <cdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 16:38:34 by cdeville          #+#    #+#             */
/*   Updated: 2024/10/28 13:52:55 by cdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMATERIASOURCE_HPP
# define IMATERIASOURCE_HPP

#include "AMateria.hpp"

class IMateriaSource
{
	public:
		virtual ~IMateriaSource() {}
		virtual void learnMateria(AMateria*) = 0;
		virtual AMateria* createMateria(std::string const & type) = 0;
};

// IMateriaSource::IMateriaSource(/* args */)
// {
// }

// IMateriaSource::~IMateriaSource()
// {
// }

class MateriaSource : public IMateriaSource
{
	protected:
		AMateria *_list[4];
	public:
		MateriaSource();
		MateriaSource(const MateriaSource &Cpy);
		virtual ~MateriaSource();

		MateriaSource & operator=(const MateriaSource &Cpy);
		virtual void learnMateria(AMateria* ptr);
		virtual void forgetMateria(int index);
		virtual AMateria* createMateria(std::string const & type);
};

MateriaSource::MateriaSource()
{
	std::cout << "\e[0;32mMateriaSource Default constructor called\e[0m" << std::endl;
	for (int i = 0; i < 4; i++)
		this->_list[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource &Cpy)
{
	std::cout << "\e[0;32mMateriaSource Copy constructor called\e[0m" << std::endl;
	*this = Cpy;
}

MateriaSource::~MateriaSource()
{
	std::cout << "\e[0;31mMateriaSource Destructor called\e[0m" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (this->_list[i])
		{
			delete this->_list[i];
			this->_list[i] = NULL;
		}
	}
}

MateriaSource & MateriaSource::operator=(const MateriaSource &Cpy)
{
	std::cout << "\e[0;32mMateriaSource Copy assignement operator called\e[0m" << std::endl;
	if (this == &Cpy)
		return (*this);
	for (int i = 0; i < 4; i++)
		this->_list[i] = Cpy._list[i];
	return (*this);
}

void MateriaSource::learnMateria(AMateria* ptr)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_list[i]
			&& this->_list[i]->getType() == ptr->getType())
		{
			std::cerr << "ERROR: You can't learn a Materia you already learned"
				<< std::endl;
			return ;
		}
	}
	for (int i = 0; i < 4; i++)
	{
		if (this->_list[i] == NULL)
		{
			this->_list[i] = ptr;
			return ;
		}
	}
	std::cerr << "ERROR: You must forget one Materia before learning another"
				<< std::endl;
}

void MateriaSource::forgetMateria(int index)
{
	if (index < 0)
	{
		for (int i = 3; i >= 0; i--)
		{
			if (this->_list[i])
			{
				delete this->_list[i];
				this->_list[i] = NULL;
				return ;
			}
		}
	}
	else if (index < 4)
	{
		if (this->_list[index])
		{
			delete this->_list[index];
			this->_list[index] = NULL;
			return ;
		}
	}
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_list[i]
			&& this->_list[i]->getType() == type)
			return (this->_list[i]->clone());
	}
	std::cerr << "ERROR: This type is not valid or not learned yet!" << std::endl;
	return (NULL);
}

#endif
