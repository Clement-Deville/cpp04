/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeville <cdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 18:30:33 by cdeville          #+#    #+#             */
/*   Updated: 2024/10/26 13:53:21 by cdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

/**========================================================================
 *                      CONSTRUCTORS/DESTRUCTORS
 *========================================================================**/

AMateria::AMateria()
{
	std::cout << "\e[0;32mAMateria Default constructor called\e[0m" << std::endl;
	this->_type = "Unknown Materia";
}

AMateria::AMateria(std::string const & type)
{
	std::cout << "\e[0;32mAMateria Type constructor called\e[0m" << std::endl;
	this->_type = type;
}

AMateria::AMateria(const AMateria &Cpy)
{
	std::cout << "\e[0;32mAMateria Copy constructor called\e[0m" << std::endl;
	*this = Cpy;
}

AMateria::~AMateria()
{
	std::cout << "\e[0;31mAMateria Destructor called\e[0m" << std::endl;
}

AMateria & AMateria::operator=(const AMateria &Cpy)
{
	std::cout << "\e[0;32mAMateria Copy assignement operator called\e[0m" << std::endl;
	if (this == &Cpy)
		return (*this);
	this->_type = Cpy._type;
	return (*this);
}

/**========================================================================
 *                              METHODS
 *========================================================================**/

std::string const AMateria::getType(void) const
{
	return (this->_type);
}

void AMateria::use(ICharacter& target)
{
	std::cout << "ERROR: Can't use a AMateria type"
		<< std::endl;
	(void)target;
}
