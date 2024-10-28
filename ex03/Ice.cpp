/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeville <cdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 15:04:06 by cdeville          #+#    #+#             */
/*   Updated: 2024/10/28 18:00:25 by cdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice()
{
	std::cout << "\e[0;32mIce Default constructor called\e[0m" << std::endl;
	this->_type = "ice";
}

Ice::Ice(const Ice &Cpy)
{
	std::cout << "\e[0;32mIce Copy constructor called\e[0m" << std::endl;
	this->_type = "ice";
	*this = Cpy;
}

Ice::~Ice()
{
	std::cout << "\e[0;31mIce Destructor called\e[0m" << std::endl;
}

Ice & Ice::operator=(const Ice &Cpy)
{
	std::cout << "\e[0;32mIce Copy assignement operator called\e[0m" << std::endl;
	if (this == &Cpy)
		return (*this);
	return (*this);
}

void Ice::use(ICharacter& target)
{
	std::string name;

	name = target.getName();
	if (name.empty())
	{
		std::cerr << "You need to choose a valid target.."
			<< std::endl;
		return ;
	}
	std::cout << "* shoots an ice bolt at "<< name
		<< " *" << std::endl;
}

AMateria* Ice::clone() const
{
	return (new Ice(*this));
}
