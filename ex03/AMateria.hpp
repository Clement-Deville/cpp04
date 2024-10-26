/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeville <cdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 18:31:38 by cdeville          #+#    #+#             */
/*   Updated: 2024/10/26 13:59:32 by cdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMateria_HPP
# define AMateria_HPP

# include <string>
# include <iostream>
# include <stdexcept>

# include "ICharacter.hpp"

class AMateria
{
protected:
	std::string _type;
public:
	AMateria();
	AMateria(std::string const & type);
	AMateria(const AMateria &Cpy);
	virtual ~AMateria();

	AMateria & operator=(const AMateria &Cpy);
	std::string const getType(void) const;
	virtual AMateria* clone() const = 0;
	virtual void use(ICharacter& target);
};

void AMateria::use(ICharacter& target)
{

}

#endif
