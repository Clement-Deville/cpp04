/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeville <cdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 13:09:29 by cdeville          #+#    #+#             */
/*   Updated: 2024/12/12 11:27:45 by cdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
#define  CHARACTER_HPP

# include "ICharacter.hpp"

class Character : public ICharacter
{
	protected :
		std::string	_name;
		AMateria	*_slot[4];
		// AMateria	*_floor[4];
	public:
		Character();
		Character(const std::string name);
		Character(const Character &Cpy);
		virtual ~Character();

		Character &operator=(const Character &Cpy);
		virtual std::string const & getName() const;
		virtual void equip(AMateria* m);
		virtual void unequip(int idx);
		virtual void use(int idx, ICharacter& target);
};

#endif
