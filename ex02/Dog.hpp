/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeville <cdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 18:31:38 by cdeville          #+#    #+#             */
/*   Updated: 2024/10/24 18:46:56 by cdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "A_Animal.hpp"

class Dog : public A_Animal
{
public:
	Dog();
	Dog(const Dog &Cpy);
	virtual ~Dog();

	Dog & operator=(const Dog &Cpy);
	virtual void makeSound(void) const;
};

#endif
