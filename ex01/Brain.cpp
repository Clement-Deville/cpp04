/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeville <cdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 15:00:09 by cdeville          #+#    #+#             */
/*   Updated: 2024/12/10 14:38:39 by cdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain() : _count(0)
{
	std::cout << "\e[0;32mBrain Default constructor called\e[0m" << std::endl;
	for (int i = 0; i < 100; i++)
		this->_ideas[i] = "";
}

Brain::Brain(const Brain &Cpy)
{
	std::cout << "\e[0;32mBrain Copy constructor called\e[0m" << std::endl;
	*this = Cpy;
}

Brain::~Brain()
{
	std::cout << "\e[0;31mBrain Destructor called\e[0m" << std::endl;
}

Brain & Brain::operator=(const Brain &Cpy)
{
	std::cout << "\e[0;32mBrain Copy assignement operator called\e[0m" << std::endl;
	if (this == &Cpy)
		return (*this);
	for (int i = 0; i < 100; i++)
		this->_ideas[i] = Cpy._ideas[i];
	this->_count = Cpy._count;
	return (*this);
}

void	Brain::setIdea(const std::string newIdea)
{
	_ideas[_count] = newIdea;
	if (_count == 99)
		_count = 0;
	else
		_count++;
}

std::string	Brain::getIdea(const unsigned short index) const
{
	if (index > 99)
	{
		std::cerr << "Index must be positive and less than 99" << std::endl;
		return (NULL);
	}
	return (_ideas[index]);
}
