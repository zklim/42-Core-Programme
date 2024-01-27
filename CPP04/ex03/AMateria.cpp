/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhlim <zhlim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 13:51:34 by zhlim             #+#    #+#             */
/*   Updated: 2023/10/31 14:12:10 by zhlim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria(std::string const & type) {
	this->type = type;
	std::cout << "Created a Materia of " << this->type << GREY << " Constructor" << RESET << std::endl;
}

AMateria::~AMateria() {
	std::cout << "Destroyed a Materia of " << this->type << GREY << " Destructor" << RESET << std::endl;
}

std::string const	&AMateria::getType() const {
	return this->type;
}

void				AMateria::use(ICharacter& target) {
	std::cout << "use " << this->type << "on " << target.getName() << std::endl;
}