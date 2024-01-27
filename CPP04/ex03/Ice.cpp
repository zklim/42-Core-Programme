/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhlim <zhlim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 14:01:28 by zhlim             #+#    #+#             */
/*   Updated: 2023/11/01 00:07:51 by zhlim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice(): AMateria("ice") {}

Ice::~Ice() {}

AMateria*	Ice::clone() const {
	return new Ice();
}

void 		Ice::use(ICharacter& target) {
	std::cout << "* shoots an ice bolt at "<< target.getName() << " *" << std::endl;
}