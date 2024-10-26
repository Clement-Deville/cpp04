/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeville <cdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 15:04:25 by cdeville          #+#    #+#             */
/*   Updated: 2024/10/26 17:39:37 by cdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICEP_HPP

# include "AMateria.hpp"

class Ice : public AMateria
{
public:
	Ice();
	Ice(const Ice &Cpy);
	virtual ~Ice();

	Ice & operator=(const Ice &Cpy);
	virtual void use(ICharacter& target);
	virtual AMateria* clone() const;
};

Ice::Ice()
{
	std::cout << "\e[0;32mIce Default constructor called\e[0m" << std::endl;
}

Ice::Ice(const Ice &Cpy)
{
	std::cout << "\e[0;32mIce Copy constructor called\e[0m" << std::endl;
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


#endif
