/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeville <cdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 18:31:38 by cdeville          #+#    #+#             */
/*   Updated: 2024/10/24 18:46:56 by cdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "A_Animal.hpp"

class Cat : public A_Animal
{
public:
	Cat();
	Cat(const Cat &Cpy);
	~Cat();

	Cat & operator=(const Cat &Cpy);
	virtual void makeSound(void) const;
};

#endif
