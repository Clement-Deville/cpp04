/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeville <cdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 18:31:38 by cdeville          #+#    #+#             */
/*   Updated: 2024/12/13 19:22:06 by cdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <string>
# include <iostream>
# include <stdexcept>
# include "Brain.hpp"

class Animal
{
protected:
	std::string type;
public:
	Animal();
	Animal(const Animal &Cpy);
	virtual ~Animal();

	Animal & operator=(const Animal &Cpy);
	virtual void makeSound(void) const;
	std::string getType(void) const;
};

#endif
