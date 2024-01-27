/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhlim <zhlim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 14:55:07 by zhlim             #+#    #+#             */
/*   Updated: 2023/11/01 00:53:13 by zhlim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource() {
	this->i = 0;
	std::cout << "New materia source found" << GREY " Constructor" RESET << std::endl;
}

MateriaSource::~MateriaSource() {
	for (int i = 0; i < 4; i++) {
		if (this->slots[i])
			delete this->slots[i];
	}
	std::cout << "Materia source has shut down" << GREY " Destructor" RESET << std::endl;
}

AMateria	**MateriaSource::getSlots() {
	return this->slots;
}

void		MateriaSource::learnMateria(AMateria* m) {
	if (this->i == 4)
		this->i = 0;
	this->slots[this->i] = m;
	std::cout << "Learnt new Materia " << this->slots[i]->getType() << " at slot " << this->i << std::endl;
	this->i++;
}

AMateria*	MateriaSource::createMateria(std::string const & type) {
	for (int i = 0; i < 4; i++) {
		if (this->slots[i] && this->slots[i]->getType() == type) {
			return this->slots[i]->clone();
		}	
	}
	return 0;
}