/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhlim <zhlim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 14:13:23 by zhlim             #+#    #+#             */
/*   Updated: 2023/11/01 00:45:52 by zhlim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(std::string const name) {
	this->name = name;
	std::cout << "Brave " << this->name << " has borned!" << GREY " Constructor" RESET << std::endl;
}

Character::Character(Character const &rhs) {
	if (this != &rhs) {
		for (int i = 0; i < 4; i++)
			if (this->slot[i])
				delete slot[i];
		for (int i = 0; i < 4; i++)
			if (rhs.slot[i])
				this->slot[i] = rhs.slot[i]->clone();
		this->name = rhs.name;
	}
}

Character::~Character() {
	for (int i = 0; i < 4; i++)
		if (this->slot[i]) 
			delete slot[i];
	std::cout << this->name << " has finished his mission" << GREY " Destructor" RESET << std::endl;
}

std::string const	&Character::getName() const {
	return this->name;
}

AMateria			*Character::getSlot(int i) const {
	return this->slot[i];
}

AMateria			**Character::getSlot() {
	return this->slot;
}

void 				Character::equip(AMateria* m) {
	for (int i = 0; i < 4; i++) {
		if (!this->slot[i]) {
			this->slot[i] = m;
			std::cout << this->getName() << " equiped " << i << " with " << this->slot[i]->getType() << std::endl;
			return ;
		}
	}
	std::cout << "Slots full!" << std::endl;
}

void 				Character::unequip(int idx) {
	for (int i = 0; i < 4; i++) {
		if (i == idx) {
			std::cout << this->getName() << " unequip " << i << " with " << this->slot[i]->getType() << std::endl;
			this->slot[i] = NULL;
			return ;
		}
	}
	std::cout << "Nothing to unequip" << std::endl;
}

void 				Character::use(int idx, ICharacter& target) {
	for (int i = 0; i < 4; i++) {
		if (i == idx && this->slot[i]) {
			this->slot[i]->use(target);
			return ;
		}
	}
	std::cout << "Materia not found" << std::endl;
}

Character			&Character::operator=(Character const &rhs) {
	if (this != &rhs) {
		for (int i = 0; i < 4; i++)
			if (this->slot[i])
				delete slot[i];
		for (int i = 0; i < 4; i++) {
			if (rhs.slot[i])
				this->slot[i] = rhs.slot[i]->clone();
		}
		this->name = rhs.name;
	}
	return *this;
}