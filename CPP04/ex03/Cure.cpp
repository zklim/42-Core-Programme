/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhlim <zhlim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 14:09:46 by zhlim             #+#    #+#             */
/*   Updated: 2023/10/31 14:12:47 by zhlim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure(): AMateria("cure") {}

Cure::~Cure() {}

AMateria*	Cure::clone() const {
	return new Cure();
}

void 		Cure::use(ICharacter& target) {
	std::cout << "* heals "<< target.getName() << "’s wounds *" << std::endl;
}