/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhlim <zhlim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 14:55:46 by zhlim             #+#    #+#             */
/*   Updated: 2023/11/01 00:48:11 by zhlim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include "IMateriaSource.hpp"

class MateriaSource: public IMateriaSource {
	
	private:
		AMateria	*slots[4];
		int			i;

	public:
		MateriaSource();
		~MateriaSource();
		
		AMateria	**getSlots();
		void		learnMateria(AMateria*);
		AMateria*	createMateria(std::string const & type);
};