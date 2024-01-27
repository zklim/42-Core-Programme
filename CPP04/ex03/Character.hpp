/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhlim <zhlim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 14:15:07 by zhlim             #+#    #+#             */
/*   Updated: 2023/11/01 00:19:27 by zhlim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include "ICharacter.hpp"

class Character: public ICharacter {
	
	private:
		std::string	name;
		AMateria	*slot[4];

	public:
		Character(std::string const name);
		Character(Character const &rhs);
		~Character();
		
		std::string const	&getName() const;
		AMateria			*getSlot(int i) const;
		AMateria			**getSlot();
		void 				equip(AMateria* m);
		void 				unequip(int idx);
		void 				use(int idx, ICharacter& target);
		Character			&operator=(Character const &rhs);
};