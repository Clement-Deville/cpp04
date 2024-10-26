/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   A_Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeville <cdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 18:31:38 by cdeville          #+#    #+#             */
/*   Updated: 2024/10/26 13:59:32 by cdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef A_Animal_HPP
# define A_Animal_HPP

# include <string>
# include <iostream>
# include <stdexcept>
# include "Brain.hpp"

class A_Animal
{
protected:
	std::string type;
	Brain *_brain;
public:
	A_Animal();
	A_Animal(const A_Animal &Cpy);
	virtual ~A_Animal();

	A_Animal & operator=(const A_Animal &Cpy);
	virtual void makeSound(void) const = 0;
	std::string getType(void) const;
	Brain	&getBrain(void) const;
};

#endif
