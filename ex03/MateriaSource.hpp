/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeville <cdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 15:57:16 by cdeville          #+#    #+#             */
/*   Updated: 2024/10/28 15:58:39 by cdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
	protected:
		AMateria *_list[4];
	public:
		MateriaSource();
		MateriaSource(const MateriaSource &Cpy);
		virtual ~MateriaSource();

		MateriaSource & operator=(const MateriaSource &Cpy);
		virtual void learnMateria(AMateria* ptr);
		virtual void forgetMateria(int index);
		virtual AMateria* createMateria(std::string const & type);
};

#endif
