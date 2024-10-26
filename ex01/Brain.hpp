/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeville <cdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 15:00:28 by cdeville          #+#    #+#             */
/*   Updated: 2024/10/26 13:53:29 by cdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <string>
# include <iostream>

class Brain
{
private:
	std::string 	_ideas[100];
	unsigned short	_count;
public:
	Brain();
	Brain(const Brain &Cpy);
	virtual ~Brain();

	Brain 		&operator=(const Brain &Cpy);
	void		setIdea(std::string newIdea);
	std::string	getIdea(unsigned short index) const;
};

#endif
