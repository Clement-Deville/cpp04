/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeville <cdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 15:00:28 by cdeville          #+#    #+#             */
/*   Updated: 2024/12/10 14:38:21 by cdeville         ###   ########.fr       */
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
	void		setIdea(const std::string newIdea);
	std::string	getIdea(const unsigned short index) const;
};

#endif
